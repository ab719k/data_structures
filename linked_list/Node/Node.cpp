#include <vector>
#include <string>
#include "Node.h"
#include <algorithm>

Node::Node(vector<string> V) 
{
    if(this->L.size() > 0) {
        L.clear();
        L.shrink_to_fit();
        cout << "Capacity:" << L.capacity() << " Size:" << L.size() << endl;
    }
    this->L=V;
}

void Node::operator =(vector<string> V) 
{
    if(this->L.size() > 0) {
        L.clear();
        L.shrink_to_fit();
        cout << "Capacity:" << L.capacity() << " Size:" << L.size() << endl;
    }
    this->L=V;
}


Node::Node(string name) 
{
    if(this->L.size() > 0) {
        L.clear();
        L.shrink_to_fit();
        cout << "Capacity:" << L.capacity() << " Size:" << L.size() << endl;
    }
    if (std::find(L.begin(), L.end(), name) != L.end())
    {
        cout<< "Name " << name << " Exist";
        // TBD Create a hashmap to increment count in subsequent release
    } else {
        L.push_back(name);
    }
}


Node Node::operator +(string name) 
{
    if (std::find(L.begin(), L.end(), name) != L.end())
    {
        cerr<< "Name " << name << " already exist";
    } else {
        L.push_back(name);
    }
    return L;
}

Node Node::operator +=(string name) 
{
    //L=
     this.push_back(name);
     return 
}

void Node::printall()
{
    cout << "The count is " << this->count << endl;
    cout << "Output: ";
    for(int i = 0; i < this->count; i++) 
    {
        cout << i << ' ';
    }
    cout << endl;
}
