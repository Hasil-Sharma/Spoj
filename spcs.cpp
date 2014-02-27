#include <cstdio>
#include <cstring>
bool check(char *str)
{
	int i = 0; j = strlen(str) - 1;
	while(i < j)
	{
		if(str[i] == str[j])
		{
			i++;
			j--;
		}
		else return false;
	}
	return true;
}
int main()
{
	int t,len,i,k;
	char str[100005],ans[100005];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",str);
		len = strlen(str);
		for(i = 1,k = 1,ans[0] = str[0]; i < len; i++)
		{
			if(str[i] != str[i-1]) ans[k++] = str[i];
		}
		ans[k] = '\0';
		if(check(ans)) printf("YES");
		else  printf("NO");
	}
}