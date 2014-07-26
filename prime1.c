#include <stdio.h>
#include <string.h>
#include <math.h>
#define max 32000
#define diff 100001
int main()
{
	int i,j,t,m,n,temp1,temp2,primes[max],num[diff];
	scanf("%d",&t);
	memset(primes,1,sizeof(primes));
	for(i = 2; i < 179; i++)
	{
		if(primes[i])
		{
			for(j = i*i; j < max; j+=i)
				primes[j] = 0;
		}
	}
	while(t--)
	{
		scanf("%d %d",&m,&n);
		memset(num,1,(n-m+1)*sizeof(int));
		for(i = 2; i*i <= n; i++)
		{
			if(primes[i])
			{
				temp2 = m - m%i - i;//it is possible that i is greater than m
				if(temp2 < i) temp2 = i;
				//temp2 is the number smaller than m divisible by i prime number
				temp1 = n - m;
				for(j = temp2 + i - m; j <= temp1; j += i)
				{
					if(j >= 0 && num[j])
					{
						num[j] = 0;
					}
				}
			}
		}
		for(i = 0; i <= temp1; i++)
			if(num[i] && m+i > 1)
				printf("%d\n",m+i);
	}
	return 0;
}
