
#ifndef __CBUF__H
#define __CBUF__H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#define RED "\e[0;31m"
#define NC "\e[0m"



typedef struct cbuf_s cbuf_t;
typedef struct meas_s meas_t;

struct meas_s {
    int ts;
    int meas_id;
    int temperature;
    int humidity;
    int pressure;
    int gas_resistance;
    int scan_mode;    
};

#define MAX_BUFFER 1024

struct cbuf_s {
    int reader;
    int writer;
    int buffer_sz;
    meas_t M[MAX_BUFFER];
};

/* API for circular buffer */
cbuf_t* cbuf_malloc(size_t buffer_sz); 
meas_t *cbuf_get(cbuf_t *C );
int cbuf_put(cbuf_t *C, meas_t *val);
int cbuf_push(cbuf_t *C, meas_t *val);
void cbuf_reset(cbuf_t *C);
void cbuf_free(cbuf_t *C);


#endif
