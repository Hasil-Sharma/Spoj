#include <stdio.h>
void merge_sort(int *arr, int p, int r);
void merge(int *arr, int p, int q, int r);
int count;
void merge_sort(int *arr, int p, int r)
{
	int q;
	if(p < r)
	{
		q = (p+r)/2;
		merge_sort(arr,p,q);
		merge_sort(arr,q+1,r);
		merge(arr,p,q,r);
	}
}

void merge(int *arr, int p, int q, int r)
{
	int n1=q-p+1, n2=r-q, i, j, k;
	int L[n1+1],R[n2+1];
	for(i=0;i<n1;i++)
		L[i] = arr[p+i];
	for(i=0;i<n2;i++)
		R[i] = arr[q+i+1];
	L[n1] = 1000001;
	R[n2] = 1000001;
	for(i=0,j=0,k=p;k <= r;k++)
	{
		if(L[i] < R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
	}
	
}

int main()
{
	int t,n,i, array[100001];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		count = 0;
		for(i = 1; i <= n; i++)
			scanf("%d",&array[i]);
		merge_sort(array,1,n);
		for(i = 1; i <= n; i++)
			printf("%d ",array[i]);
		printf("\n");
		printf("%d\n",count);
	}
}