#include <stdio.h>
#define ll long long
ll gcd(ll a, ll b)
{
	while(a != b)
	{
		if(a > b) a = a - b;
		else b = b - a;
	}
	return a;
}

int main()
{
	int t;
	ll p,q,hcf,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld",&n);
		p = (n+1);
		q = 6*n*n;
		hcf = gcd(p,6);
		printf("%lld/%lld\n",p/hcf,q/hcf);
	}
	return 0;
}
