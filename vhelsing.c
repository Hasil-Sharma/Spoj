#include<stdio.h>
#include<math.h>
int main()
{
	int t,i=0,r;
	long double cube;
 	long double ans;
	scanf("%d",&t);
	while(i < t)
	{
		i++;
		scanf("%d",&r);
		cube = powl(r,3);
		ans = 8*(2-sqrt(2))*cube;
		printf("%Lf\n",ans);
	}
	return 0;
}