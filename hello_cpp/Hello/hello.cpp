#include "hello.h"

Hello::Hello(vector<string> name) 
{
    this->g1 = name;
    this->count = g1.size();
}

Hello::Hello(string first) 
{
    this->g1.push_back(first);
    this->count = g1.size();
}

Hello::Hello(int first) 
{
    string first_2_string = to_string(first)
    this->g1.push_back(first_2_string);
    this->count = g1.size();
}


// Operator overloading example
void Hello::operator =(vector<string> source) 
{
    this->g1 = source;
    this->count = g1.size();
}

void Hello::operator +(string name) 
{
    this->g1.push_back(name);
    this->count++;
}

void Hello::operator +=(string name) 
{
    this->g1.push_back(name);
    this->count++;
}

void Hello::printall()
{
    cout << "The count is " << this->count << endl;
    cout << "Output: ";
    for(int i = 0; i < g1.size(); i++) 
    {
        cout << g1[i] << ' ';
    }
    cout << endl;
}
