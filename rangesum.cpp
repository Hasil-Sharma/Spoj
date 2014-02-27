#include <stdio.h>
#include <list>
using namespace std;

int main()
{
	int n,array[200001],i,q,a,l,r,x;
	long long int sum[300001],temp1,temp2;
	list<int> lst;
	list<int> :: iterator p;
	scanf("%d",&n);
	sum[0] = 0;
	for(i = 1; i <= n; i++)
	{
		scanf("%d",&array[i]);
		sum[i] += array[i] + sum[i-1];
	}
	/*for(i = 1; i <=  n; i++)
	{
		printf("%lld ",sum[i]);
	}
	printf("\n");*/
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d",&a);
		if(a == 1)
		{
			scanf("%d %d",&l,&r);
			printf("%lld\n",sum[r]-sum[l-1]);

		}
		else if(a == 2)
		{
			scanf("%d",&x);
			//lst.push_front(x);
			n++;
			temp1 = sum[1];
			sum[1] = x;
			for(i = 2; i <= n; i++)
			{
				temp2 = sum[i];
				sum[i] = temp1 + x;
				temp1 = temp2;
			}
			/*for(i = 1; i <= n; i++)
			{
				printf("%lld ",sum[i]);
			}
			printf("\n");*/
		}
	}
}