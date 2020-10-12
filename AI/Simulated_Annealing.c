#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <limits.h>
#include <time.h>

int equation1(int start1, int start2)
{
	int eq1 = 0;
	eq1=pow(1.5 - start1 + start1*start2 ,2);
	return(eq1);
}

int equation2(int start1, int start2)
{
	int eq2 = 0;
	eq2 = pow(2.25 - start1 + start1*pow(start2,2),2);
	return(eq2);
}

int equation3(int start1,int start2)
{
	int eq3 = 0;
	eq3 =  pow(2.625 - start1 + (start2 * pow(start2,3)),2);
	return(eq3);
}


int randomRange(int min, int max)
{
    return ( rand() % ( max - min ) ) + min;
}
 

int main()
{
	int start1 = 1;	//X
	int start2 = 1;	//Y
	int stop = 5;	
	int step = 1;
	int x = INT_MAX;	//Predicted X
	int y = INT_MAX;	// Predicted Y
	int energy1 = 0;
	int energy2 = 0;
	int diff_energy = 0;

	int eq1 =0;
	int eq2 = 0;
	int eq3 = 0;
	srand(time(NULL));

	printf("Enter starting point(X):");
	scanf("%d",&start1);

	printf("\nEnter starting point(Y):");
	scanf("%d",&start2);

	printf("\nEnter Step Size:");
	scanf("%d",&step);

 	eq1=pow(1.5 - start1 + start1*start2 ,2);


	printf("%d\n",eq1);


	eq2 = pow(2.25 - start1 + start1*pow(start2,2),2);
	printf("%d\n", eq2);


	eq3 =  pow(2.625 - start1 + (start2 * pow(start2,3)),2);
	printf("%d\n", eq3);

	//energy = pow(1.5 - start1 + (start1*start2) ,2) + (pow(2.25 - start1 + (start1*pow(start2,2)),2)) + (2.625 - start1 + (start2 * pow(start2,3)),2);
	//printf("%d",energy);

	energy1 = eq1 + eq2 + eq3;
	printf("%d",energy1);


	for(start1=-5; start1<=stop; start1=start1+step)
	{
		for(start2=-5; start2<=stop; start2=start2+step)
		{
			eq1 = equation1(start1,start2);
			eq2 = equation2(start1,start2);
			eq3 = equation3(start1,start2);

			energy2 = eq1 + eq2 + eq3;
			diff_energy =  energy2 - energy1;

			if(energy2 < energy1)
			{
				x = start1;
				y = start2;
				/*
				printf("\nTest X:%d",x);
				printf("\tTest Y:%d",y);
				printf("test");
				*/
			}
/*
			else if(exp(diff_energy%start1) > randomRange(0,1))
			{
				x = start1;
				y = start2;
			}
			*/
		}
	}

	printf("\nresult X:%d",x);
	printf("\nresult Y%d",y);
	
}