#include<stdio.h>
static int dist[100001][100001];// distance between i and j
static int edge[100001][100001];//edge exists between i and j
static int visted[100001];//particular edge is visited
static int md[100001];//minimum distane to particular vertex

void relax(int u, int v)
{
	if(md[v] > md[u] + dist[u][v])
	{
		md[v] = md[u] + dist[u][v];
	}
}

int getmin(int n)
{
	int i,min = 0,node;
	for(i = 1; i <= n; i++)
	{
		if(md[i] <= min && visted[i] == 0) 
		{
			min = md[i];
			node = i;
		}
	}
	return node;
}

int main()
{
	int t,n,m,s,d,i,c1,c2,w,tot,j,u,v;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d",&n,&m,&s,&d);
		tot = n;
		for(i = 1; i <= n; i++)
		{
			visted[i] = 0;
			for(j = 1; j <= n; j++)
				edge[i][j] = 0;
		}
		for(i = 0; i < m; i++)
		{
			scanf("%d%d%d",&c1,&c2,&w);
			dist[c1][c2] = w;
			dist[c2][c1] = w;
			edge[c1][c2] = 1;
			edge[c2][c1] = 1;
		}
		visted[s] = 1;//making source as visted
		md[s] = 0;//setting distance from source to source as 0
		while(tot--)
		{
			if(visted[d] == 1) break;
			u = getmin(n);
			for(j = 1; j <= n; j++)
			{
				v = edge[u][j];
				relax(u,v);
			}

		}
		if(visted[d]) printf("%d\n",md[d]);
		else printf("NONE\n");
	}
}