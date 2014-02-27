#include<stdio.h>
static long long int array[1000001];
using namespace std;
long long int max(long long int n, int i)
{
	if(n < i) return i;
	else return n;
}
long long int getanswer(int n)
{
	if(n <= 1000000)
	{
		if(array[n]) return array[n];
		else if( n/2 + n/3 + n/4 <= n) 
		{
			array[n] = n;
			return n;
		}
		else 
		{
			array[n] = getanswer(n/2) + getanswer(n/3) + getanswer(n/4);
			return array[n];
		}
	}
	else return max(getanswer(n/2) + getanswer(n/3) + getanswer(n/4),n);
	

}
int main()
{
	int n;
	long long int ans;
	array[0] = 0;
	array[1] = 1;
	array[2] = 2;
	while(scanf("%d",&n) != EOF)
	{
		ans = getanswer(n);
		printf("%lld\n",ans);
	}	
	return 0;
}

