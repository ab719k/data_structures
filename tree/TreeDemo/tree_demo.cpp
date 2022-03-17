#include <fstream>
#include "tree.h"

using namespace std;

static inline void display_menu()
{
    cout << "Menu" << endl; 
    cout << "i: Insert Name" << endl;
    cout << "p: Print Tree" << endl;
    cout << "f: Find a Name" << endl;
    cout << "x: Exit" << endl;
    cout << "Enter your choice: ";
}

#include <sstream>
#include <string>


static inline void load_state(string filename, Tree *T)
{
    ifstream input(filename);
    for(string line; getline( input, line ); )
    {
        cout << line << " ";
        T->insert(line);
    }
    cout <<endl;
    T->print();
}

int main(int argc, char *argv[])
{
    string name;
    Tree T;
    
    cout << "You have entered " << argc << " arguments:" << "\n";
    for (int i = 0; i < argc; ++i)
        cout << argv[i] << "\n";

    if (argc > 1) {
        load_state(argv[1], &T);
    }

    char choice = 'a';
    while((choice != 'x') || (choice != EOF)) {
        display_menu();
        cin >> choice;
        switch(choice) 
        {
            case 'i':
                cout << "Enter word: ";
                cin >> name;
                cout << " You entered " << name << endl;
                T.insert(name);
                break;
            case 'p':
                cout << "The current tree is : " << endl;
                T.print();
                break;
            case 'f':
                cout << "Enter name to be found : ";
                cin >> name;
                cout << "The element with name = '" << name << "' is " ;
                if (!(T.find(name))) {
                    cout << "not ";
                }
                cout << "present in the tree." << endl;
                break;    
            case 'x':
                return EXIT_SUCCESS;
                break;
            default:
                cout << "Unhandled choice : (" << choice << ")" << endl;
        }
    }
}
