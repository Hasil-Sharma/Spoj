#include <cstdio>
using namespace std;
long long int getans(int n, int k)
{
	int i;
	if (k > n) return 0;
	long long int ans = 1;
	for(i = 1; i <= k; i++)
	{
		printf("%lld\n",ans);
		ans *= n--;
		ans /= i;
	}
	return ans;
}
int main()
{
	int t,n,k;
	long long int ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&k);
		ans = getans(n-1,n-k);
		printf("%lld\n",ans);
	}
	return 0;
}