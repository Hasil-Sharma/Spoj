#include<stdio.h>
long int gcd(long int u,long int v);
int main()
{
	long int k,g,q,n,m,i,count;
	scanf("%ld",&q);
	i = 0;
	while(i < q)
	{
		count = 0;
		scanf("%ld %ld",&n,&m);
		for(k = 1; k <= m;k++)
		{
			g = gcd(n,k);
			if (g==1)
				count++;
		}
		printf ("%ld\n",count);
		i++;
	}
	return 0;
}

/*long int gcd(long int a,long int b){
	if (a%b==0)
		return b;
	else
		return gcd(b,a%b);
}*/
long int gcd(long int u, long int v)
{
    // simple cases (termination)
    if (u == v)
        return u;
 
    if (u == 0)
        return v;
 
    if (v == 0)
        return u;
 
    // look for factors of 2
    if (~u & 1) // u is even
    {
        if (v & 1) // v is odd
            return gcd(u >> 1, v);
        else // both u and v are even
            return gcd(u >> 1, v >> 1) << 1;
    }
 
    if (~v & 1) // u is odd, v is even
        return gcd(u, v >> 1);
 
    // reduce larger argument
    if (u > v)
        return gcd((u - v) >> 1, v);
 
    return gcd((v - u) >> 1, u);
}