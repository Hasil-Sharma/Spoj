#include <stdio.h>
#define iin(a)		scanf("%d",&a);
unsigned long long int power(unsigned long long int,int,int);
unsigned long long int geosum(unsigned long long int r, int n, int mod);
int main()
{
	int t,a,d,r,n,mod;
	unsigned long long int ans,ret;
	scanf("%d",&t);
	while(t--)
	{
		iin(a);
		iin(d);
		iin(r);
		iin(n);
		iin(mod);
		ans = ((a%mod)*power((unsigned long long)r,(n-1)/2,mod)%mod)%mod;
		//ans = power((long long int)r,(n-1)/2,mod)%mod;
		ret  = (d%mod*geosum((unsigned long long)r,(n-1)/2,mod)%mod)%mod;
		// printf("%lld %lld\n",ret,ans);
		if(n%2 == 0)
		{
			ans = (ans + ret)%mod;
		}
		else
			ans = (ans + ret - d%mod)%mod;
		printf("%llu\n",ans);

	}
	return 0;
}


unsigned long long int power(unsigned long long int a,int n,int mod)
{
	if(n == 0) return 1%mod;
	else if( n == 1) return  a%mod;
	else if( n == 2) return (a%mod*a%mod)%mod;
	else if(n%2 == 1) return (a%mod*power(power(a,2,mod),n/2,mod)%mod)%mod;
	else return power(power(a,2,mod)%mod,n/2,mod)%mod;
}

unsigned long long int geosum(unsigned long long int r, int n, int mod)
{

	if(n == 0) return 1%mod;
	else if(n == 1) return (1%mod + r%mod)%mod;
	else if(n%2 == 1) return (geosum(r,1,mod)%mod * geosum(power(r,2,mod)%mod,(n-1)/2,mod)%mod)%mod;
	else return (1%mod +  (r%mod * geosum(r,1,mod)%mod * geosum(power(r,2,mod),(n-2)/2,mod)%mod)%mod)%mod;
}
