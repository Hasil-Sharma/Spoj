#include <cstdio>
#include <string>
#include <iostream>
#include <cstring>
using namespace std;
int idx;
int pow(int a, int b)
{
	int ans = 1;
	while(b--)
	{
		ans = a*ans;
	}
	return ans;
}
int stringtoint(string s)
{
	int i,ans=0;
	for(i = 0; i < s.length(); i++)
	{
		ans += (s[i] - 48)*pow(10,s.length()-i-1);
	}
	return ans;
}
int getword(const char* s)
{
	int i;
	string temp;
	i = idx;
	while(s[i] > 47 && s[i] < 58 || s[i] == 40 || s[i] == 41)
	{
		if(s[i] != 40 && s[i] != 41)
			temp += s[i];
		//cout << s[i] << endl;
		i++;
	}
	idx = i;
	//cout << temp << endl;
	return stringtoint(temp);
}
int main()
{
	int ans,a,b,i=0,length;
	char sign;
	string s;
	cin >> s;
	length = s.length();
	idx = 0;
	a = getword(s.c_str());
	cout << a << endl;
	while(idx < length)
	{
		sign = s[idx];
		idx++;
		b = getword(s.c_str());
		cout << b << endl;
		if(sign == 43)
			a = a + b;
		else if(sign == 45)
			a = a - b;
		else if(sign == 42)
			a = a * b;
	}
	cout << a << endl;
}