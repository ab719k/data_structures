/* Given an array of distinct integers. 
   The task is to count all the triplets such that sum of two elements equals the third element. */
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <set>
#include <vector>
#include <iterator>
#include <time.h>
#include <unordered_set>
#include <iostream>

#define MAX_BUFFER 4096

using namespace std;

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

#if 0
void countTriplet(int arr[], int n)
{
    // Your code goes here
    for(int i=0;i< n;i++) {
        printf("%d", arr[i]);
    }
}
#endif

void countTripletinS(unordered_set<int> *S)
{
    unordered_set<int>::iterator itr;
    itr=S->begin();
    while(itr != S->end()) {
        printf("%d", *itr);
    }
}

void calculate_average(unordered_set<int> S);


void calculate_average(unordered_set<int> S)
{
    int sum=0;
    for(int values : S)    
    {
        printf("%d %d\n", sum , values);
        sum+=values;
     }
     printf("Average = %3.2f\n", float(sum)/S.size());
     return;
}

int main(int argc, char *argv[])
{
    int n=0;
    int A[MAX_BUFFER];
    
    unordered_set<int> us;
    set<int> S;
    int in;
    int sum = 10;

    if(argc == 2) {
        sum = atoi(argv[1]);
    } else {
        cin >> sum;
    }

    while(cin >> in)  
    {
        S.insert(in);
        us.insert(in);
    }

    set<int>::iterator itrS;

    cout << "Print Set:" << endl;
    for(itrS = S.begin(); itrS != S.end() ; ++itrS)  {
        cout << *itrS << " ";
    }
    cout << endl;

    cout << "List Reverse: ";
    for(itrS = S.end(), --itrS; itrS != S.begin() ; itrS--)  {
        cout << *itrS << " ";
    }
    cout << endl;

    set<int>::iterator l,r;
    l = S.begin();
    r = S.end();



    //calculate_average(us);
//    countTriplet(A,n);
//    countTripletinS(&S);

    return EXIT_SUCCESS;
}