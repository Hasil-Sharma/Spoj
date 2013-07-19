#include<stdio.h>
#include<math.h>
int main()
{
	int n,k,c;
	unsigned long long int ans;
	char points[101],coff[1000];
	printf("input n:");
	scanf("%d",&n);
	while(n != -1)
	{
		printf("input coff:");
		gets(coff);
		scanf("%d",&k);
		printf("input points:");
		gets(points);
		puts(n);
		puts(coff);
		puts(points);
		scanf("%d",&n);
	}
	return 0;
}