#include<stdio.h>
using namespace std;
void find_max(int *arr, int *start, int *end, int *ans)
{
	int i;
	*ans = 0;
	for(i = (*start);i < (*end);i++)
		if (*(arr+i) > *ans) *ans = (*(arr+i));
}
int main()
{
	int n,k,i=0,num,j,array[1000000];
	scanf("%d",&n);
	getchar();
	while(i<n && (scanf("%d",(array+i)))==1)
		i++;
	scanf("%d",&k);
	for(i=0;i <= n-k;i++)
	{
		j = i+k;
		find_max(array,&i,&j,&num);
		if (i==0) printf("%d",num);
		else printf(" %d",num);
		printf("\n");
	}
	return 0;
}
