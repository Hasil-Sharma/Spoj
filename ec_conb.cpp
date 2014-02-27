#include<stdio.h>
using namespace std;
static int array[40];
static int val[25];
int main()
{
	int t,n,i,j,ans;
	scanf("%d",&t);
	val[0] = 1;
	for(i = 1;i < 25; i++)
	{
		val[i] = val[i-1]*2;
	}
	while(t--)
	{	
		ans = 0;
		i = 1;
		scanf("%d",&n);
		if(n&1)
		{
			printf("%d\n",n);
			continue;
		}
		while(n)
		{
			array[i++] = n&1;
			n = n >> 1;
		}
		//printf("i : %d\n",i);
		for(j = 1; j < i;j++)
		{
			//printf("%d*%d\n",array[j],val[i-j-1]);
			ans += array[j]*val[i-j-1];
		}
		printf("%d\n",ans);
	}
}
