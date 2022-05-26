#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <iterator>


using namespace std;


/*
Few details about set in c++
    The set stores the elements in sorted order.
    All the elements in a set have unique values.
    The value of the element cannot be modified once it is added to the set, though it is possible to remove and then add the modified value of that element. Thus, the values are immutable.
    Sets follow the Binary search tree implementation.
    The values in a set are unindexed.

*/
int main(int argc, char *argv[])
{

    cout << "Hello " << argv[0] << endl;
    set<int, greater<int>> S;                           // empty set of ints
    set<int> val = {6, 10, 5, 1}; // defining a set with values
    int in;
    while(cin >> in) 
    {
        S.insert(in);
    }
    set<int , greater<int>>::iterator itr;
    cout << "\nThe set S is : \n";
    for(itr=S.begin(); itr != S.end(); itr++)
    {
        cout << *itr << " ";
    }
    cout << endl;


}