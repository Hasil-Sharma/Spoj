#include<stdio.h>
int main(){
	int t,i,a,b,j;
	char c;
	scanf("%d",&t);
	i = 0;
	while (i < t)
	{
		i++;
		scanf("%c",&c);
		scanf("%d %d",&a,&b);
		char gs[3*a],ms[3*b];
		printf("%s\n",gets(gs));
		printf("%s\n",gets(ms));
	}
	return 0;
}