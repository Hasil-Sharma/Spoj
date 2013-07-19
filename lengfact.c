#include<stdio.h>
#include<math.h>
int main()
{
	int t,i=0;
	long int n,ans;
	long double pi= 3.14159265358979323,e =2.71828182845904523536;
 	scanf("%ld",&t);
 	while(i < t)
 	{
	 	ans = floor( (logbl(2*pi*n)/2 + n*(logbl(n)-1) )/logbl(10)) + 1;
	 	printf("%d\n",ans);
	 }
	return 0;
}
