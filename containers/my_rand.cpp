/* rand example: guess the number */
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iostream>
#include <fstream>

using namespace std;

int main (int argc, char *argv[])
{
    int iSecret, iGuess;
    ofstream myfile;
    myfile.open("input_100.txt");

    /* initialize random seed: */
    srand (time(NULL));

    /* generate secret number between 1 and 10: */
    
    for(long i=0; i<99999; i++) {
        myfile << rand() % 100000 + 1 << " ";
    }
    myfile << endl;
    
    return 0;
}