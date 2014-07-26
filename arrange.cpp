/*
Keep  all the Load = 1 on the front as Load^Input = Ouput
if only terms apart from 1 are 2 & 3 then ans is 2 3
else for rest sort in descending order.
*/

#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
	int t,n,array[100000],i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i = 0; i < n; i++)
		{
			scanf("%d",&array[i]);
		}
		sort(array,array+n);

		for(i = 0; array[i] == 1; i++)
		{
			printf("%d ",array[i]);
		}
		if(i == n) continue;
		if(array[i] == 2 && array[i+1] == 3 && (i+2 == n))
		{
			printf("2 3\n");
			continue;
		}
		else
		{
			for(int j = n-1; j > i; j--)
				printf("%d ",array[j]);
		}
		printf("%d\n",array[i]);
	}
	return 0;
}