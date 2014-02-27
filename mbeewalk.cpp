#include<stdio.h>

int main()
{
	int n,t;
	//long long int array[15] = {1, 0, 6, 12, 90, 360, 2040, 10080, 54810, 290640, 1588356, 8676360, 47977776, 266378112, 1488801600};
	long long int array[15];
	array[0] = 1;
	array[1] = 0;
	array[2] = 6;
	for(int i = 0; i < 12 ;i++)
		array[i+3] = ((108*i+72+36*i*i)*array[i] + array[i+1]*(24*i*i+96*i+96) + array[i+2]*(i*i + 5*i + 6))/(i*i+6*i+9);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		printf("%lld\n",array[n]);
	}

	return 0;
}