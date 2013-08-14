//
//  cach.h
//  datastructure
//
//  Created by aaron on 13-8-13.
//  Copyright (c) 2013年 aaron. All rights reserved.
//

#ifndef datastructure_cach_h
#define datastructure_cach_h

typedef char *CACHE_request_handler(char *request);
typedef CACHE_request_handler *CACHE_request_handler_P;

void CACHE_SERVER_run(CACHE_request_handler_P request_handler);

#endif
