#include<stdio.h>
int main()
{
	unsigned long long int x,n,,ans;
	int i,t;
	i = 0;
	scanf("%d",&t);
	while(i != t)
	{
		scanf("%llu %llu",&x,&n);
		ans = x + (x-n)/(n-1) + 1;
		printf("%llu\n",ans);
		i += 1;
	}

	return 0;
}