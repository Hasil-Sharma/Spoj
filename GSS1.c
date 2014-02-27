#include <stdio.h>
#define max 50001
int maxm(int a, int b){ return (b > a) ? b : a; }
int query(int *array, int *dp, int x, int y)
{
	int i,mx = dp[x];
	dp[x] = array[x];
	for(i = x+1; i <= y; i++)
	{
		dp[i] = maxm(dp[i-1]+array[i],array[i]);
		if(mx < dp[i]) mx = dp[i];
	}

	return mx;
}
int main()
{
	int n,i,array[max],m,x,y,ans,dp[max];
	scanf("%d",&n);
	for(i = 1; i <= n;  i++) scanf("%d",&array[i]);
	scanf("%d",&m);
	while(m--)
	{
		scanf("%d %d",&x,&y);
		ans = query(array,dp,x,y);
		printf("%d\n",ans);
	}
	return 0;
}