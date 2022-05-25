#include <stdio.h>
#include <stdlib.h>


int main()
{
	float min_val, curPrice, maxProfit=0;
	scanf("%f",&min_val);
	while(scanf("%f",&curPrice) != EOF)
	{
        printf("%f", curPrice);
	    //min_val=min(min_val, curPrice);
	    //maxProfit=max(maxProfit, (curPrice*(asset/min_val)-asset));
	    //printf("%.3f, %.3f, %.3f\n",curPrice,  min_val, maxProfit) ;
	}
	printf("%.3f\n", maxProfit);
	return 0;
}
