#include<stdio.h>
#include<math.h>
int main()
{
	int T,p0,p1,t,p,i = 0;
	double k,ans;
	scanf("%d",&T);
	while(i < T)
	{
		i++;
		scanf("%d %d %d %d",&p0,&p1,&t,&p);
		k = (log(p1) - log(p0))/t;
		ans = (log(p) - log(p0))/k;
		printf("Scenario #%d: %.2lf\n",i,ans);
	}
	return 0;
}
