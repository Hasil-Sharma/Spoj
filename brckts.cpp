#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
int getMid(int a,int b)
{
	return a + (b-a)/2;
}
void updateValue(int *st, int ss, int se, int i, int diff, int index)
{
    // Base Case: If the input index lies outside the range of this segment
    if (i < ss || i > se)
        return;
 
    // If the input index is in range of this node, then update the value
    // of the node and its children
    st[index] = st[index] + diff;
    if (se != ss)
    {
        int mid = getMid(ss, se);
        updateValue(st, ss, mid, i, diff, 2*index + 1);
        updateValue(st, mid+1, se, i, diff, 2*index + 2);
    }
}
void update(int arr[],int *st,int n, int i)
{
	int diff;
	if(arr[i] == 1) diff = -2;
	else diff = 2;
	arr[i] *= -1;
	updateValue(st,0,n-1,i,diff,0);
}
int constructSTUtil(int arr[], int ss, int se, int *st,int si)
{
	if(ss == se)
	{
		st[si] = arr[ss];
		return arr[ss];
	}
	int mid = getMid(ss,se);
	st[si] = constructSTUtil(arr,ss,mid,st,si*2+1) + constructSTUtil(arr,mid+1,se,st,si*2+2);
	return st[si];
}
int* constructST(int arr[],int n)
{
	int x = (int)(ceil(log2(n)));
	int max_size = 2*(int)pow(2,x) - 1;
	int *st = new int[max_size];

	constructSTUtil(arr,0,n-1,st,0);
	return st;
}
int main()
{
	int t = 10,n,index = 1,m,k,i;
	int *string;
	char *c;
	while(t--)
	{
		i = 0;
		scanf("%d",&n);
		string = (int*)(malloc(n*sizeof(int)));
		c = (char*)(malloc(n*sizeof(char)));
		scanf("%s",c);
		while(i < n)
		{
			if(c[i] == '(') string[i] = 1;
			else string[i] = -1;
			i++;
		}
		int *st = constructST(string,n);
		scanf("%d",&k);
		printf("Test %d:\n",index++);
		while(k--)
		{
			scanf("%d",&m);
			if(m == 0)
			{
				if(n == 1) printf("NO\n");
				else if(string[0] == 1 && string[n-1] == -1) 
				{
					if(st[0] == 0) printf("YES\n");
					else printf("NO\n");
				}
				else printf("NO\n");
			}
			else update(string,st,n,m-1);
		}
	}
}