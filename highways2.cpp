#include <iostream>
#include <stdio.h>
static int dist[50001][50001];
static bool visted[100001];
using namespace std;
int main()
{
	int t,n,m,d,s,v1,v2,w;
	cin >> t;
	while(t--)
	{
		cin >> n >> m >> s >> d;
		for(int i = 1; i <= n; i++)
		{
			visted[i] = false;
			for(int j = 1; j <= n; j++)
				dist[i][j] = 0;
		}
		for (int i = 0; i < m; ++i)
		{
			/* code */
			cin >> v1 >> v2 >> w;
			dist[v1][v2] = w;
			dist[v2][v1] = w;
		}
		for(int i = 1; i <= n; i++)
		{
			printf("Adjlist of node: %d\n\t",i);
			for(int j = 1; j <= n; j++)
			{
				if(dist[i][j]) printf("%d ",j);
			}
			printf("\n");
		}
	}
	return 0;
}