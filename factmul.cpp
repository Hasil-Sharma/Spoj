#include<stdio.h>
int main()
{
	int n,i;
	long long int prev,cur,ans;
	long long int c = 109546051211ll;
	ans = 1;
	prev = 1;;
	scanf("%d",&n);
	for(i = 2; i <= n; i++)
	{
		cur = (prev*i)%c;
		ans = ((ans%c)*cur)%c;
		if(ans == 0) break;
		prev = cur; 
	}
	printf("%lld\n",ans);
	return 0;
}

