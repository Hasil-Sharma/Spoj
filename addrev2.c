#include<stdio.h>
void reverse_int(int *integer);
int main()
{
	int *a,*b,t,i=0,*ans;
	scanf("%d",&t);
	while (i < t)
	{
		i++;
		scanf("%d %d",a,b);
		reverse_int(a);
		reverse_int(b);
		*ans = (*a) + (*b);
		reverse_int(ans);
		printf("%d\n",*ans);
	}
	return 0;
}
void reverse_int(int *integer)
{
	int ans = 0,temp = *integer;
	while (temp > 0)
	{
		ans = ans*10 + (temp%10);
		temp = temp/10;
	}
	*integer = ans;
}