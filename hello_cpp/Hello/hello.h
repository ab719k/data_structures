#include <vector>
#include <string>
#include <iostream>

using namespace std;
class Hello {
private:    
    vector<string> g1;
    int count;
public:    
    Hello(vector<string> name);
    Hello(string first);
    Hello(int first); // Function Overloading
    void operator =(vector<string> source); // Operator Overloading
    void operator +(string name);
    void operator +=(string name); // Operator Overloading
    void printall();
};