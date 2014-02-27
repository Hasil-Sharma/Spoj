#include <cstdio>
#include <cstring>
#include <climits>
struct node
{
	char name[11];
	int p;
}city;
typedef struct node node;
node *citylist;
int totalcity;
int adjlist[10001][10001];
int *dist;
int *visited;
int getans(int s,int d);
int getmin();
void relax(int u, int v);
int main()
{
	int t,n,i,j,r,s,d,ans;
	char source[11],destination[11];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		totalcity = n;
		node cities[n+1];
		int tdist[n+1],tvisited[n+1];
		dist = tdist; visited = tvisited;
		citylist = cities;

		for(i = 1; i <= n; i++)
			for(j = 1; j <= n; j++)
				adjlist[i][j] = 0;

		for(i = 1; i <= n; i++)
		{
			scanf("%s",city.name);
			scanf("%d",&city.p);
			citylist[i] = city;
			for(j = 1; j <= city.p; j++)
			{
				scanf("%d",&r);
				scanf("%d",&adjlist[i][r]);
			}

		}
		scanf("%d",&r);
		while(r--)
		{
			scanf("%s",source);
			scanf("%s",destination);
			for(s=0,d=0,i=1; i<=n && (!s||!d);i++)
			{
				if(strcmp(citylist[i].name,source) == 0) s = i;
				if(strcmp(citylist[i].name,destination) == 0) d = i;
			}
			ans = getans(s,d);
			printf("%d\n",ans);
		}
	}
	return 0;
}

int getans(int s,int d)
{
	int i,u;
	for(i = 1; i <= totalcity; i++)
	{
		dist[i] = INT_MAX;
		visited[i] = 0;
	}

	dist[s] = 0;
	while(1)
	{
		u = getmin();
		if(u == -1) break;
		visited[u] = 1;
		for(i = 1; i <= totalcity; i++)
		{
			if(adjlist[u][i] != 0)
			relax(u,i);
		}
	}
	return dist[d];
}

int getmin()
{
	int i,min,u = -1;
	for(i = 1; i <= totalcity; i++)
	{
		if(visited[i] == 0)
		{
			min = dist[i];
			u = i;
		}
	}
	for(i = 1; i <= totalcity; i++)
	{
		if(dist[i] <= min && visited[i] == 0)
		{
			u = i;
			min = dist[i];
		}
	}
	return u;
}

void relax(int u, int v)
{
	if(dist[v] > dist[u] + adjlist[u][v])
		dist[v] = dist[u] + adjlist[u][v];

	return;
}