#include <cstdio>
void genseq(int * array, int index)
{
	if(index == 5)
	{
		for(int i = 0; i < 5; i++)
			printf("%d",array[i]);
		printf("\n");
	}
	else
	{
		array[index] = 0;
		genseq(array,index+1);
		array[index] = 1;
		genseq(array,index+1);
	}
	return;
}
int main()
{
	int array[5];
	genseq(array,0);
	return 0;
}