#include <stdio.h>
int main()
{
	int t,count;
	long long int n,array[60],sum;
	array[0] = 1;
	for(int i = 1; i < 60; i++)
	{
		array[i] = 2*array[i-1];
	}
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld",&n);
		if(n == 1) 
		{
			printf("1 0\n");
			continue;
		}
		for(int i = 0; i < 60; i++)
		{
			if(array[i] > n)
			{
				if(n == array[i-1]) printf("%lld 0\n",array[i-1]);
				else
				{
					printf("%lld ",array[i]);
					count = 0;
					for(i = i-1,sum = 0,count = 0; i >= 0; i--)
					{
						count++;
						if(sum + array[i] <= n)
						{
							sum += array[i];
							if(sum == n) break;
						}

					}
					printf("%d\n",count);
				}
				break;
			}
		}
	}
}