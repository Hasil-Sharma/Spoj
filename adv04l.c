#include<stdio.h>
#include<math.h>
int isfib(n);
unsigned long long int cond(m);
int main()
{
	unsigned long long int m,ans,mx,tick,k;
	int t,i=0;
	long double phi = 1.6180339887498948482045868343656381177203091798057628621;
	scanf("%d",&t);
	while(i != t)
	{
	 	scanf("%llu",&m);
	 	ans = (unsigned long long int)(floorl(m*phi +2 - phi));
		i += 1;
		printf("%llu\n",ans);
	}
}
int isfib(n)
{
	unsigned long long int a,b;
	a = sqrt(5*(n<<1)+4);
	b = sqrt(5*(n<<1)-4);
	if ((int)a == a || (int)b == a)
	{
		return 1;
	}
	return 0;
}

unsigned long long int cond(m)
{
	while (!isfib(m))
		m -= 1;
	return m;
}