#include <stdio.h>

int main()
{
	long long int n,i,j,array[10],ans;
	for(i = 0; i < 10; i++)
		array[i] = i*i;
	while(scanf("%lld",&n)!= EOF)
	{
		i = n/9;
		j = n%9;
		ans = i*array[9] + array[j];
		printf("%lld\n",ans); 
	}
}