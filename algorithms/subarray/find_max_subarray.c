/* subarray maximum sum */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MAX_BUFFER 1024

int findMax(int arr[], int n)
{
    int sum_so_far;
    for(int i=0; i<n; i++) {
        
    }

}

int main(int argc, char*argv[])
{
    int A[MAX_BUFFER];
    int n=0;
    while(scanf("%d", &A[n])!=EOF) {
        n++;
        if(n==MAX_BUFFER) {
            printf("Max Buffer exceeded");
            return EXIT_FAILURE;
        }
    }

    printf("%d", findMax(A, i));
    return EXIT_SUCCESS;
}