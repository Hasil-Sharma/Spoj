#include<stdio.h>
#include<algorithm>
using namespace std;
static int array[1100001];
static int tempa[1000003];
int main()
{
	int mod = 100000,t,a,b,i,index  = 1,count,j;
	array[0] = -1;
	array[1] = 0;
	array[2] = 1; 
	for(i = 3; i < 1100001; i++)
	{
		array[i] = (array[i-1]%mod + array[i-2]%mod)%mod;
	}
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&a,&b);
		count = 0;
		for(i = a,j = 0; i < a + b + 1; i++)
			tempa[j++] = array[i];
		sort(tempa, tempa+j);
		printf("Case %d:",index);
		for(i = 0; i < j;i++)
		{
			printf(" %d",tempa[i]);
			count++;
			if(count == 100) break;
		}
		printf("\n");
		index ++;
	}

}