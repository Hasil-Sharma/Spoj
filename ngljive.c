#include<stdio.h>
int main()
{
	int *s,i,ans,*temp;
	i = 0;
	ans = 0;
	while (*i < 10)
	{
		*i++;
		scanf("%d",s);
		*temp = *ans;
		*ans += *s;
		if (100 > *ans)
			continue;
		else if (*ans == 100)
			break;
		else if ((*ans - 100) == (100 - *temp))
			break;
		else if ((*ans - 100) > (100 - *temp))
			*ans = *temp;
			break;
		
	}
	printf("%d",*ans);
}