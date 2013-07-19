#include<stdio.h>
#include<math.h>
int main()
{
	long int n;
	float disc;
	scanf("%ld",&n);
	while (n != -1)
	{
		disc = sqrtf(1+ 4*(n-1)/3);
		if (fmod(disc,2) == 1)
			printf("Y\n");
		else
			printf("N\n");
		scanf("%ld",&n);
	}
	return 0;
}