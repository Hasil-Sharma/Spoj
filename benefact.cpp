#include <iostream>
#include <stdio.h>
#include <list>
#include <algorithm>
#include <limits.h>
#include <map>
using namespace std;
int nodes, maxd, *maxt;
int *array;
int *md;
list<int>* adjlist,adj;
bool *visited;
class Edge{
public:
	int u;
	int v;
	Edge(int tu,int tv){ u = tu; v = tv;}
	int get_u(){ return u; }
	int get_v(){ return v; }
};

bool operator<(Edge a, Edge b){ return true; }
bool operator==(Edge a, Edge b){ 
	if((a.u == b.u && a.v == b.v))
		return true;
	else return false;
}
map<Edge,int> edgelist;
Edge ref(1,1);
void dfs_visit(int s)
{
	int dist;
	list<int> :: iterator listitr;
	map<Edge,int> :: iterator p;
	for(listitr = adjlist[s].begin(); listitr != adjlist[s].end(); listitr++)
	{
		if(visited[*listitr] == false && array[s] != *listitr)
		{
			p = edgelist.begin();
			while(p != edgelist.end())
			{
				if((p->first.u == *listitr && p->first.v == s) || (p->first.v == *listitr && p->first.u == s))
				{
					dist = p->second;
					break;
				}
				p++;
			}
			dist = p->second;
			//printf("%d %d :%d\n",s,*listitr,dist);
			md[*listitr] = md[s] + dist;
			array[*listitr] = s;
			visited[*listitr] = true;
			dfs_visit(*listitr);
		}
	}
	return;
}
void dfs()
{
	int i,j;
	maxd = INT_MIN;
	for(i = 1; i <= nodes; i++)
	{
		for(j = 1 ; j <= nodes; j++)
		{
			visited[j] = false;
			array[j] = 0;
			md[i] = INT_MIN;
		}
		if(visited[i]== false)
		{
			array[i] = -1;
			visited[i] = true;
			md[i] = 0;
			dfs_visit(i);
		}
		maxt = max_element(md,md+nodes);
		if(*maxt > maxd) maxd = (*maxt);
	}
}
int main()
{
	int t,n,a,b,i,w;
	scanf("%d",&t);
	list<int> :: iterator listitr;
	while(t--)
	{
		scanf("%d",&n);//number of node
		nodes = n;
		adjlist = new list<int>[n+1];
		visited = new bool[n+1];
		array = new int[n+1];
		md = new int[n+1];
		while(scanf("%d%d%d",&a,&b,&w) != EOF)
		{
			adjlist[a].push_back(b);
			adjlist[b].push_back(a);
			edgelist.insert(pair<Edge,int>(Edge(a,b),w));
		}
		dfs();
		printf("%d\n", maxd);
	}
}