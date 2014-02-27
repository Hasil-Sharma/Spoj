#include <cstdio>
#include <climits>
int getmin (int *array, int index, int n)
{
	int i,arr[n-1],smoke;
	for(int i = 0; i < index;i++)
		arr[i] = array[i];
	smoke = array[index]*array[index+1];
	arr[index] = (array[index] + array[index+1])%100;
}
int main()
{
	int t,n,array[101],tans,ans;
	scanf("%d",&t);
	while(scanf("%d",&n) != EOF)
	{
		for(int i = 0; i < n; i++)
			scanf("%d",&array[i]);
		ans = INT_MAX;
		for(int i = 0; i < n-1; i+=2)
		{
			tans = getmin(array,i,n);
		}
	}
}