/* rand example: guess the number */
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <unistd.h>
 #include <getopt.h>

#include <iostream>
#include <fstream>
#include <string>
#include <climits>


//#include <GetOpt.h>

using namespace std;

int get_seed()
{
    int hour = std::atoi(__TIME__);
    int min = std::atoi(__TIME__ + 3);
    int sec = std::atoi(__TIME__ + 6);
    return 10000 * hour + 100 * min + sec;
}


//Make the class singleton at some point
class MainParam{
  private:
    bool initialized;
  public:  
    uint64_t low;
    uint64_t high;
    uint64_t random_seed;
    string filename; 
    
    MainParam()
    {
        initialized = true;
        low=0;
        high=UINT64_MAX;
        random_seed = get_seed();
    }
    ~MainParam() 
    {
        initialized = false;
    };
};
MainParam P;

static inline void print_help()
{
    cout << "Require some options to run \n";
    cout << "\t low     :   required_argument, \n";
    cout << "\t high    :   required_argument,\n";      
    cout << "\t MaxNbr  :   required_argument,\n";
    cout << "\t file    :   required_argument, \n";     
    cout << "\t debug   :   no_argument,\n";
    cout << "\t verbose :   no_argument,\n";
    cout << "\t separator :   optional_argument (default is newline)" << endl; 
}
static inline int local_process_opt(int argc, char **argv)
{
    if(argc == 1) {
        print_help();
        return EXIT_FAILURE;
    }  
    int c;
    int digit_optind = 0; 
    while (1) {
        int this_option_optind = optind ? optind : 1;
        int option_index = 0;
        static struct option long_options[] = {
            {"low",     required_argument, 0,  'l' },
            {"high",    required_argument, 0,  'h' },
            {"MaxNbr",  required_argument, 0,  'm' },
            {"debug",   no_argument,       0,  'd' },
            {"file",    required_argument, 0,  'f' },
            {"seprator", optional_argument, 0,  's' },        
            {"verbose", no_argument,       0,  'v' },        
            {0,         0,                 0,  0 }
        };

        c = getopt_long(argc, argv, "l:h:m:f:df:s::v?",
                long_options, &option_index);
        if (c == -1) {
            break;
        }
        switch (c) {
            case 'l':
                printf("option c with value '%s'\n", optarg);
                break;
            case 'h':
                printf("option '%c' with value '%s'\n", c, optarg);
                break;
            case 'm':
                printf("option c with value '%s'\n", optarg);
                break;
            case '?':
                print_help();
                break;
            default:
                printf("default values for option '%c'", c);
                break;
        } // switch (c) 
        if (optind < argc) {
            printf("non-option ARGV-elements: ");
            while (optind < argc)
                printf("%s ", argv[optind++]);
            printf("\n");
        }         

    }
    return EXIT_SUCCESS;
}

int main (int argc, char *argv[])
{
    int iSecret, iGuess;
    ofstream myfile;
    long long MaxNbr = 99999;
    long low=0;
    long high=LLONG_MAX;

    // process_input

#if 1
    if (local_process_opt(argc, argv) == EXIT_FAILURE) {
        return EXIT_SUCCESS;
    } 
    /* initialize random seed: */
    srand (time(NULL));
    myfile.open(filename);
    /* generate secret number between 1 and 10: */
    for(long i=0; i<MaxNbr; i++) {
        myfile << rand() % 99999 + 1 << endl;
    }    
#else
    if(argc > 2){
        string value = argv[1];
        string::size_type sz = 0;
        MaxNbr =  stoll(value,&sz,0);
        cout << value.substr(0,sz) << " interpreted as " << MaxNbr << '\n';
        value = argv[2];
        
        if (value.find(".txt") != (value.length() - 4))
            value.append(".txt");
        cout << value << endl;
        myfile.open(value); 
        if(argc == 5) {
            value = argv[3];
            low = stoll(value,&sz,0);
            cout << value.substr(0,sz) << " interpreted as " << low << endl;
            value = argv[4];
            high = stoll(value,&sz,0);
            cout << value.substr(0,sz) << " interpreted as " << low << endl; 
        }

    } else {
        myfile.open("input_100.txt");
    }
    /* initialize random seed: */
    srand (time(NULL));

    /* generate secret number between 1 and 10: */
    
    for(long i=0; i<MaxNbr; i++) {
        myfile << rand() % 99999 + 1 << endl;
    }
#endif

    return 0;
}