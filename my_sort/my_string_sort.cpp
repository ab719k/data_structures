#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
/* */
void printall(vector<string> V)
{
    for (auto i = 0; i < V.size(); ++i)
        cout << V[i] << " ";
    cout << endl;
}

bool compareString(string s1, string s2) 
{
    if (s1.compare(s2) < 0) {
        return true; 
    }
    return false ;
}

int main()
{
    vector<string> V;
    string word;

    while(cin >> word) {
        V.push_back(word);
    }

    cout << " The array before sorting" << endl << "\t";
    printall(V);
    sort(V.begin(), V.end(), compareString);
    cout << "\n The array after sorting" << endl << "\t";    
    printall(V);
    
    cout << "Exiting... " << endl;    


}