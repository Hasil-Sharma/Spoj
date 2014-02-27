#include <stdio.h>
int max(int a, int b)
{
	return (a > b) ? a : b;
}
int main()
{
	int ans[101][501],n,M,cost[101],fun[101],picks[101][501],mcost,i,j;
	while(1)
	{
		scanf("%d %d", &M, &n);
		if(M == 0 && n == 0) break;
		for(i = 1; i <= n; i++) scanf("%d %d",&cost[i],&fun[i]);
		for(i = 0; i <= n; i++)
			for(j = 0; j <= M; j++)
			{
				if(i == 0 || j == 0) ans[i][j] = 0;
				else if(cost[i] > j) ans[i][j] = ans[i-1][j];
				else ans[i][j] = max(ans[i-1][j],fun[i] + ans[i-1][j-cost[i]]);
			}

		for(i = 0; i <= M; i++)
			if(ans[n][i] == ans[n][M])
			{
				mcost = i;
				break;
			}

		printf("%d %d\n",mcost,ans[n][M]);
	}
	return 0;
}