#include<stdio.h>
#include<strings.h>
static int array[26];
int main()
{
	int n,flag = 1;
	char c,str[31];
	scanf("%d",&n);
	while(n--)
	{
		gets(str);
		array[str[0]%97]++;
		
	}
	for(int i = 0; i < 26;i++)
	{
		if(array[i] >= 5)
		{
			printf("%c",i+97 );
			flag = 0;
		}
	}
	if(flag) printf("PREDAJA");
	return 0;
}