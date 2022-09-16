#include <vector>
#include <string>
#include <iostream>

using namespace std;
class Trie {
private:    
    vector<string> g1;
    int count;
public:  
    Trie();  
    Trie(vector<string> name);
    Trie(string first);
    Trie(int first); // Function Overloading
    void operator =(vector<string> source); // Operator Overloading
    void operator +(string name);
    //void operator +=(string name); // Operator Overloading
    Trie& operator +=(string name);
    void printall();
    bool find(string val); // find if the value is present in trie

};