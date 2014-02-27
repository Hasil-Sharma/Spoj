#include<stdio.h>
using namespace std;
int main()
{
	int t,exponent,ans,index = 1,flag = 0,flag2 = 0;
	long long int n,i;
	scanf("%d",&t);
	while(t--)
	{
		ans = 1;
		scanf("%lld",&n);
		for(i = 2;i*i <= n;i++)
		{
			exponent = 0;
			flag = 0;
			while(n%i == 0)
			{
				exponent++;
				n /= i;
				flag = 1;
			}
			if(flag && (exponent%2 == 1)) 
			{
				flag2 = 1;
				break;
			}
			
			ans *= (exponent + 1);
		}
		if(n != 1) ans *=2;
		printf("Case %d: ",index);
		index++;
		if(flag2)
		{
			printf("No\n");
			continue;
		}
		if(ans%2) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
