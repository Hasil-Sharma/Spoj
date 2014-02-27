#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
	int q,n,m,i,count,primes[100001],k = 0;
	bool array[100001];
	for(i = 2; i < 100001; i++)
	{
		array[i] = true;
	}
	for(i = 2; i < 100001; i++)
	{
		if(array[i] = true)
		{
			primes[k++] = i;
			for(int j = i; j < 100001; j += i)
			{
				array[j] = false;
			}
		}
	}
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d",&n,&m);
		count = 0;
		for(i = 1; i <= m; i++)
		{
			array[i] = true;
		}
		for(i = 0;;i++)
		{
			if(primes[i] > n) break;
			
			if(n%primes[i] == 0)
			{
				for(int j = primes[i]; j <= m; j += primes[i])
				{
					array[j] = false;
				}
				while(n%primes[i] == 0)
					n = n/primes[i];
			}
			
		}
		if(n != 1)
		{
			for(int j = n; j <= m; j += n)
			{
				array[j] = false;
			}
		}
		for(i = 1 ; i <= m; i++)
			if(array[i]) count++;
		printf("%d\n",count);
	}
}