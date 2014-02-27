#include <cstdio>
using namespace std;
int array[1100];
int check(int a, int b)
{
	int sub = a - b;
	while(sub > 9)
	{
		if(sub%10 != 0) return 0;
		sub = sub/10;
	}
	return 1;
}
int getans(int p, int q)
{
	for(int i = 0; i < 1100)
}
int main()
{
	int t,a,p1,p2,num[10000],k=0,i,j,count,temp,index1,index2;
	
	for(i = 0; i < 10000; i++)
		num[i] = 0;

	for(i = 2; i < 10000;i++)
	{
		if(num[i] == 0)
		{
			num[i] = 1;
			if(i > 999)
			{
				array[k] = i;
				k++;
			}
			for(j = 2*i; j < 10000; j += i)
				num[j] = -1;
		}
	}
	/*for(i = 0; i < k; i++)
		printf("%d\n",primes[i]);*/
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d", &p1, &p2);
		count = getans(p1,p2);
		printf("%d\n",count);
	}
}