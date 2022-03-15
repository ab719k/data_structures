#include <vector>
#include <string>
#include <iostream>

using namespace std;
class Node {
private:    
    vector<int> g1;
    int count;
public:    
    Hello(vector<string> name);
    Hello(string first);
    void operator =(vector<string> source);
    void operator +(string name);
    void operator +=(string name);
    void printall();
};