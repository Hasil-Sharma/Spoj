#include<stdio.h>
#include<algorithm>
using namespace std;
static int sqr[1001];
int main()
{
	int t,a,ans;
	for(int i = 0;i*i <= 1000; i++)
		sqr[i*i] = 1;
	
	for(int i = 1; i <= 1000; i++)
	{
		if(!sqr[i])
		{
			sqr[i] = 50;
			for(int j = 1; j <= i; j++)
			{
				sqr[i] = min(sqr[i], sqr[j] + sqr[i-j]); 
			}
		}
	}
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&a);
		printf("%d\n",sqr[a]);
	}
	return 0;
}
