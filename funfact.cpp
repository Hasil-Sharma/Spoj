#include<stdio.h>
int main()
{
	unsigned long long int t,x,cur = 1,prev = 1,i;
	for(i = 2; i < 50; i++)
	{
		cur = prev*i;
		printf("%llu :%llu\n",i,cur);
		prev = cur; 
	}
	return 0;
}