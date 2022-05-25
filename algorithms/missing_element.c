/* Given an array of size N-1 such that it only contains distinct integers in the range of 1 to N. Find the missing element. */
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int log_print = 0;

/* getMissingNo takes array and size of array as arguments*/
int getMissingNo(int a[], int n)
{
    int i=0, total;
    total = 1;
    for (i = 2; i <=n; i++) {
        total += i;
        total -= a[i-2];
        if(log_print) printf("%02d: total(%2d), a[%d]=(%d)\n",i,total,i-2,a[i-2]);       
    }
    return total;
}


int main(int argc, char * argv[])
{
    //int N = 5;
    //int A[] = {1,2,3,5};
    int N = 10;
    int A[] = {6,1,2,8,3,4,9,10,5,11};
    printf("The missing number is %d\n", getMissingNo(A, N));
    
}