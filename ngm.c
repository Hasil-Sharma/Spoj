#include<stdio.h>
int main()
{
	long int n;
	int i;
	scanf("%ld",&n);
	i = n %10;
	if (i)
	{
		printf("1\n");
		printf("%d\n",i);
	}
	else
		printf("2\n");
}