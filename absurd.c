#include<stdio.h>
long int removezero(long int c);
int main()
{
	long int t,c,i = 0,e1,e2,e3;
	long double ulimit,llimit;
	scanf("%ld",&t);
	while(i < t)
	{
		i ++;
		scanf("%ld",&c);
		c = removezero(c);
		llimit = 0.95*c;
		ulimit = 1.05*c;
		e1 = c - (c%10);
		if (e1 >= llimit && e1 <= ulimit)
		{
			printf("absurd\n");
			continue;
		}
		e2 = e1 + 5;
		if (e2 >= llimit && e2 <= ulimit && e2 != c)
		{
			printf("absurd\n");
			continue;
		}
		e3 = e2 + 5;
		if (e3 >= llimit && e3 <= ulimit)
		{
			printf("absurd\n");
			continue;
		}
		else
			printf("not absurd\n");
	}
	return 0;
}
long int removezero(long int c)
{
	if (c%10)
		return c;
	else
		return removezero(c/10);
}