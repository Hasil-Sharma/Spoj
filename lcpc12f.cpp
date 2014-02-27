#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
int main()
{
	int t,x,n,cards,i,l,r,index = 1;
	map<int,long long int> m;
	map<int,long long int> :: iterator p,q;
	long long int count;
	scanf("%d",&t);
	while(t--)
	{
		count = 0;
		scanf("%d",&x);
		scanf("%d",&n);
		for(i = 0; i < n; i++)
		{
			scanf("%d",&cards);
			m[cards]++;
		}
		p = m.begin();
		while(p != m.end())
		{
			q = m.find(x-(p->first));
			if(q != m.end() && p->first <= (x - p->first))
			{
				//printf("%d\n",q->first);
				if(x == 2*q->first) count += (p->second)*(p->second-1)/2;
				else
				{
					count += (p->second)*(q->second);
				}
			}
			p++;
		}
		printf("%d. %lld\n",index,count);
		m.clear();
		index ++;
	}
}