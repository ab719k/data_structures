/* Given an array of distinct integers. The task is to count all the triplets such that sum of two elements equals the third element. */


#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 4096

void print_array(int A[],int n)
{
  for (int i = 0; i <n; i++) {   
      printf("%d", A[i]);
      if(i%32 == 0) {
          printf("\n");
      }
  }
  printf("\n");
}

int countTriplet(int arr[], int n)
{
    // Your code goes here
}


int main(int argc, char *argv[])
{
    int n=0;
    int A[MAX_BUFFER];

    if (argc > 1) {
        for(int i=1; i < argc; i++)
            A[n++] = atoi(argv[i]);        
        print_array(A,n);
    }
    while(scanf("%d", &A[n++]) != EOF){
        printf("%d ", A[n-1]);
        if(n%32 == 0) {
          printf("\n");
        }        
    }
    printf("\n");
    countTriplet(A,n);

    return EXIT_SUCCESS;
}