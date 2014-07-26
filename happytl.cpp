#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;
int main()
{
	int n,m,x,y,se,ss,start[10000],duration[10000],i,j,count;
	scanf("%d %d",&n,&m);
	while(n+m)
	{
		for(i = 0; i <  n; i++)
		{
			scanf("%d %d %d %d",&x,&y,&start[i],&duration[i]);
			//cin >> x >> y >> start[i] >> duration[i];
			duration[i] += start[i];
		}
		for(i = 0; i < m; i++)
		{
			 count = 0;
			scanf("%d %d",&x,&y);
			//cin >> x >> y;
			//checking if the given range overlaps with the other call
			//durations
			for(j = 0; j < n; j++)
			{
				se = max(x,start[j]);
				ss = min(y+x,duration[j]);
				if(ss - se > 0) count++;
			}
			printf("%d\n",count);
			//cout << count << endl;
		}
		scanf("%d %d",&n,&m);
		//cin >> n >> m;
	}
	return 0;
}
