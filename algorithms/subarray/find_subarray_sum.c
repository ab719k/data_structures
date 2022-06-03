/* subarray maximum sum */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int log_print = 0;

void subarraySum(int arr[], int n, long long s, int *v)
{
    long long sum_so_far=arr[0];
    int b=0,e=0;
    if(v == NULL) {
        return;
    }

    for(int i=1; i<n; ) {
        if(log_print) printf("i(%d), sum(%llu), b(%d), e(%d)\n", i, sum_so_far, b, e );
        if (sum_so_far+arr[i] > s) {
            // we need to remove the beginning till sum is less than s
            sum_so_far-=arr[b++];
        } else if (sum_so_far+arr[i] == s) {
            // Found the subarray
            sum_so_far+=arr[i];
            v[0]=b; v[1]=++e;
            if(log_print) printf("Success: i(%d), sum(%llu), b(%d), e(%d)\n", i, sum_so_far, b, e );
            return;
        } else {
            // continue adding to the sum.
            sum_so_far += arr[i];
            e=i;
            i++;
        }
    }
    v[0]=v[1]=n+1;
}

int main(int argc, char*argv[])
{
    int v[2] = {0,0};
    int A[] = {19,2,3,6,5,2,3,7,9};
    int n = sizeof(A)/sizeof(int);
    subarraySum(A, n, 9, v);

    if(v[0] >= n) {
        printf("Sum Not present\n");
    } else {
        printf("The return values are %d and %d\n", v[0]+1, v[1]+1);
        for(int i=v[0];i<v[1]+1;i++) {
            printf("%d ", A[i]);
        }
        printf("\n");
    }
    return EXIT_SUCCESS;
}