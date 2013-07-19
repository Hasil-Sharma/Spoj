#include<stdio.h>
int main()
{
	long int n,k,t,f,T,i;
	i = 0;
	scanf("%ld",&T);
	while(i < T)
	{
		scanf("%ld %ld %ld %ld",&n,&k,&t,&f);
		printf("%ld\n",n + k*(f-n)/(k-1));
		i ++;
	}
	return 0;
}