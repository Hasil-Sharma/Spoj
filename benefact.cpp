#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 50001
int visited[N];

int topmax;

struct AdjListNode
{
	int dest;
	int weight;
	struct AdjListNode* next;
};

struct AdjList
{
	struct AdjListNode *head;
};

struct Graph
{
	int v;
	struct AdjList* array;
};

struct Graph* createGraph(int V)
{
	struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
	graph->v = V;
	graph->array = (struct AdjList*)malloc((V+1)*sizeof(struct AdjList));
	int i;
	for(i = 0; i <= V; i++)
		graph->array[i].head = NULL;
	return graph;
}

struct AdjListNode* newAdjListNode(int dest,int weight)
{
	struct AdjListNode* newNode = (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
	newNode->dest = dest;
	newNode->weight = weight;
	newNode->next = NULL;
	return newNode;
}

void addEdge(struct Graph* graph, int src, int dest,int weight)
{
	struct AdjListNode* newNode = newAdjListNode(dest,weight);
	newNode->next = graph->array[src].head;
	graph->array[src].head = newNode;

	newNode = newAdjListNode(src,weight);
	newNode->next = graph->array[dest].head;
	graph->array[dest].head = newNode;
}

int max(int a, int b)
{
	return (a > b) ? a: b;
}

int dfs(struct Graph* graph, int vertex,int length)
{
	struct AdjListNode* temp = graph->array[vertex].head;
	visited[vertex] += 1;
	int temp_weight = temp->weight;
	while(temp)
	{
		if(visited[temp->dest] <= 2)
			temp_weight = (temp->weight,dfs(graph,temp->dest,length+temp_weight));
		temp = temp->next;
	}
	printf("%d %d\n",vertex,temp_weight);
	return temp_weight+length;
}
int main()
{
	int t,n,a,b,l,count,i,j;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		struct Graph* graph = createGraph(n);
		for( i = 0;i < n-1;  i++)
		{
			scanf("%d %d %d",&a,&b,&l);
			addEdge(graph,a,b,l);
		}
		dfs(graph,1,0);
	}
	return 0;
}
