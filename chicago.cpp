#include <stdio.h>
#include <map>
#include <list>
#include <cstring>
#include <algorithm>
#include <climits>
#define N 101
using namespace std;
map<int, list<int> > adjList;
map<int, list<int> > :: iterator mapitr;
list<int> :: iterator listiter;
double weight[N][N];
double dist[N];
int visited[N];
int prev[N];
int getmax()
{
	int imax = -1;
	double melem = -1;
	for(int i = 1; i < N; i++)
	{
		if(dist[i] > melem && visited[i] != 1)
		{
			imax = i;
			melem = dist[i];
		}
	}
	return imax;
}

void relax(int s, int d)
{
	if(dist[d] < dist[s]*weight[s][d] )
	{
		dist[d] = dist[s]*weight[s][d];
		prev[d] = s;
	}
}
int main()
{
	int n,m,a,b,p;
	while(true)
	{
		scanf("%d",&n);
		if(!n) break;
		scanf("%d",&m);
		for(int i = 0; i < m; i++)
		{
			scanf("%d %d %d",&a,&b,&p);
			weight[a][b] = weight[b][a] =  p/100.0;
			mapitr = adjList.find(a);
			if(mapitr != adjList.end())
				mapitr->second.push_back(b);
			else
			{
				adjList.insert(make_pair(a,list<int>()));
				mapitr = adjList.find(a);
				mapitr->second.push_back(b);
			}
			mapitr = adjList.find(b);
			if(mapitr != adjList.end())
				mapitr->second.push_back(a);
			else
			{
				adjList.insert(make_pair(b,list<int>()));
				mapitr = adjList.find(b);
				mapitr->second.push_back(a);
			}

		}
		memset(visited,0,sizeof(visited));
		//memset not working !!
		for(int i = 0; i < N; i++)
			dist[i] = -1;

		dist[1] = 1;
		prev[1] = 0;
		while(true)
		{
			int source = getmax();
			if(source == -1|| source == n) break;
			visited[source] = 1;
			mapitr = adjList.find(source);
			listiter = mapitr->second.begin();
			while(listiter != mapitr->second.end())
			{
				relax(source,*listiter);
				listiter++;
			}
			
		}
		double ans = 100;
		int s = n, dest = prev[s];
		printf("%.6lf percent\n",dist[n]*100.0);
		adjList.clear();
	}
	return 0;
}
