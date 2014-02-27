#include <stdio.h>
using namespace std;
int fib(int n,int m)
{
	int a,b;
	if(n == 0 || n == 1) return n;
	else if(n % 2 == 1)
	{
		a = fib((n+1)/2,m);
		b = fib((n-1)/2,m);
		return (((a%m)*(a%m))%m + ((b%m)*(b%m))%m)%m;
	}
	else
	{
		a = fib(n/2-1,m);
		b = fib(n/2,m);
		return (2*((a%m*b%m)%m) + ((b%m)*(b%m))%m)%m;
	}
}
int main()
{
	int t,n,m,i,a,b,c,ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&m);
		//a(n) = 2*(fib(n+2) - 1) - n
		ans = fib(n+2,m)%m;
		ans = (ans + ans - n%m - 2)%m;
		printf("%d\n",ans);
	}
	return 0;
}