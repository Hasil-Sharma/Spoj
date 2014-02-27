#include <cstdio>
using namespace std;
int check(char *string,int n)
{
	int i = 0,num = 0;
	for(; i < n; i++)
	{
		if(string[i] == 40) num++;
		else if(string[i] == 41) num--;
	}
	if(num == 0) return 1;
	else return 0; 
}
int main()
{
	int i = 1,n,m,k,flag;
	char string[30000];
	while(i <= 10)
	{
		scanf("%d",&n);
		scanf("%s",string);
		scanf("%d",&m);
		printf("Test %d:\n",i++);
		while(m--)
		{
			scanf("%d",&k);
			if(k == 0)
			{
				flag = check(string,n);
				if(flag) printf("YES\n");
				else printf("NO\n");
			}
			else
			{
				k--;
				if(string[k] == 40) string[k] = 41;
				else string[k] = 40;
			}
		}
	}
	return 0;
}