#include<stdio.h>
using namespace std;
int getanswer(int n)
{
	if(n == 1 || n == 2) return n;
	else if( n/2 + n/3 + n/4 <= n) return n;
	else return getanswer(n/2) + getanswer(n/3) + getanswer(n/4);

}
int main()
{
	int n;
	long long int ans;
	while(scanf("%d",&n) != EOF)
	{
		ans = getanswer(n);
		printf("%lld\n",ans);
	}	
	return 0;
}

