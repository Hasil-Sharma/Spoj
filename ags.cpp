#include<stdio.h>
using namespace std;
int main()
{
	int t,alfa,i;
	int a,d,r,n,mod,array[1000000];
	long long int ans,sum;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d %d",&a,&d,&r);
		scanf("%d %d",&n,&mod);
		if(n == 1) 
		{
			ans = a % mod;
			printf("%lld\n",ans);
			continue;
		}
		else if( n == 2)
		{
			ans = (a%mod + d%mod)%mod;
			printf("%lld\n",ans);
			continue;
		}
		alfa = (n-1)/2;
		if(n%2 == 0)// n is even
			alfa = alfa - 1;
			
		array[1] = r%mod;
		for(i = 2; i <= alfa; i++)
			array[i] = (array[i-1]*(r%mod))%mod;
		for(i = 1; i <= alfa;i++);
			sum += array[i];
		if(n%2 == 0) sum += 1%mod;
		sum = ((d%mod)*(sum%mod))%mod;
		ans = (((a%mod)*array[alfa])%mod + sum%mod)%mod;
		printf("%lld\n",ans);
		
	}
	return 0;
}
