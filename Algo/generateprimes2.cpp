#include <cstdio>
using namespace std;
int main()
{
	int n,primes[1000000],k = 1,flag;
	scanf("%d",&n);
	primes[0] = 2;
	for(int i = 3; i <= n; i++)
	{
		flag = 1;
		for(int j = 0; j < k; j++)
		{
			if(i%primes[j] == 0)
			{
				flag = 0;
				break;
			}
		}
		if(flag) primes[k++] = i;
	}
	for(int i = 0; i < k; i++)
		printf("%d\n",primes[i]);
	return 0;
}