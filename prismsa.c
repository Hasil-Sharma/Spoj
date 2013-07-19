#include<stdio.h>
#include<math.h>
int main()
{
	int t,i=0;
	long int v;
	long double ans,a;
	scanf("%d",&t);
	while (i < t)
	{
		i ++;
		scanf("%ld",&v);
		a = powl(4*v,1.0/3);
		ans = 6*sqrtl(3)*v/a;
		printf("%Lf\n",ans);
	}
	return 0;
}