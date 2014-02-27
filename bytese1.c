#include <stdio.h>
#include <stdlib.h>
#define INT_MAX 100000
void relax(int u , int v);
void dijkstra(int dest);
void addnode(int i, int j);
int getneighcount(int index);
int getmin();
int allvisited();
void getneigh(int i, int j, int* arr, int index);
int dist[101][101];
int visited[10001];
int md[10001];
int row,col;
struct node
{
	int x;
	int y;
	int w;
	int index;
	int numneighbour;
	int neighbour[4];
}node;
struct node all_nodes[10002];
int main()
{
	int k,m,n,i,weight,j,a,b,T;
	scanf("%d",&k);
	while(k--)
	{
		scanf("%d%d",&m,&n);
		row = m;
		col = n;
		for(i = 1; i <= m; i++)
		{
			for(j = 1; j <= n; j++)
			{
				scanf("%d",&dist[i][j]);
				addnode(i,j);
			}
		}
		scanf("%d%d%d",&a,&b,&T);
		for(i = 1; i <= m*n; i++)
		{
			visited[i] = 0;
			md[i] = INT_MAX;
		}
		if(T < dist[1][1])
		{
			printf("NO\n");
			continue;
		}
		dijkstra((a-1)*n+b);
		if((T-md[(a-1)*n+b])>=0)
		{
			printf("YES\n");
			printf("%d\n",T - md[(a-1)*n+b] );
		}
		else printf("NO\n");

	}
}
void addnode(int i, int j)
{
	node.x = i;
	node.y = j;
	node.w = dist[i][j];
	node.index = (i-1)*col + j;
	node.numneighbour = getneighcount(node.index);
	getneigh(i,j,node.neighbour,node.index);
	all_nodes[node.index] = node; 
}

int getneighcount(int index)
{
	//for four corners
	if(index == 1 || index == col || index == row*col || index == (row-1)*col+1)
		return 2;
	//for first col and last col
	else if(index%col == 1 || index%col == 0)
		return 3;
	//for first row and last row
	else if((index/col+1)== 1|| (index/col+1)==row)
		return 3;
	//for rest
	else return 4;
}

void getneigh(int i, int j, int* arr, int index)
{
	//Considering all four corners
	if(index == 1)
	{
		arr[0] = 2;
		arr[1] = 1+col;
	}
	else if(index == col)
	{
		arr[0] = col-1;
		arr[1] = col+col;
	}
	else if(index == (row-1)*col +1)
	{
		arr[0] = (row-2)*col+1;
		arr[1] = (row-1)*col+2;
	}
	else if(index == row*col)
	{
		arr[0] = index - 1;
		arr[1] = index - col;
	}
	//first col
	else if(index%col == 1)
	{
		arr[0] = index - col;
		arr[1] = index + 1;
		arr[2] = index + col;
	}
	//last col
	else if(index%col == 0)
	{
		arr[0] = index - col;
		arr[1] = index - 1;
		arr[2] = index + col;
	}
	//first row
	else if((index/col+1) == 1)
	{
		arr[0] = index + 1;
		arr[1] = index - 1;
		arr[2] = index + col;
	}
	//last row
	else if((index/col+1) == row)
	{
		arr[0] = index + 1;
		arr[1] = index - 1;
		arr[2] = index - col;
	}
	//rest
	else
	{
		arr[0] = index - 1;
		arr[1] = index + 1;
		arr[2] = index + col;
		arr[3] = index - col;
	}
}

void dijkstra(int dest)
{
	int u,count,i;
	int *array;
	md[1] = dist[1][1];
	while(1)
	{
		u = getmin(row,col);
		visited[u] = 1;
		if(u == dest) break;
		count = getneighcount(u);
		array = all_nodes[u].neighbour;
		for(i = 0; i < count; i++)
		{
			relax(u,array[i]);

		}
	}
}

int allvisited()
{
	int i;
	for(i = 1; i <= row*col; i++)
	{
		if(visited[i] == 0) return 1;
	}
	return 0;
}

int getmin()
{
	int i,min,index;
	min = INT_MAX;
	for(i = 1; i <= row*col; i++)
	{
		if(md[i] <= min && visited[i] == 0)
		{
			min = md[i];
			index = i;
		}
	}
	return index;
}

void relax(int u , int v)
{
	if(md[v] > md[u] + all_nodes[v].w)
	{
		md[v] = md[u] + all_nodes[v].w;
	}
}