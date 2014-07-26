#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
	int a,b,array[10];
	array[0] = 0;
	for(int i = 1; i < 10; i++)
	{
		//array[i] = 1 + 2 + .. + i;
		array[i] = array[i-1] + i;
	}
	while(true)
	{
		cin >> a >> b;
		if( a == -1 ) break;


	}
	return 0;
}
