#include <cstdio>
int gcd(int a , int b)
{
	return (b == 0) ? a : gcd(b,a%b);
}
int main()
{
	int a, b,ans;
	scanf("%d %d",&a,&b);
	ans = gcd(a,b);
	printf("%d\n",ans);
}