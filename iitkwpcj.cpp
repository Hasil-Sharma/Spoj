#include <iostream>
#include <string>
using namespace std;
/*
 Check the lowest string of two and remove that smaller from
 larger string, removal must be from 0 index, not any other
 
 ababab, ab
 abab,ab
 ab,ab
 //
 ababab, abab
 ab,abab
 ab,ab

 */
bool func(string*, string*);

int main()
{
	int t;
	string s1,s2;
	cin >> t;
	while(t--)
	{
		bool flag;
		cin >> s1 >> s2;
		flag = func(&s1,&s2);
		if(flag) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}

bool func(string* s1, string* s2)
{
	if(*s1 == *s2) return true;
	else if( s1->length() == s2->length()) return false;
	else if ( s1->length() > s2->length())
	{
		if(s1->find(*s2) != 0) return false;
		while(s1->find(*s2) == 0)
			s1->erase(s1->begin(),s1->begin() + s2->length());
		if(s1->length() == 0) return true;
		else return func(s1,s2);
	}
	else
	{
		if(s2->find(*s1) != 0) return false;
		while(s2->find(*s1) == 0)
			s2->erase(s2->begin(),s2->begin() + s1->length());
		if(s2->length() == 0) return true;
		else return func(s1,s2);
	}
}
