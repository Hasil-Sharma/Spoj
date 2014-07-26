#include <stdio.h>
#include <stdlib.h>

int findSum(int a,int alfa,int mod);
int modular_pow(int r,int expt,int mod);
int mulmod(int a,int b,int c);
int main()
{
	int t,r,n,mod,ans,alfa,array;
	int a,d;
	long long int first,sum;
	//printf("%d\n",mulmod(223631,147020,8550886));
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d %d",&a,&d,&r);
		scanf("%d %d",&n,&mod);
		if(n == 1)
		{
			ans = a % mod;
			printf("%d\n",ans);
			continue;
		}
		alfa = (n-1)/2;
		array = findSum(r,alfa,mod);//r^alfa + ... + 1
		sum = array;
		first = a%mod;
		first = (first*modular_pow(r,alfa,mod))%mod;//(a*r^alfa)%mod
		if(n%2 == 1) sum = (sum - 1%mod)%mod;
		sum = ((d%mod)*sum)%mod;
		sum = (first + sum)%mod;
		printf("%lld\n",sum);
	}
	return 0;
}

//fix the sum problem is here
int findSum(int a, int alfa,int mod)
{
	long long int ans,temp,array,base;
	int n,i;
	if(alfa%2 == 0) n = alfa/2 - 1;//even
	else n = (alfa-1)/2;//odd
	base = a;
	base = ((base%mod)*(base%mod))%mod;//a^2%mod//why isn't mulmod working ?
	if(1)
	{
		ans = 1;
		temp = 1;
		// sum = 1 + base + base^2 + ... + base^n
		for(i = 1; i <= n; i++)
		{
			temp = (temp*base)%mod;
			ans = (ans + temp)%mod;
			//ans = (ans + modular_pow(base,i,mod))%mod; 
		}
		if(alfa%2 == 0)
		{
			//temp = ((a%mod) + base)%mod;//(a+a^2)
			temp = (a%mod + 1%mod)%mod;
			temp = ((a%mod)*temp)%mod;
			ans = (temp*ans)%mod;
			ans = (1%mod + ans)%mod;// 1 + (1+a)*a*(1+..)
		}
		else
		{
			temp = (a%mod + 1%mod)%mod;
			ans = (temp*ans)%mod;
		}
	}
	return ans;
}

int modular_pow(int r,int expt,int mod)
{
	long long int result = 1;
	long long int base = r;
	base = base % mod;
	while(expt)
	{
		if(expt%2 == 1) result = ((result%mod)*(base%mod))%mod;
		expt = expt >> 1;
		base = (base%mod)*(base%mod);
		base = base%mod;
	}
	return result%mod;
}

