#include <cstdio>
using namespace std;
int lcs[2001][2001],x[2001],y[2001];
int max(int a,int b)
{
	return (a>b)?a:b;
}
void getlcs(int n, int m)
{
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
		{
			if(x[i] == y[j]) lcs[i][j] = 1 + lcs[i-1][j-1];
			else lcs[i][j] = max(lcs[i-1][j],lcs[i][j-1]);
		}
}
int main()
{
	int d,n,m,i,ans,ans1;
	for(int i = 0; i < 2001;i++) 
	{
		lcs[i][0] = 0;
		lcs[0][i] = 0;
	}
	scanf("%d",&d);
	while(d--)
	{
		for(i =1; ;i++)   
		{                 
			scanf("%d",&x[i]);      
			if(x[i] == 0) break;    
		}                 
		n = i-1;
		ans1 = 0;
		while(1)
		{
			for(i = 1; ;i++)
			{
				scanf("%d",&y[i]);
				if(y[i] == 0) break;
			}
			m = i-1;
			if(m==0) break;
			getlcs(n,m);
			ans = lcs[n][m];
			if(ans > ans1) ans1 = ans;
		}
		printf("%d\n",ans1);
	}
}
