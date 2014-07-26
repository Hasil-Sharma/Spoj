#include<stdio.h>
int gcd(int a, int b)
{
	if(b == 0) return a;
	else return gcd(b,a%b);

}
int main()
{
	int e,f,s,m,ed,fd,sd,md;
	int x,y,z,w;
	scanf("%d %d %d %d %d %d %d %d",&e,&f,&s,&m,&ed,&fd,&sd,&md);
	while (e != -1)
	{
		int x_y,x_w,x_z,flag;
		flag = 1;
		printf("Here1\n");
		for(int i = e; i <= 1000 && flag; i++)
		{
			for(int j = f; j <= 1000 && flag; j++)
				if(i*fd == ed*j)
				{
					x_y = i;
					y = j;
					flag = 0;
				}
		}

		printf("Here2\n");
		flag = 1;
		for(int i = e; i <= 1000 && flag; i++)
		{
			for(int j = m; j <= 1000 && flag; j++)
				if(i*md == ed*j)
				{
					x_w = i;
					w = j;
					flag = 0;
				}
		}
		flag = 1;
		for(int i = e; i <= 1000 && flag; i++)
		{
			for(int j = s; j <= 1000 && flag; j++)
				if(i*sd == j*ed)
				{
					x_z = i;
					z = j;
					flag = 0;
				}
		}
		printf("%d %d %d\n",x_y,x_z,x_w);
		printf("%d %d %d\n",y,z,w);
		x = (x_y*x_w*x_z)/gcd(x_y,gcd(x_w,x_z));
		y = y*x/x_y;
		z = z*x/x_z;
		w = w*x/x_w;

		printf("%d %d %d %d\n",x,y,z,w);
		scanf("%d %d %d %d %d %d %d %d",&e,&f,&s,&m,&ed,&fd,&sd,&md);
	}
	return 0;
}
