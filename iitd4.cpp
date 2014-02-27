#include <cstdio>
#define MOD 1000000007
int main()
{
	int t,a,b,k,ans,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&a,&b,&k);
		ans = 0;
		for(i = a; i <= b; i++)
			ans += getfn(i,k);
	}
}