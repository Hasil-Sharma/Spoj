#include <iostream>
using namespace std;
int getsum(long long int num)
{
	int sum = 0;
	while(num)
	{
		sum += num%10;
		num  = num /10;
	}
	return sum;
}
int main()
{
	int t,sum;
	long long int num;
	cin >> t;
	while(t--)
	{
		cin >> num;
		sum = getsum(num);
		while(num % sum != 0)
		{
			sum = getsum(++num);
		}
		printf("%lld\n",num);

	}
}