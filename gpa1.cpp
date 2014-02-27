#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;
int getattendence(float a)
{
	if( a < 51) return 5;
	else if( a < 61) return 4;
	else if (a < 71) return 3;
	else if (a < 81) return 2;
	else if (a < 91) return 1;
	else return 0;
}
int getsubject(float a)
{
	if(a >= 91) return 10;
	else if(a >= 81) return 9;
	else if(a >= 71) return 8;
	else if(a >= 61) return 7;
	else if(a > 50) return 6;
	else if(a == 50) return 5;
	else if(a < 50) return 0;

}
int main()
{
	int n,credit[6],i,subject[6];
	float finalexam,attendence,nfinal,nassignemnt,subtot,credits,assignment[3];
	bool flag;
	string s;
	string s1("ab");
	string :: size_type sz;
	scanf("%d",&n);
	while(n--)
	{
		for(i = 0; i < 6; i++)
			scanf("%d",&credit[i]);
		flag = false;
		for(int j = 0; j < 6; j++)
		{
			for(i = 0; i < 3; i++)
			{
				cin >> s;
				if(s == s1) assignment[i] = 0;
				else assignment[i] = atof(s.c_str());
			}
			scanf("%f",&finalexam);
			nfinal = finalexam/2.0;
			scanf("%f",&attendence);
			attendence = getattendence(attendence);
			sort(assignment,assignment+3);
			nassignemnt = (assignment[2]+assignment[1])*45.0/40;
			subtot = nfinal + attendence + nassignemnt;
			subject[j] = getsubject(subtot);
		}
		subtot = 0.0;
		credits = 0.0;
		for(i = 0; i < 6; i++)
		{
			if(subject[i] == 0) flag = true;
			credits += credit[i];
			subtot += credit[i]*subject[i];
		}
		if(flag)
		{
			printf("FAILED, %.2f\n",subtot*1.0/credits);
		}
		else
		{
			printf("PASSED, %.2f\n",subtot*1.0/credits);
		}
	}
	return 0;
}