#include <cstdio>
int main()
{
	int n, arr1[1000000],i,count1,count2,arr2[1000000],flag = 1;
	scanf("%d",&n);
	for(i = 0; i < n; i++)
	{
		scanf("%d",&arr1[i]);
		arr2[i] = arr1[i];
	}
	for(i = 1,count1 =0; i < n; i++)
	{
		if(arr1[i] <= arr1[i-1])
		{
			count1++;
			arr1[i] = arr1[i-1]+1;
		}
		
	}
	for(i = 0; i < n; i++)
		printf("%d ",arr1[i]);
	printf("\n");
	for(i = n-1,count2 = 0; i > 0; i--)
	{
		if(arr2[i] <= arr2[i-1])
		{
			count2++;
			arr2[i-1] = arr2[i]-1;
			if(arr2[i-1] == 0)
			{
				flag = 0;
				printf("%d\n",count1);
				break;
			}
		}
	}
	for(i = 0; i < n; i++)
		printf("%d ",arr2[i]);
	printf("\n");
	if(count1 > count2 && flag) printf("%d\n",count2);
	else if(flag) printf("%d\n",count1);
	return 0;
}