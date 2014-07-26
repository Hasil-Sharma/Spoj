#include <stdio.h>
#include <string.h>
#define ll long long

int main()
{
	ll ans;
	int t,count,len,i;
	int array[30];
	char str[30],c,temp;
	array[0] = 1ll;
	for(i = 1; i < 30; i++)
		array[i] = 2*array[i-1];
	scanf("%d",&t);
	while(t--)
	{
		ans = 1ll;
		scanf("%s",str);
		c = str[0];
		count = 1;
		len = strlen(str);
		for(i = 1; i < len; i++)
		{

			if(c == str[i]) count++;
			else
			{
				c = str[i];
				ans *= array[count-1];
				count = 1;
			}
		}
		ans *= array[count-1];
		printf("%lld\n",ans);
	}
	return 0;
}
