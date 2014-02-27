#include <stdio.h>
#include <algorithm>
#include <map>
using namespace std;
int main()
{
	int t,c,v,i,voter[101][101],j,votes[101],maxv1,maxc1,maxv2,maxc2,maxv,maxc;
	map<int,int> m,m2;
	map<int,int>::iterator p,q;
	scanf("%d",&t);
	while(t--)
	{
		maxv1 = 0;
		maxc1 = 1;
		scanf("%d%d",&c,&v);
		//Taking input
		for(i = 1; i <= v; i++)
			for(j = 1; j <= c; j++)
				scanf("%d",&voter[i][j]);

		//Setting votes to zero
		for(j = 1; j <= c;j++)
			m.insert(pair<int,int>(j,0));

		//For every voter adding a vote to top contentant;
		for(i = 1; i <= v; i++)
		{
			p = m.find(voter[i][1]);
			p->second++;
		}

		//Finding largest and second largest value of votes
		p = m.begin();
		while(p != m.end())
		{
			if(p->second > maxv1)
			{
				maxv1 = p->second;
				maxc1 = p->first;
			}
			p++;
		}
		if(maxv1 > v/2) printf("%d 1\n",maxc1);
		else
		{
			p = m.find(maxc1);
			m.erase(p);
			p = m.begin();
			maxv2 = 0;
			while(p != m.end())
			{
				if(p->second > maxv2)
				{
					maxv2 = p->second;
					maxc2 = p->first;
				}
				p++;
			}
			m2.insert(pair<int,int>(maxc1,0));
			m2.insert(pair<int,int>(maxc2,0));
			p = m2.find(maxc1);
			q = m2.find(maxc2);
			for(i = 1; i <= v; i++)
			{
				for(j =1; j <= c; j++)
				{
					if(voter[i][j] == maxc1) p->second++;
					else if(voter[i][j] == maxc2) q->second++;
				}
			}
			if(p->second > q->second) printf("%d 2\n",p->first);
			else printf("%d 2\n",q->first);
			m2.clear();
		}
		m.clear();

	}
	return 0;
}