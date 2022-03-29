#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Node {
    private:    
        vector<string> L;
    public:    
        Node(vector<string> name);
        Node(string first);
        void operator =(vector<string> source);
        void operator +(string name);
        void operator +=(string name);
        void printall();
};