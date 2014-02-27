#include<stdio.h>
#include<math.h>
using namespace std;
int main()
{
	long long int n,i;
	int exponent,flag,limit;
	while(1)
	{
		scanf("%lld",&n);
		if(!n) break;
		limit = sqrt(n);
		for(i = 2; i <= limit;i++)
		{
			flag = 0;
			exponent = 0;
			while(n%i == 0)
			{
				exponent++;
				n /= i;
				flag = 1;
				limit = sqrt(n);
			}
			if(flag) printf("%lld^%d ",i,exponent);
		}
		if(n != 1) printf("%lld^1",n);
		printf("\n");
	}
	return 0;
}
