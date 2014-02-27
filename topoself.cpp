#include<stdio.h>
#include<stack>
#include<iostream>
using namespace std;
static int dist[300000];
static int parent[300000];
static int sort[300000];
static int adjlist[300000][5];
int adj0[] = {1,3,4};
int adj1[] = {2,3,4,5};
int adj2[] = {4,5};
stack<int> Stack;
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
		//printf("Checking adj list of %d and looking node %d\n",i,adjlist[i][k]);
		if(parent[adjlist[i][k]] == 0)
		{
			//printf("\tNow visting %d from %d\n",adjlist[i][k],i );
			parent[adjlist[i][k]] = 1;
			dfsvisit(n,adjlist[i][k]);
		}
	}
	Stack.push(i);

}
void dfs(int n)
{
	int i;
	for(i = 0; i < 3*n ; i++)
	{
		if(parent[i] == 0)
		{
			//printf("Starting from vertex %d\n", i);
			parent[i] = 1;
			dfsvisit(n,i);
		}
	}
}
int main()
{
	int n,i,a,b;
	scanf("%d",&n);
	while(n!=0)
	{
		for(i = 0;i < 3*n;i++)
		{
			//scanf("%d",&dist[i]);
			parent[i] = 0;
		}
		generateadj(n);
		//printf("Adj List\n");
		/*for(i = 0; i < 3*n; i++)
		{
			printf("%d :",i);
			for (int j = 0; j < getnumofneighbor(n,i); ++j)
			{
				printf(" %d",adjlist[i][j]);
			}
			printf("\n");
		}*/
		dfs(n);
		while (Stack.empty() == false)
	    {
	        cout << Stack.top() << " ";
	        Stack.pop();
	    }
	    cout << endl;
    	scanf("%d",&n);
	}
}