#include<stdio.h>
int main()
{
	int t,n,flag,array[] = {3, 5, 17, 257, 65537},temp;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		temp = n;
		while(n % 2 == 0)
		{
			n = n/2;
		}
		for(int i = 0; i < 5; i++)
		{
			if(n % array[i] == 0)
			{
					n = n/array[i];
			}
		}
		if (n == 1) printf("Yes\n");
		else printf("No\n");
	}
}