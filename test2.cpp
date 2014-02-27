#include<stdio.h>
#include<math.h>
#include<cstdlib>
using namespace std;
long long int gcd(long long int a,long long int n)
{
	a = (a<0) ? -1*a : a;
	return (n != 0) ? gcd(n,a%n): a;
}
long long int pollardrho(long long int n)
{
	long long int x,y,g;
	int c;
	if (n%2 == 0)
	{
		/* code */
		return 2;
	}
	x = rand()%(n) + 1;
	y = x;
	c = 2;
	g = 1;
	while(g == 1)
	{
		x = ((x*x)%n + c)%n;
		y = ((y*y)%n + c)%n;
		y = ((y*y)%n + c)%n;
		g = gcd(x-y,n);
	}
	return g;
}
int main()
{
	long long int n,i,ans;
	int exponent;
	while(1)
	{
		scanf("%lld",&n);
		if(!n) break;
		while(n!=1)
		{
			ans = pollardrho(n);
			exponent = 0;
			while(n%ans == 0)
			{
				exponent++;
				n /= ans;
			}
			printf("%lld^%d ",ans,exponent);
		}
		printf("\n");
		
	}
	return 0;
}
