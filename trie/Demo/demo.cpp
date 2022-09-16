#include<fstream>
#include "trie.h"

using namespace std;

int main()
{
    //fstream infile;
    string word;
    //infile.open(stdin);
    //istream& infile;
    Trie H1("Amit");
    //Trie H2("First");
    cout << "Enter word: ";    
    while(cin >> word)
    {
        cout << "Entered " << word << endl;
        H1 += word;
        cout << "The list so far" << endl;
        H1.printall();
        cout << "Enter another word: ";
    
    }

    //infile.close();
    H1.printall();
    
    //cout << "Print H2" << endl;
    //H2.printall();

}
