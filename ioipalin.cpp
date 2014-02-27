#include <cstdio>
#include <cstring>
static short int ans[5003][5003];
short int max(short int a, short int b)
{
	return (a > b) ? a : b;
}
int main()
{
	int n,fans,j,t;
	char str[5003],rstr[5003];
	scanf("%d",&n);
		scanf("%s",str+1);
		for(int i = 1,j=n; i <= n; i++,j--)
			rstr[i] = str[j];
		for(int i = 0; i <= n; i++)
			for(int j = 0; j <= n; j++)
			{
					if(i == 0 || j == 0) ans[i][j] = 0;
					else if(str[i] == rstr[j]) ans[i][j] = ans[i-1][j-1]+1;
					else ans[i][j] = max(ans[i-1][j],ans[i][j-1]);
			}
		fans = n - ans[n][n];
		printf("%d\n",fans);
	return 0;
}
