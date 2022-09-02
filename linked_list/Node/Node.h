#include <vector>
#include <string>
#include <iostream>

using namespace std;


class Node {
    private:    
        vector<string> L;
        int count=0;

    public:    
        Node(vector<string> name);
        Node(string first);

        void operator =(vector<string> source);
        
        Node operator +(string name);
        Node operator +(Node second);
        
        Node operator +=(string name);
        Node operator +=(Node second);

        bool exists(string name);
        bool update(string name1, string name2);
        bool remove_if_exists(string name);
        void remove(string name);

        void printall();
};