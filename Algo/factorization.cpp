#include <cstdio>
#include <cmath>
#include <map>
using namespace std;
int main()
{
	int n;
	map<int,int> m;
	map<int,int> :: iterator p;
	scanf("%d",&n);
	for(int i = 2; i <= sqrt(n); i++)
	{
		while(n%i == 0)
		{
			m[i]++;
			n = n/i;
		}
	}
	if(n != 1) m[n] = 1;
	p = m.begin();
	printf("%d^%d",p->first,p->second);
	p++;
	while(p != m.end())
	{
		printf("*%d^%d",p->first,p->second);
		p++;
	}
	printf("\n");
	return 0;
}