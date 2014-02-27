#include<stdio.h>
static int count;
static int data[3];
using namespace std;
void combinationUtil(int *arr,int start,int end,int index,int r)
{
	if(index == 3)
	{
		int a,b,c;
		a = data[0];
		b = data[1];
		c = data[2];
		if((a+b < c) || (b+c < a) || (c+a < b)) 
			{
				//printf("%d %d %d\n",a,b,c);
				count++;
			}
		return;
	}
	for(int i = start; i <= end && end-i+1 >= r-index; i++)
	{
		data[index] = arr[i];
		combinationUtil(arr,i+1,end,index+1,r);
	}
}
void printCombination(int *arr, int n,int r)
{
	combinationUtil(arr,0,n-1,0,r);
}
int  main()
{
	int n,l[2001],a,b,c;
	while(1)
	{
		scanf("%d",&n);
		if(!n) break;
		for(int i = 0; i < n; i++) scanf("%d",&l[i]);
		count = 0;
		printCombination(l,n,3);
		printf("%d\n",count);
	}
	return 0;
}