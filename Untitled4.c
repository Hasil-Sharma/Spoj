#include<stdio.h>
int fact( int n);
int main()
{
	int i,ans;
	scanf("%d",&i);
	ans = fact(i);
	printf("%d\n",ans);
}
int fact(int n)
{
	if (n == 0 || n == 1) return 1;
	else return n*fact(n-1);
}