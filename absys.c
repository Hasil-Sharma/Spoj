#include<stdio.h>
#include<string.h>
#include<conio.h>
int main()
{
	int t,i=0;
	char space,string[30];
	scanf("%d",&t);
	while (i < t)
	{
		i++;
		gets(string);
		puts(string);
	}
	return 0;
}