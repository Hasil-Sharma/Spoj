#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> array,connectedcomponent,tempval;
vector<vector<int> > *adjlist;
bool visited[1001];
void dfs(int s)
{
	connectedcomponent.push_back(s);
	visited[s] = true;
	for(int i = 0; i < adjlist->at(s).size(); i++)
	{
		if(!visited[adjlist->at(s)[i]])
			dfs(adjlist->at(s)[i]);
	}
}
int main()
{
	int t,n,m,a,i,u,v;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		//array.push_back(-1);//making array as 1 indexed
		adjlist = new vector<vector<int> >(n);
		for(i = 0; i < n; i++)
		{
			scanf("%d",&a);
			array.push_back(a);
			visited[i] = false;
		}
		for(i = 0; i < m; i++)
		{
			scanf("%d%d",&u,&v);
			adjlist->at(u-1).push_back(v-1);
			adjlist->at(v-1).push_back(u-1);
		}
		for(i = 0; i < n; i++)
		{
			if(!visited[i])
			{
				dfs(i);
				for(i = 0; i < connectedcomponent.size(); i++)
					tempval.push_back(array[connectedcomponent[i]]);
				sort(connectedcomponent.begin(), connectedcomponent.end());
				sort(tempval.begin(), tempval.end());
				for(i = 0; i < tempval.size(); i++)
					array[connectedcomponent[i]] = tempval[i];
				connectedcomponent.clear();
				tempval.clear();
			}
		}
		for(i = 0; i < n-1 ; i++)
			printf("%d ",array[i]);
		printf("%d\n",array[n-1]);
		array.clear();
	}
	return 0;
}