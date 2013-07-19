#include<stdio.h>
#include<math.h>
int main()
{
	long long int at,alt,s,a,b,c,n,d,j;
	long double ans;
	int t,i=0;
	scanf("%d",&t);
	while(i < t)
	{
		i += 1;
		scanf("%lld %lld %lld",&at,&alt,&s);
		ans = 2.5 + (at*1.0 + s)/(at+alt) + sqrtl((2.5 + (at*1.0 + s)/(at+alt))*(2.5 + (at*1.0 + s)/(at+alt)) - 12.0*s/(at + alt));
			n = llrintl(ans);
			d = (alt - at)/(n - 6);
			a = at - 2*d;
			printf("%lld\n",n);
			for(j=0;j < n-1;j++)
			{
				printf("%lld ",a);	
				a += d;
			}
			printf("%lld\n",a);
	}
	return 0;
}