#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;
int main()
{
	int t,found;
	bool flag;
	char array[100001];
	scanf("%d",&t);
	while(t--)
	{
		flag = true;
		scanf("%s",array);
		string s1(array);
		scanf("%s",array);
		string s2(array);
		if(s1.length() == s2.length())
		{
			if(s1 == s2)
			flag = false;
			else
			flag = true;
		}
		else if(s1.length() > s2.length())
		{
			while(s1 != s2)
			{
				flag = false;
				found = s1.find(s2);
				if(found == 0)
				{
					cout << s1 << endl;
					found += s2.length();
					s1.assign(s1,found,s1.size());
				}
				else
				{
					flag = true;
					break;
				}
			}
		}
		else if(s1.length() < s2.length())
		{
			while(s1.length() != s2.length())
			{
				flag = false;
				found = s2.find(s1);
				if(found == 0)
				{
					cout << s2 << endl;
					found += s1.length();
					s2.assign(s2,found,s2.size());
				}
				else
				{
					flag = true;
					break;
				}
			}
		}
		if(flag) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
	return 0;
}