#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	while(n != 0)
	{
		printf("%d\n",(n+1)*(3*n+2)/2);
		scanf("%d",&n);
	}
	return 0;
}