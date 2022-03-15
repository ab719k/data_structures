#include<fstream>
#include "hello.h"

using namespace std;

int main()
{
    //fstream infile;
    string word;
    //infile.open(stdin);
    //istream& infile;
    Hello H1(10);
    Hello H2("First");
    while(cin >> word)
    {
        cout << "Entered " << word << endl;
        H1 + word;
    }    
    //infile.close();
    H1.printall();
    cout << "Print H2" << endl;
    H2.printall();

}
