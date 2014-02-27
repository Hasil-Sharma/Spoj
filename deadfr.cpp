#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
typedef long long int ll;
ll gcd(ll x, ll y)
{
	if (y == 0) return x;
	else return gcd(y, x%y);
}
ll getpow(int length)
{
	int i = 1;
	ll ans = 1;
	for(i = 0; i < length ; i++)
		ans = ans * 10;
	return ans;
}
int main()
{
	string s,num1,num2;
	ll a,b,p,q,x1,y1,d,x2,y2;
	int index;
	cin >> s;
	while(s != "0")
	{
		index = s.find("...");
		num1 = s.substr(2,s.length()-5);
		a = getpow(num1.length());
		b = 10*a;
		cout << a << endl;
		cout << b << endl;
		num2 = num1 + num1[num1.length()-1];
		p = atoll(num1.c_str());
		q = atoll(num2.c_str());
		x1 = q - p;
		y1 = b - a;
		d = gcd(x1,y1);
		//cout << d << endl;
		//cout << x << endl;
		//cout << y << endl;
		cout << x1/d << "/" << y1/d << endl;
		cin >> s;
	}	
}