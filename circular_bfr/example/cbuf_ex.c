#include <cbuf.h>

static inline char get_input_char()
{
    char c;
    printf("Menu\n");
    printf("\ts: Reset\n");
    printf("\tr: Read\n");
    printf("\tw: Write (Write only if there is space)\n");
    printf("\tp: Push (overwrite stale values)\n");
    printf("\to: Output all values \n");
    printf("\tx: Exit\n");    
    printf("Enter your choice: ");
    scanf("%c", &c);
    getchar();
    return c;
}

void get_values(meas_t *src)
{
    printf("ts: ");
    scanf("%u", &src->ts);   
    printf("gas_resistance: "); 
    scanf("%f", &src->gas_resistance);
    printf("humidity: "); 
    scanf("%f", &src->humidity);
    printf("temperature: "); 
    scanf("%f", &src->pressure);
    printf("meas_id: "); 
    scanf("%d", &src->meas_id);
    printf("scan_mode: ");
    scanf("%d", &src->scan_mode);  
}

void print_values(meas_t *src)
{
    if(src == NULL){
        printf("Nothing to print");
        return;
    }
    printf("ts: %u", src->ts);   
    printf("gas_resistance: %f", src->gas_resistance);
    printf("humidity: %f", src->humidity);
    printf("temperature: %f", src->pressure);
    printf("meas_id: %d", src->meas_id);
    printf("scan_mode: %d", src->scan_mode);  
}

int main(int argc, char *argv[])
{
    // Create M:N thread, M writer, N reader.
    // Check how long does it take for them to fill the buffer
    cbuf_t *CBfr = cbuf_malloc(512);
    meas_t *MVal = malloc(sizeof(meas_t));
     meas_t *outMVal;
    cbuf_reset(CBfr);
    char in=0;
    while(in != 'x'){
        in=get_input_char();
        switch(in) 
        {
            case 's':
                cbuf_reset(CBfr);
               break; 
            case 'r':
                outMVal = cbuf_get(CBfr);
                if(outMVal != NULL)
                    print_values(outMVal);
                else 
                printf("Buffer is empty\n");
            case 'w':
                printf("Write values\n");
                get_values(MVal);
                cbuf_put(CBfr,MVal);
                break;
            case 'p':
                printf("Overwrite values\n");
                get_values(MVal);
                cbuf_push(CBfr,MVal);
                break;
            case 'o':
                printf("Print current buffer values\n");
                cbuf_output(CBfr);
                break;
            case 'x':
                printf("Bye\n");
                break;
            default:
                printf("%c", in);
                break;
        }
        printf("\n");
    }
    cbuf_free(CBfr);

    return EXIT_SUCCESS; 
}
