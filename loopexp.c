#include<stdio.h>
int main()
{
	int t,i = 0;
	long int n,j;
	double ans,temp;
	scanf("%d",&t);
	while(i < t)
	{
		i++;
		scanf("%ld",&n);
		ans = 0;
		for(j = 1.0; j <= n; j++ )
		{
			temp = 1.0/j;
			ans += temp; 
		}
		printf("%lf\n",ans);
	}
	return 0;
}