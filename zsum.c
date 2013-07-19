#include<stdio.h>
unsigned long long int power(unsigned long long int x, unsigned long long int n);
int main()
{
	unsigned long long int n,k,c;
	unsigned long long int ans;
	c = 10000007;
	scanf("%llu %llu",&n,&k);
	while(n != 0 && k !=0)
	{
		ans = 0;
		ans += power(n,n)%10000007;
		ans += 2*power(n-1,n-1)%10000007;
		ans += 2*power(n-1,k)%10000007;
		ans += power(n,k)%10000007;
		printf ("%llu\n",ans);
		scanf("%llu %llu",&n,&k);
	}
	return 0;
	
}

unsigned long long int power(unsigned long long int x,unsigned long long int n)
{
	if (n == 0) 
		return 1;
	else if (n == 1) 
		return x%10000007;
	else if (n % 2 == 0)
		return power(x*x,n/2)%10000007;
	else if (n % 2) 
		return (x*power(x*x,(n-1)/2))%10000007;
}
