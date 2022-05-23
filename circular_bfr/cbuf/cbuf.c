#include "cbuf.h"

cbuf_t* cbuf_malloc(size_t buffer_sz)
{
    if(buffer_sz > MAX_BUFFER) {
        printf("Current buffer size is limited to %d", MAX_BUFFER);
    }

    cbuf_t *C = malloc(sizeof(cbuf_t));
    if (!C) {
        fprintf(stderr, RED "[ERROR]"
               NC  ": Cbuf Not enough memory");            
    }
    C->reader=0;
    C->writer=0;
    return C;
}

meas_t *cbuf_get(cbuf_t *C)
{
    meas_t *ret;
    if(C->buffer_sz){
        C->buffer_sz--;
        ret = &(C->M[C->reader]);
        C->reader = (C->reader+1)%MAX_BUFFER;
    }
}

static inline void copy_meas_values(meas_t *dst, meas_t *src) 
{
    dst->gas_resistance = src->gas_resistance;
    dst->humidity = src->humidity;
    dst->temperature = src->pressure;
    dst->ts= src->ts;
    dst->meas_id = src->meas_id;
    dst->scan_mode = src->scan_mode;
}



int cbuf_put(cbuf_t *C, meas_t *src)
{
    int i=C->writer;
    meas_t *dst = &C->M[i];
    if(C->buffer_sz < MAX_BUFFER) {
        if(C->writer != C->reader) {
            copy_meas_values(dst, src);
            C->writer=(C->writer+1) % MAX_BUFFER;
            return EXIT_SUCCESS;
        }
    }
    printf("Memory full, measurement discared");
    return EXIT_FAILURE;

}

int cbuf_push(cbuf_t *C, meas_t *src)
{
    int i=C->writer;
    meas_t *dst = &C->M[i];
    if(C->buffer_sz < MAX_BUFFER) {
        copy_meas_values(dst, src);
        if(C->writer == C->reader) {
            printf("Memory full, measurement overwritten, move reader");
            C->reader = (C->reader+1)%MAX_BUFFER;
        }
        C->writer=(C->writer+1) % MAX_BUFFER;
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;

}

void cbuf_reset(cbuf_t *C)
{
    C->reader=0;
    C->writer=0;
}

void cbuf_free(cbuf_t *C)
{
    free(C);
}