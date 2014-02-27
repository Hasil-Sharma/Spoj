#include <cstdio>
#include <map>
using namespace std;

int main()
{
	int r,i,count = 0;
	map<int,int> m,tut;
	map<int,int> :: iterator p;
	scanf("%d",&r);
	while(r--)
	{
		scanf("%d",&i);
		m[i]++;
	}
	p = m.begin();
	count++;
	while(p != m.end())
	{
		while(tut[count] < 4)
		{
			
		}

	}

}