#include<stdio.h>
int main()
{
	int n,k,coef[1001],points[100],i,point,j,index = 1,temp;
	long long int ans;
	while(true)
	{
		scanf("%d",&n);
		if(n == -1) break;
		for(i = 0; i <= n; i++)
		{
			scanf("%d",&coef[i]);
		}
		scanf("%d",&k);
		printf("Case %d:\n",index);
			index++;
		for(i = 0; i < k; i++)
		{
			scanf("%d",&points[i]);
			point = points[i];
			temp = point;
			ans = 0;
			ans += coef[n];
			//printf("Setting ans to itital of %llu\n",ans);
			for(j = n - 1; j >= 0; j--)
			{
				//printf("Multiplying %d & %d\n",coef[j],point);
				ans = ans + coef[j]*point;
				point = point*temp;
			}
			//printf("\n");
			printf("%lld\n",ans);

		}
	}
}