#include <stdio.h>
#include <stdlib.h>

unsigned long long int findSum(unsigned long long int a, unsigned long long int alfa,unsigned long long int mod,int flag);
unsigned long long int modular_pow(unsigned long long int r,unsigned long long int expt,unsigned long long int mod);
int main()
{
	unsigned long long int t,a,d,r,n,mod,ans,alfa,array;
	unsigned long long int sum,first;
	int flag;
	scanf("%llu",&t);
	while(t--)
	{
		scanf("%llu %llu %llu",&a,&d,&r);
		scanf("%llu %llu",&n,&mod);
		if(n == 1)
		{
			ans = a % mod;
			printf("%llu\n",ans);
			continue;
		}
		flag = (n%2 == 1) ? 1: 0;
		alfa = (n-1)/2;
		array = findSum(r,alfa,mod,flag);//r^alfa + ... + 1
		sum = array;
		first = ((a%mod)*modular_pow(r,alfa,mod))%mod;//(a*r^alfa)%mod
		if(n%2 == 1) sum = (sum -1%mod)%mod;
		sum = ((d%mod)*sum)%mod;
		printf("sum: %lld\n",sum);
		sum = (first + sum)%mod;
		printf("%llu\n",sum);
	}
	return 0;
}

//fix the sum problem is here
unsigned long long int findSum(unsigned long long int a, unsigned long long int alfa,unsigned long long int mod,int flag)
{
	unsigned long long int ans,temp,array,base;
	int n,i;
	if(alfa%2 == 0) n = alfa/2 - 1;//even
	else n = (alfa-1)/2;//odd
	base = ((a%mod)*(a%mod))%mod;//a^2%mod
	printf("Base: %llu\n",base);
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

unsigned long long int modular_pow(unsigned long long int r,unsigned long long int expt,unsigned long long int mod)
{
	unsigned long long int result = 1;
	unsigned long long int base = r;
	base = base % mod;
	while(expt)
	{
		if(expt%2 == 1)
			result = (result*base)%mod;
		expt = expt >> 1;
		base = (base*base)%mod;
	}
	return result%mod;
}

