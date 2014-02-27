#include <cstdio>
using namespace std;
int main()
{
	int t,n,a,i,flag;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		flag = 1;
		for(i = 0; i < n; i++)
		{
			scanf("%d",&a);
			if(a > i)
			{
				flag = 0;
			}
		}
		if(flag) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}