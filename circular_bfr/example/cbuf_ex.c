#include <cbuf.h>


int main(int argc, char *argv)
{
    printf("Hello circular buffer");
    // Create M:N thread, M writer, N reader.
    // Check how long does it take for them to fill the buffer
    cbuf_t *C = cbuf_malloc(512);

    cbuf_reset(C);
    meas_t *val = cbuf_get(C);
    cbuf_free(C);

    return EXIT_SUCCESS; 
}
