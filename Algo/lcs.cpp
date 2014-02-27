#include <cstdio>
using namespace std;
int max(int a,int b)
{
	return (a>b)? a : b;
}
int main()
{
	char x[1000],y[1000];
	//x is a character array[1,2,...n]
	int n,m,lcs[1000][1000];//lcs[n][m],index for string starts from 1
	scanf("%d",&n);
	scanf("%s",x+1);
	scanf("%d",&m);
	scanf("%s",y+1);
	for(int i = 0; i <= n; i++)
		lcs[i][0] = 0;//lcs[n][0] == 0 
	for(int i = 0; i <= m; i++)
		lcs[0][i] = 0;//lcs[0][m] == 0

	for(int i = 1; i <= n; i++)
	{
		printf("From X taking Character: %c  i=%d\n",x[i],i);
		for(int j = 1; j <= m; j++)
		{
			if(x[i] == y[j]) lcs[i][j] = 1 + lcs[i-1][j-1];
			else lcs[i][j] = max(lcs[i][j-1],lcs[i-1][j]);
			printf("\tFrom Y taking Character: %c  j=%d LCS[i][j] = %d\n",y[j],j,lcs[i][j]);
		}
	}
		printf("%d\n",lcs[n][m]);
	return 0;
}
