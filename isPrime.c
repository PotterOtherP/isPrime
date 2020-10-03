#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int checkPrime(int a)
{
   int c;
 
   for ( c = 2 ; c <= a - 1 ; c++ )
   { 
      if ( a%c == 0 )
     return 0;
   }
   return 1;
}


void factor(int x)
{
	printf("\nThe prime factorization of %d is: \n", x);
	printf("%d = ", x);

	int j = 2;
	int exp = 0;

	while (!checkPrime(x))
	{
		while (checkPrime(j) && ((x % j) == 0))
		{
			++exp;
			x /= j;
		}

		if (exp > 1)
			printf("(%d)^%d", j, exp);
		else if (exp == 1)
			printf("%d", j);

		if (exp > 0 && x > 1)
			printf(" * ");

		++j;
		exp = 0;
	}

	if (x > 1)
		printf("%d\n", x);

}


int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		printf("Run with one integer.\n");
		return -1;
	}

	int x = atoi(argv[1]);

	if (x == 0)
	{
		printf("Enter a real integer. And not zero.\n");
		return -1;
	}

	if (x >= (2147483646))
	{
		printf("That's too big.\n");
		return -1;
	}

	if (x != 0 && x <= 1)
	{
		printf("Try something bigger. Like a positive integer over 1.\n");
		return -1;
	}


	if (checkPrime(x))
		printf("\n%d is prime\n", x);
	else
	{
			factor(x);
	}

	



	return 0;
}
