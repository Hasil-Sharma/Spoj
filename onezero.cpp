#include <stdio.h>
int checking(long long int n)
{
	long long int i = 10;
	while(n)
	{
		if((n%10 == 0 || n%10 == 1))
				n = n/i;
		else
			return 0;
	}
	return 1;
}
int main()
{
	long long int t,n,ans,flag,i;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		flag = checking(n);
		if(flag == 1) printf("%lld\n",n);
		else
		{
			for(i = 2; i > 0; i++)
			{
				ans = n*i;
				flag = checking(ans);
				if(flag == 1) 
				{
					printf("%lld\n",ans);
					break;
				}
			}
		}
	}

}