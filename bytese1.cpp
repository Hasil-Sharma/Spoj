#include <iostream>
using namespace std;
static int dist[101][101];
static int md[101][101];
static bool q[101];
void dijkstra()
{
	md[1][1] = dist[1][1];

}
int main()
{
	int k,m,n,a,b,T;
	cin >> k;
	while(k--)
	{
		cin >> m >> n;
		for (int i = 1; i <= m; ++i)
		{
			md[i] = 100000;
			for (int j = 1; j <= n; ++j)
			{
				cin >> dist[i][j];
			}
		}
		cin >> a >> b >> T;
		dijkstra();
	}

	return 0;
}