#include<stdio.h>
#include<list>
using namespace std;
static int dist[51][51];
static int md[51];
void relax(int u, int v)
{
	if(md[v] > md[u] + dist[u][v])
	{
		md[v] = md[u] + dist[u][v];
	}
}
int getmin(std::list<int> lst)
{
	int min = 10000001,u;
	list<int>::iterator p = lst.begin();
	while(p != lst.end())
	{
		if(md[*p] < min) 
		{
			u = (*p);
			min = md[*p];
		}
		p++;
	}
	return u;
}
int getweight(int s, int d, int n)
{
	int u;
	list<int> lst;
	for(int i = 1; i <= n ; i++)
	{
		lst.push_back(i);
		md[i] = 10000001;
	}
	md[s] = 0;
	while(!lst.empty())
	{
		u = getmin(lst);
		lst.remove(u);
		for(int i = 1; i <= n;i++)
			relax(u,i);
	}

	return md[d];
}
int main()
{
	int t,n,r,s,d,tweight,k=1;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
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