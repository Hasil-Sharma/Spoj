#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
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
	int V;
	struct AdjList* array;
};

struct AdjListNode* newAdjListNode(int dest, int weight)
{
	struct AdjListNode* newNode = (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
	newNode->dest = dest;
	newNode->weight = weight;
	newNode->next = NULL;
	return newNode;
}

struct Graph* createGraph(int V)
{
	struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
	graph->V = V;
	graph->array = (struct AdjList*) malloc(V*sizeof(struct AdjList));
	int i;
	for(i = 0; i < V; ++i)
		graph->array[i].head = NULL;

	return graph;
}

void addEdge(struct Graph* graph, int src, int dest,int weight)
{
	struct AdjListNode* newNode = newAdjListNode(dest,weight);
	newNode->next = graph->array[src].head;
	graph->array[src].head = newNode;
}

struct City
{
	char name[11];
	int p;
};

struct CityList
{
	int n;
	struct City* array;
};

struct CityList* createCityList(int n)
{
	struct CityList* cityList = (struct CityList*) malloc(sizeof(struct CityList));
	cityList->n = n;
	cityList->array = (struct City*) malloc(n*sizeof(struct City));
	return cityList;
}
struct Graph* graph;
struct CityList* cities;
int *dist;
int *visited;
int getans(int src, int dest);
int getmin();
void relax(int u, int v, int w);
int main()
{
	int s,n,i,p,j,dest,weight,src,ans,r;
	char name[11];
	char source[11],destination[11];
	scanf("%d",&s);
	while(s--)
	{
		scanf("%d",&n);
		graph = createGraph(n);
		cities = createCityList(n);
		dist = (int*)malloc(n*sizeof(int));
		visited = (int*)malloc(n*sizeof(int));
		for(i = 0; i <  n; i++)
		{
			scanf("%s", name);
			scanf("%d",&p);
			strcpy(cities->array[i].name,name);
			cities->array[i].p = p;
			for(j = 0; j < p; j++)
			{
				scanf("%d %d",&dest,&weight);
				addEdge(graph,i,dest-1,weight);
			}
		}
		scanf("%d",&r);
		while(r--)
		{
			scanf("%s",source);
			scanf("%s",destination);
			for(i = 0, src = -1, dest = -1; i < n && (src == -1|| dest == -1); i++)
			{
				if(strcmp(cities->array[i].name,source) == 0) src = i;
				else if(strcmp(cities->array[i].name,destination) == 0) dest = i; 
			}
			ans = getans(src,dest);
			printf("%d\n",ans);
		}
	}
	return 0;
}

int getans(int src, int dest)
{
	int i,u;
	struct AdjListNode* pCrawl;
	for(i = 0; i < cities->n; i++)
	{
		dist[i] = INT_MAX;
		visited[i] = 0;
	}
	dist[src] = 0;
	while(1)
	{
		u = getmin();
		if(u == -1 || u == dest) break;
		visited[u] = 1;
		pCrawl = graph->array[u].head;
		while(pCrawl != NULL)
		{
			relax(u,pCrawl->dest,pCrawl->weight);
			pCrawl = pCrawl->next;
		}
	}
	return dist[dest];
}

int getmin()
{
	int i,min,u = -1;
	for(i = 0; i < cities->n; i++)
	{
		if(visited[i] == 0)
		{
			min = dist[i];
			u = i;
		}
	}
	for(i = 0; i < cities->n; i++)
	{
		if(dist[i] < min && visited[i] == 0)
		{
			u = i;
			min = dist[i];
		}
	}
	return u;
}

void relax(int u, int v, int w)
{
	if(dist[v] > dist[u] + w)
		dist[v] = dist[u] + w;
}