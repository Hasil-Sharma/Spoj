#include<stdio.h>
using namespace std;
static int dist[51][51];
static int vistedf[51];
static int vistedb[51];
static int mdf[51];
static int mdb[51];
void relax(int u, int v,int *md)
{
	if(md[v] > md[u] + dist[u][v])
	{
		md[v] = md[u] + dist[u][v];
	}
}

void relaxb(int u, int v,int *md)
{
	if(md[v] > md[u] + dist[v][u])
	{
		md[v] = md[u] + dist[v][u];
	}
}

int getmin(int n, int *md)
{
	int min = 10000001,u,i;
	for(i = 1; i <= n; i++)
	{
		if(md[i] < min && vistedf[i] == 0)
		{
			min = md[i];
			u  = i;	
		} 
	}
	return u;
}


int getweight(int s, int d, int n)
{
	int u,numvisted = 0,i,ans,flag,k;
	for(i = 1; i <=n; i++)
	{
		mdf[i] = 10000001;
		mdb[i] = 10000001;
		vistedf[i] = 0;
		vistedf[i] = 0;
	}
	mdf[s] = 0;
	mdb[d] = 0;
	k = 0;
	while(true)
	{
		if(k%2)
		{
			//backward
			u = getmin(n,mdb);
			vistedb[u] = 1;
			for(i = 1; i<=n; i++)
				relaxb(i,u,mdb);
		}
		else
		{
			//forward
			u = getmin(n,mdf);
			vistedf[u] = 1;
			for(i = 1; i<=n; i++)
				relax(u,i,mdf);
		}
		k++;
		for(i=1,flag = 0; i <= n;i++)
		{
			if(vistedf[i] && vistedb[i])
			{
				flag = 1;
				break;
			}
		}
		if(flag) break;
		
	}
	ans = mdb[i] + mdf[i];
	for(i = 1; i <= n; i++)
		if(mdf[i] + mdb[i] < ans )
			ans = mdf[i]+mdb[i];
	return ans;
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