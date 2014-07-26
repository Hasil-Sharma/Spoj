#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
using namespace std;

long long int gcd(long long int x, long long int y)
{
	if(y == 0) return x;
	else return gcd(y,x%y);
}

long long int getnum(string str)
{
	char *strc = const_cast<char*>(str.c_str());
	long long int num1 = atoll(strc);
	long long int num2 = num1/10;
	//printf("Num1 && Num2 : ");
	//printf("%lld %lld\n",num1,num2);
	return num1-num2;
}

long long int getdem(int count)
{
	long long int num1 = 1,num2 = 1,temp = 1;
	for(int i = 0;i < count; i++)
		temp *= 10;
	num1 = temp;
	num2 = num1/10;
	//printf("%d %lld %lld\n",count,num1,num2);
	return num1 - num2;
}
int main()
{
	string str;
	while(true)
	{
		int count,index;
		long long int num,dem;
		cin >> str;
		if(str == "0") break;
		index = str.find("...");
		count = index - 2;
		str.erase(str.begin()+index,str.end());
		str.erase(str.begin(),str.begin()+2);
		num = getnum(str);
		dem = getdem(count);
		long long int hcf = gcd(num,dem);
		cout << num/hcf << "/" << dem/hcf << endl;
	}
	return 0;
}
