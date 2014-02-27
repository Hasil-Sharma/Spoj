#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	int t,n,ent[100],ext[100],i,mx,tim,count,mcount;
	scanf("%d",&t);
	while(t--)
	{
		mx = 0;
		scanf("%d",&n);
		for(i = 0;i < n;i++)
		{
			scanf("%d %d",&ent[i],&ext[i]);
		}
		tim = 0;
		count = 0;
		mcount = 0;
		std::sort(ent, ent+n);
		std::sort(ext, ext+n);
		for(i = 0; i < n; i++)
		{
			if(ent[i] < ext[tim])
			{
				count++;
				if(mcount < count) mcount = count;
			}
			else tim++;
		}
		printf("%d\n",mcount);
	}
}