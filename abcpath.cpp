#include <stdio.h>
#include <iostream>
#include <malloc.h>
using namespace std;
char graph[50][50];
int adjlist[2500][8][2];
int getindex(int x, int y, int height , int width)
{
	return x*(width) + y;
}
int getcount(int x, int y,int height, int width)
{
	if(x == 0 && y == 0) return 3;
	else if(x == 0 && y == width - 1) return 3;
	else if(x == height - 1 && y == 0 ) return 3;
	else if(x == height - 1 && y == width - 1) return 3;
	else if(y == 0) return 5;
	else if(y == width - 1) return 5;
	else if(x == 0) return 5;
	else if(x == height - 1) return 5;
	else return 8;
}
int getneb(int x, int y,int arr[][2],int height,int width)
{
	if(x == 0 && y == 0)
	{
		int tarr[][2] = {{1,0},{1,1},{0,1}};
		for(int i = 0; i < 3; i++)
			for(int j = 0; j < 2; j++)
				arr[i][j] = tarr[i][j];
		return 3;
	}
	else if(x == 0 && y == width - 1)
	{
		int tarr[][2] = {{0,y-1},{1,y-1},{1,y}};
		for(int i = 0; i < 3; i++)
			for(int j = 0; j < 2; j++)
				arr[i][j] = tarr[i][j];
		return 3;
	}
	else if(x == height - 1 && y == 0 )
	{
		int tarr[][2] = {{x - 1,0},{x - 1,1},{x,1}};
		for(int i = 0; i < 3; i++)
			for(int j = 0; j < 2; j++)
				arr[i][j] = tarr[i][j];
		return 3;
	}
	else if(x == height - 1 && y == width - 1)
	{
		int tarr[][2] = {{x,y-1},{x-1,y},{x-1,y-1}};
		for(int i = 0; i < 3; i++)
			for(int j = 0; j < 2; j++)
				arr[i][j] = tarr[i][j];
		return 3;
	}
	else if(y == 0)
	{
		int tarr[][2] = {{x-1,0},{x,1},{x+1,0},{x-1,1},{x+1,1}};
		for(int i = 0; i < 5; i++)
			for(int j = 0; j < 2; j++)
				arr[i][j] = tarr[i][j];
		return 5;
	}
	else if(y == width - 1)
	{
		int tarr[][2] = {{x-1,y},{x,y-1},{x+1,y},{x-1,y-1},{x-1,y-1}};
		for(int i = 0; i < 5; i++)
			for(int j = 0; j < 2; j++)
				arr[i][j] = tarr[i][j];
		return 5;
	}
	else if(x == 0)
	{
		int tarr[][2] = {{0,y-1},{0,y+1},{1,y-1},{1,y},{1,y+1}};
		for(int i = 0; i < 5; i++)
			for(int j = 0; j < 2; j++)
				arr[i][j] = tarr[i][j];
		return 5;
	}
	else if(x == height - 1)
	{
		int tarr[][2] = {{x,y-1},{x,y+1},{x-1,y-1},{x-1,y},{x+1,y+1}};
		for(int i = 0; i < 5; i++)
			for(int j = 0; j < 2; j++)
				arr[i][j] = tarr[i][j];
		return 5;
	}
	else
	{
		int tarr[][2] = {{x-1,y-1},{x-1,y},{x-1,y+1},
							{x,y-1},{x,y+1},
						{x+1,y-1},{x+1,y},{x+1,y+1}};
		for(int i = 0; i < 8; i++)
			for(int j = 0; j < 2; j++)
				arr[i][j] = tarr[i][j];
		return 8;
	}
}
void dfs(int index, int path, int ncount)
{

}
int main()
{
	int h,w,sx,sy,i,j,start[2500],startcnt,visted[50][50],path,ncount,neb[8][2],index,k;
	char string[50];
	while(true)
	{
		path = 0;
		startcnt = 0;
		cin >> h >> w;
		if(!(h+w)) break;

		for(i = 0; i < h; i++)
		{
			cin >> string;
			for(j = 0; j < w; j++)
			{
				visted[i][j] = 1;
				graph[i][j] = string[j];
				if(string[j] == 'A')
				{
					index = getindex(i,j,h,w);
					start[startcnt++] = index;
				}
			}
		}
		//generating adjlist
		for(i = 0; i < h; i++)
		{
			for(j = 0; j < w; j++)
			{
				ncount = getneb(i,j,neb,h,w);
				index = getindex(i,j,h,w);
				for(k = 0; k < ncount; k++)
				{
					adjlist[index][k][0] = neb[k][0];
					adjlist[index][k][1] = neb[k][1];
				}

			}
		}

		/*for(i = 0; i < h; i++)
		{
			for(j = 0; j < w; j++)
			{
				printf("Adjlist of %c at index (%d,%d)\n\t",graph[i][j],i,j);
				ncount = getcount(i,j,h,w);
				index = getindex(i,j,h,w);
				for(k = 0; k < ncount; k++)
					printf("%c ",graph[adjlist[index][k][0]][adjlist[index][k][1]]);
				printf("\n");
			}
		}*/

		for(i = 0 ; i < startcnt; i++)
		{
			sx = start[i]/w;
			sy = start[i]%w;
			index = getindex(sx,sy,h,w);
			dfs(index,path,getcount(sx,sy));
		}
	}
}