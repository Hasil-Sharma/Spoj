/*
Keep  all the Load = 1 on the front as Load^Input = Ouput
if only terms apart from 1 are 2 & 3 then ans is 2 3
else for rest sort in descending order.
*/

#include <cstdio>
#include <algorithms>

int main()
{
	int t,n,array[100000];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i = 0; i < n; i++)
		{
			scanf("%d",&array[i]);
		}
		sort(array,array+n);

		for(int i = 0; i < n; i++)
		{
			printf("%d ",array[i]);
		}
		printf("\n");
	}
	return 0;
}