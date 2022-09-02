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

int find_peak(int *A, int l, int r)
{
	if(A[l] > A[l+1]) {
		// found peak on the left
		return l;
	} else if (A[r-1] < A[r]) {
		//found peak on the right
		return r;
	} 
	if()
}

int main(int argc, char *argv[])
{
	int i=0;
	int A[MAX_BUFFER];

	if(argc > 1) {
		printf("No Argument Expected\n");
		return EXIT_FAILURE;
	}
	
	while(scanf("%d",&A[i++]) != EOF) {
        printf("%d", A[i-1]);
	}
	find_peak(A, 0, i);
	
	return 0;
}


