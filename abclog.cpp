#include<stdio.h>
using namespace std;
static int array[60];
static long long int val[60];
int main()
{
	int t,i,j;
	long long int n;
	long long int ans;
	val[0] = 1;
	for(i = 1;i < 60; i++)
	{
		val[i] = val[i-1]*2;
	}
	while(true)
	{	
		ans = 0;
		i = 1;
		scanf("%lld",&n);
		if(n == -1) break;
		while(n)
		{
			array[i++] = n%2;
			n = n >> 1;
		}
		//printf("i : %d\n",i);
		for(j = 1; j < i;j++)
		{
			//printf("%d*%d\n",array[j],val[i-j-1]);
			ans += array[j]*val[i-j-1];
		}
		printf("%lld\n",ans);
	}
}
