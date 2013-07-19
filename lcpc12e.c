#include<stdio.h>
#include<math.h>
int main()
{
	int T,i = 0;
	double x1,y1,x2,y2,ac,l,bc,ab,cosa,ans;
	scanf("%d",&T);
	while(i < T)
	{
		i++;
		scanf("%lf %lf %lf %lf %lf %lf",&x1,&x2,&y1,&y2,&ac,&l);
		ab = sqrt(pow(x1-x2,2)+pow(y1-y2,2));
		bc = pow(l,2)/2.0;
		cosa = (pow(ab,2)+pow(ac,2)-bc)/(2*ab*ac);
		if (cosa <= 1)
		{
			ans = 2*ac*sqrt(1-pow(cosa,2));
			printf("%d. %.3lf\n",i,ans);
		}
		else
	 		printf("%d. No problem\n",i);
	}
	return 0;
}