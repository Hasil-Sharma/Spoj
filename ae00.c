#include<stdio.h>
int solution(int n, int i,int temp);
int main()
{
	int n,i=1,ans;
	scanf("%d",&n);
	ans = solution(n,i+1,n/i - i + 1);
	printf("%d",ans);
	return 0;
}
int solution(int n , int i , int temp)
{
	if (temp >=0) return temp + solution(n,i+1,n/i - i + 1);
	else return 0;
}