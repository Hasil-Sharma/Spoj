#include<stdio.h>
void get_input(int n,int m);
int get_count(char *s);
int main()
{
	int t,n,m,k,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d %d\n",&n,&m,&k);
		get_input(n,m);
		
	}
	return 0;
}

void get_input(int n,int m)
{
	char state[m+1];
	int i = 0,list[n];
	while(i < n)
	{
		gets(state);
		list[i] = get_count(state);
		i++;
	}
}

int get_count(char *s)
{
	int i = 0,j = strlen(s),count = 0;
	while(i < j)
	{
		if (s[i] == '*') count++;
		i++;
	}
	return count;
}
