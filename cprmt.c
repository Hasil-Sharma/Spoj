#include<stdio.h>
int main()
{
	char a[1001],b[1001],ans[1001],temp;
	int i,j,k;
	while(scanf("%s\n%s",a,b) != EOF)
	{
		k = 0;
		for(i = 0; i < strlen(a);i++)
		{
			temp = a[i];
			for(j = 0 ; j < strlen(b);j++)
			{
				if(b[j] == temp)
				{
					ans[k] = temp;
					k++;
					b[j] = '$';
					break;	
				}
					
			}	
		}
		for(i = 0; i < k; i++)
			for(j = k - 1; j > i; j--)
			{
				temp = ans[j-1];
				ans[j-1] = ans[j]; 
				ans[j] = temp;
			}
		for(i = 0 ; i < k; i++)
			printf("%c",ans[i]);
			printf("\n");	
	}
	return 0;
}