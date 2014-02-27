#include <stdio.h>
void swap(int *a, int *b)
{
	int temp;
	temp = (*a);
	(*a) = (*b);
	(*b) = temp;
}
int getnext(int n, int *array)
{
	int k = -1,l,i,j;
	for(i = 0; i < n-1; i++)
	{
		if(*(array+i) < *(array+i+1))
			k = i;
	}
	if(k == -1) return k;
	for(i = 0; i < n; i++)
	{
		if(*(array+i) > *(array+k))
			l = i;
	}
	swap(array+k,array+l);
	for(i = 0; i < k+1; i++)
		printf("%d",array[i]);
	for(i = n-1; i >= (k+1); i--)
		printf("%d",array[i]);
	printf("\n");
}
int main()
{
	int t,n,array[1000000],flag,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for ( i = 0; i < n; ++i)
		{
			scanf("%d",array+i);
		}
		flag = getnext(n,array);
		if(flag == -1) printf("-1\n");
	}
}