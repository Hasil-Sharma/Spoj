#include<stdio.h>
#include<math.h>
using namespace std;
int main()
{
	int t,flag;
	long long int n,num,i,temp;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld",&n);
		for(i = 0,flag = 0; i*i < n && flag == 0; i++)
		{
			num = n - i*i;
			temp = (long long int)sqrt(num);
			if(temp*temp == num) flag = 1;
		}
		if(flag) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
