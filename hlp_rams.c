#include <stdio.h>
int getBin(long long int n);
long long int power(int n);
int main()
{
	int t,num;
	long long int n,odd,even;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld",&n);
		num = getBin(n);
		odd = power(num);
		even = n - odd + 1;
		printf("%lld %lld\n",even,odd);
	}
	return 0;
}

int getBin(long long int n)
{
	int count = 0;
	while(n)
	{
		if(n%2 == 1) count++;
		n = n/2;
	}
	return count;
}

long long int power(int n)
{
	int ans = 1;
	while(n--)
	{
		ans *= 2;
	}
	return ans;
}