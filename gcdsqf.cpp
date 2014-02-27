#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
string getlcm(string a, string b)
{
	string lcm;
	int i;
	for(i = 0; i < b.length(); i++ )
	{
		if(a[i] == '0' && b[i] == '0') lcm += '0';
		else lcm += '1';
	}
	lcm += a.substr(i,a.length()-b.length());
	return lcm;
}

string getunique(string a, string lcm)
{
	string g1;
	for(int i = 0; i < a.length(); i++)
	{
		if(a[i] == '1' && lcm[i] == '1') g1 += '1';
		else g1 += '0';
	}
	return g1;
}
int main()
{
	string a,b,lcm,g1,g2,ans;
	int k,index;
	scanf("%d",&k);
	while(k--)
	{
		cin >> a;
		cin >> b;
		lcm = (a.length() > b.length()) ? getlcm(a,b) : getlcm(b,a);
		g1 = getunique(a,lcm);
		g2 = getunique(b,lcm);
		ans = (g1.length() > g2.length()) ? getunique(g2,g1) : getunique(g1,g2);
		index = -1;
		for(int i = 0; i < ans.length(); i++)
		{
			if(ans[i] == '1') index = i;
		}
		if(index == -1) printf("relatively prime");
		else
		{
			for(int i = 0; i <= index; i++)
				printf("%c",ans[i]);
		}
		printf("\n");

	}
}