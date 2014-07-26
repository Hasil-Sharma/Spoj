#include <stdio.h>
#define ll long long
void multiply(ll F[2][2],ll M[2][2]);
void power(ll F[2][2],int n);
int m,mod;

ll fib(int n)
{
	ll F[2][2] = {{1,1},{1,0}};
	if(n == 0)
		return 0;
	power(F,n-1);
	return F[0][0]%mod;
}

void power(ll F[2][2],int n)
{
	if(n == 0 || n == 1)
		return;
	ll M[2][2] = {{1,1},{1,0}};

	power(F,n/2);
	multiply(F,F);
	
	if(n%2 != 0)
		multiply(F,M);
}

void multiply(ll F[2][2], ll M[2][2])
{
	ll x = ((ll)F[0][0]*M[0][0])%m + ((ll)F[0][1]*M[1][0])%m;
	ll y = ((ll)F[0][0]*M[0][1])%m + ((ll)F[0][1]*M[1][1])%m;
	ll z = ((ll)F[1][0]*M[0][0])%m + ((ll)F[1][1]*M[1][0])%m;
	ll w = ((ll)F[1][0]*M[0][1])%m + ((ll)F[1][1]*M[1][1])%m;

	 F[0][0] = x%m;
	 F[0][1] = y%m;
	 F[1][0] = z%m;
	 F[1][1] = w%m;
}

int main()
{
	int t,n;
	ll ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&mod);
		m = mod;
		ans = fib(n+2)%mod;
		ans = (ans + ans - (2%mod) - (n%mod))%mod;
		if(ans < 0)
			ans += m;
		printf("%lld\n",ans);
	}
	return 0;
}
