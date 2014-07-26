#include <stdio.h>
#include <iostream>
using namespace std;
int getSum(int);
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
		int suma,sumb,sum,tempa,tempb;
		cin >> a >> b;
		if( a == -1 ) break;
		tempa = a - a%10;
		tempb = b - b%10;
		if(tempa < 10)
		{
			break;	
		}
		else
		{
			for(int i = tempa; i < tempb; i += 10)
			{
				int d = getSum(tempa) - 1;
				sum += 45 + d*10;
			}
			sum += getSum(tempb);
		}
		cout << sum << endl;
	}
	return 0;
}

int getSum(int a)
{
	if(a%10 == a) return a;
	else return a%10 + getSum(a/10);
}
