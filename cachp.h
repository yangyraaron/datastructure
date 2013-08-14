//
//  cachp.h
//  datastructure
//
//  Created by aaron on 13-8-13.
//  Copyright (c) 2013年 aaron. All rights reserved.
//

#ifndef datastructure_cachp_h
#define datastructure_cachp_h

#include "cach.h"
#include "cda.h"

typedef struct cache_command{
    char **arguments;
    CDA_UINT8_t size;
} COMMAND_t,*COMMAND_p_t;

#endif
