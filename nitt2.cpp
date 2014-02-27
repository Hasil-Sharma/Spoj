#include <cstdio>
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;
int getsum(string s)
{
	int sum = 0;
	char c;
	for(int i = 0; i < s.length(); i++)
	{
		sum += (s[i]-48);
	}
	return sum;
}
bool checkseven(string s)
{
	int array[] = {1,3,2,-1,-3,-2};
	int k=0,num,sum = 0;
	for(int i = s.length() - 1; i >= 0; i--)
	{
		num = s[i] - 48;
		sum += array[k]*num;
		k = (k+1)%6;
	}
	if(sum%7 == 0) return true;
	else return false;
}
int main()
{
	int t,sum;
	bool flag1 , flag2, byseven;//flag1 = 252, flag2 = 525
	string s;
	scanf("%d",&t);
	while(t--)
	{
		cin >> s;
		//for 9 and 3
		sum = getsum(s);
		//cout << "Total of nums " << sum << endl;
		if(s == "0")
		{
			printf("Yes Yes\n");
		}
		if(s.length() == 1 || s.length() == 2)
		{
			printf("No No\n");
			continue;
		}
		if(sum%3 == 0)
		{
			flag2 = true;
			flag1 = false;
			if(sum%9 == 0)
				flag1 = true;
		}
		else
		{
			flag2 = false;
			flag1 = false;
		}
		//for 4 and 25
		sum = 10*(s[s.length()-2]- 48);
		sum += s[s.length()-1] - 48;
		//cout << "Sum of last two numbers " << sum << endl;
		if(sum%4 == 0 && sum%25 == 0)
		{
			if(flag2) flag2 = true;
			if(flag1) flag1 = true;
		}
		else if(sum%4 == 0)
		{
			if(flag1) flag1 = true;
			flag2 = false;
		}
		else if(sum%25 == 0)
		{
			flag1 = false;
			if(flag2)flag2 = true;
		}
		else
		{
			flag1 = false;
			flag2 = false;
		}
		byseven = checkseven(s);
		//cout << "Done by Seven :" << byseven << endl;
		if(flag1 && byseven) printf("Yes ");
		else printf("No ");

		if(flag2 && byseven) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}