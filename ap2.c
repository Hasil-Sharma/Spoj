#include<stdio.h>
int main()
{
	long long int s,a_t,al_t,n,d,k,a;
	int t,i=0;
	scanf("%d",&t);
	while (i < t)
	{
		i += 1;
		scanf("%lld %lld %lld",&a_t,&al_t,&s);
		n = 2*s/(a_t+al_t);
		d = (2*a_t-2*s/n)/(5-n);
		a = a_t - 2*d;
		printf("%lld\n",n);
		printf("%lld",a);
		for(k=2;k<=n;k++)
			printf(" %lld",a+(k-1)*d);
		if (i == t)
		break;
		else
		printf("\n");
	}
}