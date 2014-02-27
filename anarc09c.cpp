#include<stdio.h>
using namespace std;
static int afact[1000004];
static int bfact[1000004];
static int count;
int abs(int a)
{
	return (a>=0) ? a : -1*a;
}
int max(int a, int b)
{
	return (a > b) ? a : b;
}
void getfactor(int a, int *fact)
{
	int flag = 0;
	for(int i = 2; i*i <= a; i++)
		{
			while(a%i == 0)
			{
				fact[i]++;
				a = a/i;
				flag = 1;
			}
			//if(flag) printf("%d\n",i);
		}
		if (a != 1)
		{
			fact[a]++;
		}
}
int main()
{
	int a,b,index = 1,c,dist;
	scanf("%d%d",&a,&b);
	while(a != 0 && b != 0)
	{
		count = 0;
		dist = 0;
		c = max(a,b);
		for(int i = 1; i <= c; i++)
		{
			afact[i] = 0;
			bfact[i] = 0;
 		}
		getfactor(a,afact);
		getfactor(b,bfact);
		
		for(int i = 2; i <= c; i++)
		{
			if(afact[i] || bfact[i]) 
			{
				//printf("%d ",i );
				dist += abs(afact[i] - bfact[i]);
				count++;
			}
		}
		printf("%d. %d:%d\n",index,count,dist);
		scanf("%d%d",&a,&b);
		index++;
	}
}