#include<stdio.h>
int main()
{
	int t,n,array[5] = {3, 5, 17, 257, 65537},i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		while(n%2 == 0)
		{
			n /= 2;
		}
		for(i = 0; i < 5; i++)
		{
			if(n % (*(array+i)) == 0)
			{
					n /= (*(array+i));
			}
		}
		if (n == 1) printf("Yes\n");
		else printf("No\n");
	}
}