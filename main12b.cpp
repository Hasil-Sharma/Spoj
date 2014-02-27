#include <cstdio>
#include <map>
using namespace std;

int main()
{
	int t,index = 1,n;
	long long int array[100],num,max,temp,i,j;
	map<long long int,int> primes;
	map<long long int,int> :: iterator p;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for (i = 0; i < n; ++i)
			scanf("%lld",&array[i]);
		temp = array[0];
		for (i = 1; i < n; i++)
		{
			if(array[i] > temp)
			{
				temp = array[i];
			}
		}
		for(i = 2; i*i <= temp; i++)
		{
			for(j = 0 ;j < n; j++)
			{
				if(array[j]%i == 0)
				{
					primes[i]++;
					while(array[j]%i == 0)
						array[j] = array[j]/i;
				}
				if(array[j] != 1) primes[array[j]]++;
			}
		}
		printf("Case #%d: %lu\n",index, primes.size());
		p = primes.begin();
		while(p != primes.end())
		{
			printf("%lld\n",p->first);
			p++;
		}
		primes.clear();

	}
	return 0;
}