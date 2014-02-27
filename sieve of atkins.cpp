#include <stdio.h>
int main()
{
	int n,num[1000001],i,j,primes[1000000],k=0;
	for(i = 0; i < 1000001; i++)
		num[i] = 0;
	scanf("%d",&n);
	for(i = 2; i <= n ; i++)
	{
		if(num[i] == 0)
		{
			num[i] = 1;
			primes[k] = i;
			k++;
			for(j = 2*i; j <= n; j+=i)
				num[j] = -1;
		}
	}
	for(i = 0; i < k; i++)
		printf("%d\n",primes[i]);

}