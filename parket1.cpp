#include <stdio.h>
int main()
{
	int r,b,sum,x,y;
	scanf("%d%d",&r,&b);
	sum = r+b;
	for(x = 2; x > 0; x++)
	{
		if(sum%x == 0)
		{
			y = sum/x;
			break;
		}
	}
	if(x>y) printf("%d %d\n",x,y);
	else printf("%d %d\n",y,x);
}