#include <stdio.h>
#include <map>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;
list<int> parent,vertices;
list<int> :: iterator litr;
map<int , list<int> > adjlist;
map<int , list<int> > :: iterator mapitr;
list<int> :: iterator listitr;
int visited[10001];
int dfs_visit(int s)
{
	int val = 0;
	mapitr = adjlist.find(s);
	listitr = mapitr->second.begin();
	while(listitr != mapitr->second.end())
	{
		if(find(parent.begin(),parent.end(),*listitr) == parent.end())
		{
			parent.push_back(*listitr);
			val = dfs_visit(*listitr);
			return val;
		}
		else  return 1;
		listitr++;
	}
	return val;
}
int dfs()
{
	int val = 0;
	litr = vertices.begin();
	while(litr != vertices.end())
	{
		if(find(parent.begin(),parent.end(),*litr) == parent.end())
		{
			parent.push_back(*litr);
			dfs_visit(*litr);
		}
		else return 1;
		litr++;
	}
	return val;
}
int main()
{
	int  n,m,i,u,v,a,b,val;
	scanf("%d%d",&n,&m);//n number of node and m is number of edges
	for(i = 1; i <= n; i++)
	{
		visited[i] = 0;
		vertices.push_back(i);
	}
	for(i = 0; i < m; i++)
	{
		scanf("%d%d",&a,&b);
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
	/*mapitr = adjlist.begin();
	while(mapitr != adjlist.end())
	{
		printf("Node %d:",mapitr->first);
		listitr = mapitr->second.begin();
		while(listitr != mapitr->second.end())
		{
			printf(" %d",*listitr);
			listitr++;
		}
		printf("\n");
		mapitr++;
	}*/
	//if(m == n -1)
	//{
		val = dfs();
		if(val == 1) printf("NO\n");
		else if(val == 0)printf("YES\n");
	//}
	//else printf("NO\n");
}