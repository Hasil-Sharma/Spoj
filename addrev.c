#include<stdio.h>
int reverse_int(int integer);
int main()
{
	int a,b,t,i=0,ans;
	scanf("%d",&t);
	while (i < t)
	{
		i++;
		scanf("%d %d",&a,&b);
		ans = reverse_int(reverse_int(a)+ reverse_int(b));
		printf("%d\n",ans);
	}
	return 0;
}
int reverse_int(int integer)
{
	int ans = 0;
	while (integer > 0)
	{
		ans = ans*10 + (integer%10);
		integer = integer/10;
	}
	return ans;
}