#include<stdio.h>

/*using namespace std;*/
int dist[51][51];
int visted[51];
int md[51];
void relax(int u, int v)
{
	if(md[v] > md[u] + dist[u][v])
	{
		md[v] = md[u] + dist[u][v];
	}
}
int getmin(int n)
{
	int min = 10000001,u,i;
	for(i = 1; i <= n; i++)
	{
		if(md[i] < min && visted[i] == 0)
		{
			min = md[i];
			u  = i;	
		} 
	}
	return u;
}

int getweight(int s, int d, int n)
{
	int u,numvisted = 0,i;
	for(i = 1; i <=n; i++)
	{
		md[i] = 10000001;
		visted[i] = 0;
	}
	md[s] = 0;
	while(numvisted < n)
	{
		numvisted++;
		u = getmin(n);
		visted[u] = 1;
		//printf("Extract min : %d\n",u);
		for(i = 1; i <= n; i++)
		{
			relax(u,i);
			//printf("Currently Relaxing: %d %d\n",u,i);
		}
	}
	return md[d];
}

int main()
{
	int t,n,r,s,d,tweight,k=1,i,j;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i = 1; i <= n; i++)
		{
			for(j = 1; j <= n; j++)
				scanf("%d",&dist[i][j]);
		}
		scanf("%d",&r);
		tweight = 0;
		while(r--)
		{
			scanf("%d %d",&s,&d);
			tweight += getweight(s,d,n);
		}
		printf("Case #%d: %d\n",k,tweight);
		k++;
	}
	return 0;
}
