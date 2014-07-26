#include <stdio.h>
int main()
{
	int n,c,i,count,flag,found,j,max;
	c = 1;
	while(scanf("%d",&n) != EOF)
	{
		int array[n];
		for(i = 0; i < n; i++)
			scanf("%d",&array[i]);
		count = (array[0]) ? 1: 0;
		max = array[0];
		for(i = 1; i < n; i++)
		{
			flag = 0;
			found = 1;
			if(array[i] == 0) continue;
			for(j = i -1; j >= 0 && !flag; j--)
			{
				if(array[j] < array[i])
				{
					flag = 1;
					found = 0;
				}
				else if(array[j] == array[i])
				{
					found = 0;
					flag = 0;
					break;
				}
			}
			count += flag + found;
		}
		printf("Case %d: %d\n",c,count);
		c++;
	}
}
