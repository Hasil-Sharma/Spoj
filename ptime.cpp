#include <stdio.h>
#include <map>
#include <math.h>
using namespace std;
int main()
{
	int n,num[10001],i,j,primes[10000],k=0,numb;
	map<int,int> m;
	map<int,int> :: iterator p;
	for(i = 0; i < 10001; i++)
		num[i] = 0;
	for(i = 2; i <= sqrt(10000) ; i++)
	{
		if(num[i] == 0)
		{
			num[i] = 1;
			primes[k] = i;
			k++;
			for(j = i*i; j <= 10000; j+=i)
				num[j] = -1;
		}
	}

	while(scanf("%d",&n) != EOF)
	{
		for(i = 2; i <= n; i++)
		{
			numb = i;
			//printf("Checking for %d\n",numb);
			for(j = 0; j < k; j++)
			{
				if(numb % primes[j] == 0)
				{
					//printf("\tFinding for prime %d\n",primes[j]);
					p = m.find(primes[j]);
					if(p == m.end())
					{
						m.insert(pair<int,int>(primes[j],0));
						//printf("\t\tInserted %d to map\n",primes[j]);
						p = m.find(primes[j]);
					}
					while(numb%primes[j] == 0)
					{
						p->second++;
						numb = numb/primes[j];
					}
				}
				if(primes[j] > numb) break;
			}
			if(numb != 1)
			{
				p = m.find(numb);
				if(p == m.end())
				{
					m.insert(pair<int,int>(numb,0));
					//printf("\t\tInserted %d to map\n",primes[j]);
					p = m.find(numb);
				}
				p->second++;

			}
		}
		p = m.begin();
		printf("%d^%d",p->first,p->second);
		p++;
		while(p != m.end())
		{
			printf(" * %d^%d",p->first,p->second);
			p++;
		}
		printf("\n");
	}
	return 0;
}