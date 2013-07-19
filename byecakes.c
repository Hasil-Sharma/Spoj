#include<stdio.h>
int main()
{
	int e,f,s,m,ed,fd,sd,md;
	int x,y,z,w;
	scanf("%d %d %d %d %d %d %d %d",&e,&f,&s,&m,&ed,&fd,&sd,&md);
	while (e != -1)
	{
		x = 0;
		for(;1 == 1;x++)
		{
			if ((e+x)%ed == 0)
				y = fd*(e+x)/ed - f;
				z = sd*(e+x)/ed - s;
				w = md*(e+x)/ed - m;
				if(x>=0 && y >=0 && w>=0 && z>=0)
					break;
		}
		printf("%d %d %d %d\n",x,y,z,w);
		scanf("%d %d %d %d %d %d %d %d",&e,&f,&s,&m,&ed,&fd,&sd,&md);
	}
	return 0;
}