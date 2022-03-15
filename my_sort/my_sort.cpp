#include <iostream>
#include <algorithm>
#include <vector>


void show(int A[], int array_size)
{
    for (int i = 0; i < array_size; ++i)
        cout << A[i] << " ";
}

/**/
void printall()
{

}

using namespace std;

int main()
{
    vector<int> V;
    int A[] = { 1, 5, 8, 9, 6, 7, 3, 4, 2, 0 };
    int n = sizeof(A)/sizeof(A[0]);
    cout << "The size of array is " << sizeof(A)/sizeof(A[0]) << endl;


    cout << " The array before sorting" << endl;
    show(A, n);
    cout << " Sorting " << endl;
    sort(A, A+n)



}