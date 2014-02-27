#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	int n,k,array[1000000],i,count = 0;
	bool found;
	scanf("%d%d",&n,&k);
	for(i = 0; i < n; i++)
		scanf("%d",&array[i]);
	sort(array,array+n);
	for(i = 0; i < n; i++)
	{
		found = binary_search(array+i,array+n,array[i] + k);
		if(found) count++;
	}
	printf("%d\n",count);
}