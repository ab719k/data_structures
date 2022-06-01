/* 
random number generator example: 
*/
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <unistd.h>
 #include <getopt.h>

#include <iostream>
#include <fstream>
#include <string>
#include <climits>

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
    uint64_t N;
    string seprator;
    bool debug;
    bool verbose;
    string filename; 
    
    MainParam()
    {
        initialized = true;
        low=0;
        high=UINT64_MAX;
        random_seed = get_seed();
        seprator = '\n';
        filename = "random100.txt";
        N = 100;
        verbose =false;
        debug = false;
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
    cout << "\t low         :   lowest random, \n";
    cout << "\t max         :   highest random number,\n";      
    cout << "\t nbr         :   Number of random elements to be printed in the file ,\n";
    cout << "\t file        :   name of the file to store random numbers, \n";     
    cout << "\t debug       :   enable debug mode,\n";
    cout << "\t verbose     :   print random numbers being generated on screen as well,\n";
    cout << "\t separator   :   optional_argument (default is newline)" << endl; 
}
static inline int local_process_opt(int argc, char **argv)
{
    if(argc == 1) {
        print_help();
        return EXIT_FAILURE;
    }  
    int c;
    int digit_optind = 0; 
    int this_option_optind = optind ? optind : 1;
    int option_index = 0;
    static struct option long_options[] = {
        {"low",     required_argument, 0,  'l' },
        {"max",     required_argument, 0,  'm' },
        {"nbr",     required_argument, 0,  'n' },
        {"debug",   no_argument,       0,  'd' },
        {"file",    required_argument, 0,  'f' },
        {"seprator", optional_argument, 0,  's' },        
        {"help",    no_argument,           0, 'h' },        
        {"verbose", no_argument,        0,  'v' },        
        {0,         0,                 0,  0 }
    };
    while (1) {
        c = getopt_long(argc, argv, "l:m:n:f:dhs::v?",
                long_options, &option_index);
        if (c == -1) {
            break;
        }
    
        switch (c) {
            case 'l':
                P.low=atoi(optarg);
                break;
            case 'm':
                P.high=atoi(optarg);
                break;
            case 'n':
                P.N=atoi(optarg);
                break;
            case 's':
                //printf("option '%c' with value '%s'\n", c, optarg);
                P.seprator=optarg;
                cout << "{ P.seprator : \"" << P.seprator << "\" }" << endl;
                break;
            case 'd':
                P.debug=true;
                break;
            case 'v':
                P.verbose=true;
                break;
            case 'f':
                P.filename=optarg;
                break;
            case 'h':
                print_help();
                break;
            default:
                printf("default values for option '%c'", c);
                cout << "c = " << c << "& optarg" << optarg << endl;
                break;
        } // switch (c) 
    }
    if (optind < argc) {
        printf("non-option ARGV-elements: ");
        while (optind < argc)
            printf("%s ", argv[optind++]);
        printf("\n");
    }         
    return EXIT_SUCCESS;
}

int main (int argc, char *argv[])
{
    ofstream myfile;

    if(argc == 2 && argv[1][0] == '?') {
        print_help();
        return EXIT_SUCCESS;
    }
    if (local_process_opt(argc, argv) == EXIT_FAILURE) {
        return EXIT_SUCCESS;
    } 
    /* initialize random seed: TBD add more seed option later */
    srand (time(NULL));

    myfile.open(P.filename);
    uint64_t value = 0;
    for(uint64_t i=0; i<P.N; i++) {
        value = P.low + rand() % (P.high - P.low);
        if(P.verbose) {
            cout << value << P.seprator;
        }
        myfile <<  value << P.seprator;
    }    
    myfile << endl;     
    return 0;
}