#include <stdio.h>
#include <string.h>
int main()
{
	int t,index=1,flag;
	char string[120005];
	char* found;
	char find[] = "100";
	scanf("%d",&t);
	while(t--)
	{

		scanf("%s",string);
		flag = 0;
		int len = strlen(string);
		if(len % 3 != 0) flag = 1;
		if(!flag && (string[0] != '1' || string[len-1] != '0'))
			flag = 1;
		while(*string != '\0' && *string != '\n' && !flag)
		{
			//printf("%s\n",string);
			found = strstr(string,find);
			if(found)
			{
				strcpy(found,found+3);
			}
			else
			{
				flag = 1;
				break;
			}

		}
		printf("Case %d: ",index);
		index++;
		if(flag) printf("no\n");
		else printf("yes\n");
	}
	return 0;
}
