/*
Given an unsorted array A of size N that contains only non-negative integers, find a continuous sub-array which adds to a given number S.
In case of multiple subarrays, return the subarray which comes first on moving from left to right.

Example 1:
Input:
N = 5, S = 12
A[] = {1,2,3,7,5}
Output: 2 4
Explanation: The sum of elements from 2nd position to 4th position is 12.



*/

#include <stdio.h>


void subarraySum(int arr[], int n, long long s, int *v)
{
    long long sum_so_far=arr[0];
    int b=0,e=0;
    if(v == NULL) {
        return;
    }

    for(int i=1; i<n; ) {
        if (sum_so_far+arr[i] > s) {
            // we need to remove the beginning till sum is less than s
            sum_so_far-=arr[b++];
        } else if (sum_so_far+arr[i] == s) {
            // Found the subarray
            v[0]=b; v[1]=e;
            break;
        } else {
            // continue adding to the sum.
            sum_so_far += arr[i];
            e=i;
            i++;
        }
    }
}

int main(int argc, char*argv[])
{
    int v[2];
    int A[] = {1,2,3,7,5};

    subarraySum(A, sizeof(A)/sizeof(int), 12, v); 

    return EXIT_SUCCESS;
}