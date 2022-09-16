#include <fstream>
#include <sstream>
#include <string>
#include "bst.h"

using namespace std;

static inline void display_menu()
{
    cout << "Menu" << endl; 
    cout << "i: Insert Number" << endl;
    cout << "d: Delete Number" << endl;
    cout << "p: Print BST" << endl;
    cout << "s: Search Number" << endl;
    cout << "b: balance tree" << endl;
    cout << "x: Exit" << endl;
    cout << "Enter your choice: ";
}



int main(int argc, char *argv[])
{
    //string number;
    BST T;
    char choice = 'a';
    int number;
    int x;

#if DBG_PRINT_NOT_YET    
    cout << "You have entered " << argc << " arguments:" << "\n";
    for (int i = 0; i < argc; ++i)
        cout << argv[i] << "\n";
    string filenumber=argv[1];

    ifstream input_file(filenumber);
    if (!input_file.is_open()) {
        cerr << "Could not open the file - '"
             << filenumber << "'" << endl;
        return EXIT_FAILURE;
    }
    while (input_file >> number) {
        cout << number << "; ";
        T.insert(number);
    }
    cout << endl;
    input_file.close();
#endif
    /*
    while (cin >> x) {
        T.insert(number);
    }
    cin >> choice;
    */
   
    while((choice != 'x') || (choice != EOF)) {
        display_menu();
        cin >> choice;
        switch(choice) 
        {
            case 'i':
                cout << "Enter number: ";
                cin >> number;
                cout << " You entered " << number << endl;
                T.insert(number);
                break;
            case 'd':
                cout << "Enter Number: ";
                cin >> number;
                cout << " You entered " << number << endl;
                T.remove(number);
                break;
            case 'p':
                cout << "The current tree is : " << endl;
                T.print();
                break;
            case 'f':
                cout << "Enter number to be found : ";
                cin >> number;
                cout << "The element with number = '" << number << "' is " ;
                if (!(T.find(number))) {
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
