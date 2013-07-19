#include<stdio.h>
int main()
{
	int n,t,i = 0,j;
	double ans;
	scanf("%d",&t);
	while(i < t)
	{
		ans = 0;
		i ++;
		scanf("%d",&n);
		for(j = 1; j <=n;j++)
		{
			ans += n/(1.0*j);
		}
		printf("%.2lf\n",ans);
	}
	return 0;
}