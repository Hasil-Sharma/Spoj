#include <stdio.h>
#include <string.h>
int main()
{
	int s,n,flag;
	flag = 1;
	scanf("%d %d",&s,&n);
	if(n == 1)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		if(s >= x) printf("YES\n");
		else printf("NO\n");
		return 0;
	}
	int array[n][2],visited[n];
	int ntemp = n;
	memset(visited,0,sizeof(visited));
	while(ntemp--)
	{
		scanf("%d %d",&array[n-ntemp-1][0],&array[n-ntemp-1][1]);
	}
	int min = 100000,imin = 0;
	ntemp = n;
	while(ntemp-- && flag)
	{
		for(int i = 0; i < n; i++)
		{

			if(array[i][0] < min && visited[i] == 0)
			{
				min = array[i][0];
			 	imin = i;
			}
		}
		visited[imin] = 1;
		if(s >= min)
		{
			s += array[imin][1];
		}
		else flag = 0;
	}
	(flag) ? printf("YES\n") : printf("NO\n");
	return 0;
}
