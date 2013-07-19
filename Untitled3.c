#include<stdio.h>
int main()
{
	char name;
	name = ' ';
	while(name != '\n')
	{
		name = getchar();
		printf("%c\n",name);
	}
}