#include "hello.h"

Node::Node(vector<string> name) 
{
    this->g1 = name;
    this->count = g1.size();
}

Node::Node(string first) 
{
    this->g1.push_back(first);
    this->count = g1.size();
}

Node::Node(int first) 
{
    this->g1.push_back(first);
    this->count = g1.size();
}


// Operator overloading example
void Node::operator =(vector<string> source) 
{
    this->g1 = source;
    this->count = g1.size();
}

void Node::operator +(string name) 
{
    this->g1.push_back(name);
    this->count++;
}

void Node::operator +=(string name) 
{
    this->g1.push_back(name);
    this->count++;
}

void Node::printall()
{
    cout << "The count is " << this->count << endl;
    cout << "Output: ";
    for(int i = 0; i < g1.size(); i++) 
    {
        cout << g1[i] << ' ';
    }
    cout << endl;
}
