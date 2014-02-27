#include<stdio.h>
using namespace std;
int get(int a)
{
	int i,num = 0,count = 0,onum = a;
	for(i = 2;i*i <= a;i++)
	{
		if( a%i == 0)
		{
			num += i;
			while(a%i == 0) a = a/i;
		}
	}
	if(a != 1) num += a;
	if(num == onum) return 0;
	return num;
}
int main()
{
	int p,a,b,k,count,num,tot;
	scanf("%d",&p);
	while(p--)
	{
		scanf("%d%d%d",&a,&b,&k);
		tot = 0;
		while(a<=b)
		{
			num = a;
			count = 0;
			//printf("Starting from :%d\n",num );
			while(true)
			{
				num = get(num);
				//printf("\t\t Got: %d\n",num);
				count++;
				if(count == k || num == 0) break;
			}
			if(count == k && num == 0) tot++;
			a++;
		}
		printf("%d\n",tot);
	}
	//printf("%d\n",get(4));
}