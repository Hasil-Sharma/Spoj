#include <string>
#include <iostream>
using namespace std;
int main()
{
	int t,count = 0;
	bool flag;
	cin >> t;
	string temp("100");
	while(t--)
	{
		string str;
		count++;
		cin >> str;
		flag = true;
		while(flag)
		{
			if(str == temp) break;
			int index = str.find(temp);
			if(index == string::npos) flag = false;
			else str.erase(str.begin() + index, str.begin() + index + 3);
		}
		cout << "Case " << count << ": ";
		if(flag) cout << "yes";
		else cout << "no";
		cout << endl;
	}
	return 0;
}
