#include<stdio.h>
#include<string.h>
using namespace std;
int main()
{
	int i,len,count;
	char string[100001],temp;
	while(scanf("%s",string) != EOF)
	{
		len = strlen(string);
		if(len == 3)
		{
			printf("%s\n",string);
			continue;
		}
		temp = string[0];
		count = 1;
		for(i = 1; i <= len; i++)
		{
			if(temp == string[i])
			{
				//printf("%c\n",temp);
				count++;
			}
			else if(temp != string[i])
			{
				if(count > 3) printf("%d!%c",count,temp);
				else
				{
					for(int j = 1; j <= count; j++)
						printf("%c",temp);
				}
				count = 1;
				temp = string[i];
			}
		}

		printf("\n");
	}
}