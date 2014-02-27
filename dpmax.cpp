#include<stdio.h>
static long long int c = 109546051211ll;
long long mulmod(long long a,long long b){
    long long x = 0,y=a%c;
    while(b > 0){
        if(b%2 == 1){
            x = (x+y)%c;
        }
        y = (y << 1)%c;
        b /= 2;
    }
    return x%c;
}
int main()
{
	int n,i;
	long long prev,cur,ans;
	ans = 1;
	prev = 1;;
	scanf("%d",&n);
	for(i = 2; i <= n; i++)
	{
		cur = mulmod(prev,i);
		ans = mulmod(ans,cur);
		if(ans == 0) break;
		prev = cur; 
	}
	printf("%lld\n",ans);
	return 0;
}