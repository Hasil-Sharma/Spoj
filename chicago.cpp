#include <stdio.h>
#include <map>
#include <list>
#include <limits.h>
using namespace std;
double dist[101][101];
int visited[101];
int md[101];
int nodes,dest;
map<int , list<int> > adjlist;
list<int> lst,path;
map<int , list<int> > :: iterator mapitr;
list<int> :: iterator listitr;
int getmin()
{
	int min = INT_MAX,index,i;
	for(i = 1; i <= nodes; i++)
	{
		if(md[i] < min && visited[i] == 0)
		{
			index = i;
			min = md[i];
		}
	}
	lst.remove(index);
	path.push_back(index);
	visited[index] = 1;
	return index;
}
void relax(int u, int v)
{
	if(md[v] > md[u]+dist[u][v])
	{
		md[v] = md[u]+dist[u][v];
	}
}
void dijkstra()
{
	int u,v;
	md[1] = 1;
	while(lst.empty() != true)
	{
		u = getmin();
		if(u == dest) break;
		mapitr = adjlist.find(u);
		listitr = mapitr->second.begin();
		while(listitr != mapitr->second.end())
		{
			relax(u,*listitr);
			listitr++;
		}
	}
}
int main()
{
	int n,m,a,b,i;
	double totprob,prob,p;
	scanf("%d%d",&n,&m);
	while(1)
	{
		nodes = n;
		dest = n;
		totprob = 1.0;
		for(i = 1; i <= n; i++)
		{
			md[i] = INT_MAX;
			visited[i] = 0;
			lst.push_back(i);
		}
		for(i = 0; i < m; i++)
		{
			scanf("%d%d%lf",&a,&b,&p);
			dist[a][b] = dist[b][a] = 1 - (p*1.0)/100;
			mapitr = adjlist.find(a);
			if(mapitr == adjlist.end())
			{
				adjlist.insert(pair<int , list<int> > (a,list<int>()));
				mapitr = adjlist.find(a);
				mapitr->second.push_back(b);
			}
			else mapitr->second.push_back(b);
			mapitr = adjlist.find(b);
			if(mapitr == adjlist.end())
			{
				adjlist.insert(pair<int , list<int> > (b,list<int>()));
				mapitr = adjlist.find(b);
				mapitr->second.push_back(a);
			}
			else mapitr->second.push_back(a);
		}
		mapitr = adjlist.begin();
		while(mapitr != adjlist.end())
		{
			printf("Node %d:",mapitr->first);
			listitr = mapitr->second.begin();
			while(listitr != mapitr->second.end())
			{
				printf(" %d(%lf)",*listitr,dist[mapitr->first][*listitr]);
				listitr++;
			}
			printf("\n");
			mapitr++;
		}
		dijkstra();
		while(path.size() != 1)
		{
			a = path.front();
			path.pop_front();
			b = path.front();
			prob = (1 - dist[a][b])/100;
			totprob = totprob*prob;

		}
		printf("%.6lf percent\n",totprob*100);
		scanf("%d",&n);
		if(n == 0) break;
		scanf("%d",&m);
		adjlist.clear();
		path.clear();
	}
}
