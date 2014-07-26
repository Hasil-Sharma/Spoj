#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <climits>
#define e printf("Here\n")
#define pint(num) printf("%d\n",num);
using namespace std;
int maxVal(int x,int y){ return (x > y)? x: y; }

int RMQUtil(int *st, int ss, int se, int qs, int qe, int index)
{
	if(qs <= ss && qe >= se)
		return st[index];
	if (se < qs || ss > qe)
        return INT_MIN;
	int mid = ss + (se-ss)/2;
    return maxVal(RMQUtil(st, ss, mid, qs, qe, 2*index+1),
                  RMQUtil(st, mid+1, se, qs, qe, 2*index+2));
}
int constructSTUtil(int *arr, int ss, int se, int *st, int si)
{
	if(ss==se)
	{
		st[si] = arr[ss];
		return arr[ss];
	}
	int mid  = ss + (se-ss)/2;;
	st[si] = maxVal(constructSTUtil(arr,ss,mid,st,si*2+1),
		constructSTUtil(arr,mid+1,se,st,si*2+2));
	return st[si];
}

int* construcSt(int *arr, int n)
{
	int x = (int)(ceil(log2(n)));
	int max_size = 2*(int)pow(2,x) - 1;
	int *st = new int[max_size];
	constructSTUtil(arr,0,n-1,st,0);
	return st;
}

int main()
{
	int n,k,i=0,num,j,array[1000000],start,end;
	scanf("%d",&n);
	while(i<n && (scanf("%d",(array+i)))==1)
		i++;
	scanf("%d",&k);
	int *st = construcSt(array,n);
	start = 0;
	end = k-1;
	while(end < n)
	{	
		printf("%d ",RMQUtil(st,0,n-1,start,end,0));
		start++;
		end++;
	}
	printf("\n");
	return 0;
}

