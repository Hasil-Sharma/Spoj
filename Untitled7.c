#include <stdio.h>
int main()
{
	unsigned long long int i = 0;
	unsigned long long int ans;
	for (ans = 1 ; i < 31 ; i++ )
	{
		ans *= 8;
		printf("answer returned %llu\n",ans);
	}
	printf("answer returned %llu\n",ans);
	return 0;
}