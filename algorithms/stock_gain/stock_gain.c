#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_BUFFER 65536  

// Is there a better way to define bytes in c or c++
#define KILOBYTES * 1024UL
#define MEGABYTES * 1048576
#define GIGABYTES * 1073741824UL


#define max(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })

#define min(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a < _b ? _a : _b; })

const bool _program_debug = false;


int main(int argc, char *argv[])
{
	float min_val=0.0, curPrice=0.0, maxProfit=0;
	float F[MAX_BUFFER];
	int i=0;
	scanf("%f",&min_val);
	int asset = 100;

	if(argc ==2) {
		int tmp = atoi(argv[1]);
		if (tmp > 0) {
			asset = tmp;
		}
	}

	float max_val;
	while(scanf("%f",&curPrice) != EOF)
	{
        printf("%3.2f ", curPrice);
		min_val=min(min_val, curPrice);
		float current_asset =  (curPrice * asset) - (min_val * asset);
		if (maxProfit < current_asset) 
			max_val = curPrice;
		maxProfit=max(maxProfit, current_asset);
	    if (_program_debug) printf("Step %d : c(%.2f), min(%.2f), max(%.2f) P(%.2f)\n", i, curPrice,  min_val, max_val, maxProfit) ;
		i++;
	}
	
	printf("%.3f\n", (maxProfit) - asset);
	return 0;
}


