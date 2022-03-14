#include<fstream>
#include "hello.h"

using namespace std;

int main()
{
    //fstream infile;
    string word;
    //infile.open(stdin);
    //istream& infile;
    Hello H("First");
    while(cin >> word)
    {
        cout << "Entered " << word << endl;
        H + word;
    }    
    //infile.close();

    H.printall();

}
