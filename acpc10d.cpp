#include<stdio.h>
using namespace std;
static int dist[300000];
static int weight[300000];
static int parent[300000];
static int visted[300000];
static int list[300000];
static int adjlist[300000][5];
int listindex;
int adj0[] = {1,3,4};
int adj1[] = {2,3,4,5};
int adj2[] = {4,5};
int getnumofneighbor(int n,int i)
{
	if(i < 3*n - 3)
	{
		if(i%3 == 0) return 3;
		else if(i%3 == 1) return 4;
		else return 2;
	}
	else if( i >= 3*n - 3 && i != (3*n-1)) return 1;
	else return 0;
}
void getneighbor(int i)
{
	int n,j;
	if(i%3 == 0) 
	{
		n = 3;
		j = i/3;
		for(int k = 0; k < n; k++)
			adjlist[i][k] = adj0[k] + 3*j;

	}
	else if(i%3 == 1) 
	{
		n = 4;
		j = i/3;
		for(int k = 0; k < n; k++)
			adjlist[i][k] = adj1[k] + 3*j;
	}
	else
	{ 
		n = 2;
		j = i/3;
		for(int k = 0; k < n; k++)
			adjlist[i][k] = adj2[k] + 3*j;
	}
}
void generateadj(int n)
{
	int i,j;
	for (i = 0; i < 3*n-3; ++i)
	{
		getneighbor(i);
	}
	for(i = 3*n-3; i < (3*n-1); ++i)
	{
		adjlist[i][0] = i+1;
	}
}
void dfsvisit(int n,int i)
{
	int j,k;
	j = getnumofneighbor(n,i);
	for(k = 0; k < j; k++)
	{
		if(parent[adjlist[i][k]] == 0)
		{
			parent[adjlist[i][k]] = 1;
			dfsvisit(n,adjlist[i][k]);
		}
	}
	//printf("Putting %d on index %d\n",i, listindex);
	list[listindex] = i;
	listindex--;

}
void dfs(int n)
{
	int i;
	for(i = 0; i < 3*n ; i++)
	{
		if(parent[i] == 0)
		{
			parent[i] = 1;
			dfsvisit(n,i);
		}
	}
}
int main()
{
	int n,i,a,b,s,d,node,neighbor,index = 1;
	scanf("%d",&n);
	while(n!=0)
	{
		listindex = 3*n-1;
		for(i = 0;i < 3*n;i++)
		{
			scanf("%d",&weight[i]);
			parent[i] = 0;
			dist[i] = 0;
			visted[i] = 0;
		}
		generateadj(n);
		dfs(n);
		s = 1;
		d = 1 + (n-1)*3;
		node = 1;
		dist[node] = weight[node];
		listindex = 1;
		while (listindex < 3*n)
	    {
	        node = list[listindex];
	        listindex++;
	        //printf("Checking for Node: %d\n",node);
	        for(i = 0; i < getnumofneighbor(n,node); i++)
	        {
	        	neighbor = adjlist[node][i];
	        	//printf("\tChecking neighbor %d\n",neighbor);
	        	if(visted[neighbor] == 0)
	        	{
	        		dist[neighbor] = dist[node] + weight[neighbor];
	        		visted[neighbor] = 1;
	        		//printf("\t\tSetting Distance to neighbor as %d as it is visted for first time\n",dist[neighbor]);
	        	}
	        	else
	        	{
	        		if(dist[node] + weight[neighbor] < dist[neighbor])
	        		{
	        			//printf("\t\tSetting Distance to neighbor from %d",dist[neighbor]);
	        			dist[neighbor] = dist[node] + weight[neighbor];
	        			//printf(" to %d\n",dist[neighbor] );
	        		}
	        		//else printf("\t\t Not changing the distance\n");
	        	}
	        }
	    }
	    printf("%d. %d\n",index,dist[d]);
	    index ++;
    	scanf("%d",&n);
	}
}