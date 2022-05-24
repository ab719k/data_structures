#include "trie.h"

Trie::Trie(vector<string> name) 
{
    this->g1 = name;
    this->count = g1.size();
}

Trie::Trie(string first) 
{
    this->g1.push_back(first);
    this->count = g1.size();
}

Trie::Trie(int first) 
{
    string first_2_string = to_string(first);
    this->g1.push_back(first_2_string);
    this->count = g1.size();
}


// Operator overloading example
void Trie::operator =(vector<string> source) 
{
    this->g1 = source;
    this->count = g1.size();
}

void Trie::operator +(string name) 
{
    this->g1.push_back(name);
    this->count++;
}

void Trie::operator +=(string name) 
{
    this->g1.push_back(name);
    this->count++;
}

void Trie::printall()
{
    cout << "The count is " << this->count << endl;
    cout << "Output: ";
    for(int i = 0; i < g1.size(); i++) 
    {
        cout << g1[i] << ' ';
    }
    cout << endl;
}

bool Trie::find(string val)
{
    cout << "TBD: " << endl;
 
    return false;
}
