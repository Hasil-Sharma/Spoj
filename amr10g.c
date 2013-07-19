#include<stdio.h>
#include<stdlib.h>
int main()
{
	int t,k,n,i;
 	int height[20000];
	
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&k,&n);
		for(i = 0; i < n; i++) scanf("%d",&height[i]);
		for(i = 0; i < n; i++) printf("%d\n",height[i]);
	}
	return 0;
}