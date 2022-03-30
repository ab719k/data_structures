#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 3) {
        cout << "Usage " << argv[0] << " s1 s2" << endl;
        return EXIT_SUCCESS;
    }
    string s1 = argv[1];
    string s2 = argv[2];

    cout << " The comparison of " << s1 << " and " << s2 << " is " << s1.compare(s2) << endl;
    
    return EXIT_SUCCESS;

}

