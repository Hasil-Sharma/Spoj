#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#define N 1000001
using namespace std;
bool prime[N];
bool ans[N];
int getans(long long int n)
{
	int count = 0;
	bool flag;
	//printf("%d\n",n);
	for(int i = 2; i <= N; i++)
	{
		if(prime[i] && i*i > n)
		{
			flag = false;
			break;
		}
		if(prime[i] && n%i == 0)
		{
			//printf("\t%d\n",i);
			if(!ans[i]) count ++;
			ans[i] = true;
			while(n%i == 0)
				n = n/i;
		}
	}
	if(n > 1 && !ans[n] && !flag)
	{
		//printf("\t%d\n",n);
		ans[n] = true;
		count++;
	}
	return count;
}
int main()
{
	int t,n,ca =1;
	long long int array[100];
	scanf("%d",&t);
	memset(prime,true,sizeof(prime));
	prime[0] = prime[1] = false;
	for(int i =2; i < sqrt(N); i++)
		if(prime[i] == true)
		{
			for(int j = i*i; j < N; j+=i)
				prime[j] = false;
		}
	while(t--)
	{
		scanf("%d",&n);
		for(int i = 0; i < n; i++)
			scanf("%lld",&array[i]);
		sort(array,array+n);
		int count = 0;
		for(int i = 0; i < N; i++)
			ans[i] = false;
		ans[0] = ans[1] = false;	
		for(int i = 0; i < n; i++)
			count += getans(array[i]);
		printf("Case #%d: %d\n",ca,count);
		ca++;
		for(int i = 0; i < N; i++)
			if(ans[i])
				printf("%d\n",i);
	}
	return 0;
}
