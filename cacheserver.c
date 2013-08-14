//
//  cacheserver.c
//  datastructure
//
//  Created by aaron on 13-8-13.
//  Copyright (c) 2013年 aaron. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/errno.h>
#include "cachp.h"
#include "hstb.h"
#include "cda.h"

static void CACHE_SERVER_dispatch(int,CACHE_request_handler_P);
static char *OPER_request_handler(char *);
static COMMAND_p_t CACHE_command_interpret(const char *);
static void *CACHE_command_exec(const char *,const char *, const char *);
static void CACHE_free(CDA_UINT16_t index,void *);

static HASH_TABLE_ID_t cache_hash;
static void error(char *msg){
    perror(msg);
    exit(1);
}

void CACHE_SERVER_close(){
    H_destroy(cache_hash, CACHE_free);
}

void CACHE_SERVER_run(){
    cache_hash = H_create(10);
    
    int socketfd,new_socketfd,clilen;
    unsigned short port = 56666;
    
    struct sockaddr_in serv_addr,cli_addr;
    
    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd<0) {
        error("Error opening socket");
    }
    
    bzero((char*)&serv_addr, sizeof(serv_addr));
    bzero((char*)&cli_addr, sizeof(cli_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    
    if(bind(socketfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr))<0){
        error("binding to server error!");
    }
    
    printf("server is listening to %d\n",port);
    listen(socketfd, 5);
    
    clilen = sizeof(cli_addr);
    //pid_t pid;
    while (1) {
        new_socketfd = accept(socketfd, (struct sockaddr *)&cli_addr, (socklen_t *)&clilen);
        if(new_socketfd<0){
            if (errno==EINTR) {
                continue;
            }
            error("Error on accept");
        }
        
        CACHE_SERVER_dispatch(new_socketfd,OPER_request_handler);
        
//        if ((pid=fork())==0) {
//            close(socketfd);
//            CACHE_SERVER_dispatch(new_socketfd,OPER_request_handler);
//            exit(0);
//
//        }else if(pid<0){
//            error("Error on fork");
//        }
//        else{ close(new_socketfd);}
    }
    close(socketfd);
    CACHE_SERVER_close();
}


static void CACHE_free(CDA_UINT16_t index,void *data){
    printf("freeing data : %s",(char *)data);
    
    CDA_free(data);
}

static void CACHE_SERVER_dispatch(int sock,CACHE_request_handler_P request_hander){
    char buffer[256];
    
    bzero(buffer, 256);
    long n = read(sock,buffer,255);
    printf("accept msg %s\n",buffer);
    
    char *result = request_hander(buffer);
    if(n<0) error("Error reading from socket");
    
    strcpy(buffer, result);
    n = write(sock, buffer, strlen(buffer));
    
    if(n<0) error("Error on writing to socket");

}
static char *OPER_request_handler(char *request){
    COMMAND_p_t command = CACHE_command_interpret(request);
    
    char *oper = *command->arguments;
    char *key = *(command->arguments+1);
    char *value = *(command->arguments+2);
    
    CDA_free(command);
    
    return (char *)CACHE_command_exec(oper,key,value);
}

static COMMAND_p_t CACHE_command_interpret(const char *command){
    COMMAND_p_t p_command = CDA_NEW(COMMAND_t);
    
    if(*command!='*')
        return NULL;
    command++;
    
    char *arg = CDA_NEW(char);
    CDA_UINT16_t arg_count=0;
    //CDA_UINT16_t arg_len=0;
    CDA_BOOL_t is_len=CDA_FALSE;
    CDA_BOOL_t is_new=CDA_TRUE;
    unsigned short index = 0;
    while (*command!='\0') {
        if(*command=='\r' && *(command+1)=='\n'){
            //if the argument length is 0 ,the arg is the argument length
            //else the arg is the argument
            if(arg_count==0){
                arg_count = atoi(arg);
                p_command->arguments = CDA_malloc(sizeof(char *)*arg_count);
                p_command->size = arg_count;
            }else if(is_len){
                //arg = CDA_NEW(char);
                is_len = CDA_FALSE;
                is_new=CDA_TRUE;
            }else{
                char *cp_arg=CDA_NEW(char);
                memcpy(cp_arg, arg, strlen(arg));
                p_command->arguments[index]=cp_arg;
                ++index;
                //++p_command->arguments;
                //arg=CDA_NEW(char);
                is_new=CDA_TRUE;
            }
            command+=2;
            
            continue;
        }
        //the next argument is length of next argument
        if(*command=='$'){
            is_len = CDA_TRUE;
            is_new=CDA_TRUE;
            ++command;
            continue;
        }
        //if the arg is to record new argument
        if(is_new){
            memset(arg, '\0',strlen(arg));
            *arg=*command;
            is_new=CDA_FALSE;
        }else{
            strncat(arg, command, 1);
        }

        ++command;
    }
    
    CDA_free(arg);
    
    return p_command;
    
}

static void *CACHE_command_exec(const char *oper,const char *key, const char *value){
    if (strcasecmp(oper, "GET")==0) {
        return H_get(key, cache_hash);
    }else if(strcasecmp(key, "SET")){
        char *data=CDA_NEW(char);
        strcpy(data, value);
        H_set(key, data, cache_hash);
        
        return "1";
    }
    return "0";
    
}




