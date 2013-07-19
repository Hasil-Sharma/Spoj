#include<stdio.h>
#include<math.h>
int main()
{
	int t,i = 1;
	long long int r;
	long long int ans;
	scanf("%d",&t);
	while(i <= t)
	{
		scanf("%lld",&r);
		ans = 4*pow(r,2);
		printf("Case %d: %lld .25\n",i,ans);
		i++;
	}
	return 0;
}