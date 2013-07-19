#include<stdio.h>
int main()
{
	int n,m,d;
	int a,b,i=0;
	scanf("%d",&d);
	while(i != d)
	{
		i ++;
		scanf("%d %d",&n,&m);
		a = n-m;
		b = (m-1)/2;
		if (a&b)
		{
			printf("0\n");
		}
		else
		{
			printf("1\n");
		}
	}
	return 0;
}