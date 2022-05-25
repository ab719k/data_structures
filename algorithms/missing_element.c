/* Given an array of size N-1 such that it only contains distinct integers in the range of 1 to N. Find the missing element. */
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

// SOLUTION

/* getMissingNo takes array and size of array as arguments*/
int getMissingNo(int a[], int n)
{
    int i, total;
    total = (n + 1) * (n + 2) / 2;
    for (i = 0; i < n; i++)
        total -= a[i];
    return total;
}


int main(int argc, char * argv[])
{
    //int N = 5;
    //int A[] = {1,2,3,5};
    int N = 10;
    int A[] = {6,1,2,8,3,4,9,10,5};

    int t=A[0];
    int m;

    // Move the extra to the end
    int i =0;

    int out_of_bound;
    while(i<N-2) {
        if(A[i]>=N) {
            out_of_bound=A[i];
            A[i]=A[N-1];
            A[N-1]=out_of_bound;            
        }

    }


    while(i<N-1) {
        printf("[%d,%d]: ", i,t);
        for (int j=0; j<N;j++) {    
            printf("%d ", A[j]);
        } 
        printf("\n");
        if(A[i]>=N) {
            //swap(A[N-1], A[i]);
            t=A[N-1];
            A[N-1]=A[i];
            A[i]=t;
        } 
        else if (A[i] == i) {
            i++;
        }
        else {
            //swap(A[i], A[A[i]]);
            if(A[A[i]] >= N) {
                t=A[A[i]-1];
                A[A[i]-1]=A[i];
                A[i]=t;
            } else {
                t=A[A[i]];
                A[A[i]]=A[i];
                A[i]=t;
            }
        }
        getchar();
    }
    for (int i=0; i<N;i++) {    
        if(A[i] != i) {
            printf("The missing # is %d\n", i);
        }
    } 
    
}