#include <cstdio>
#include <map>
#include <queue>
using namespace std;

int main()
{
	int t,n,i,j,num,p;
	scanf("%d",&t);//number of test cases
	map <int,queue<int> > woman,man;
	while(t--)
	{
		scanf("%d",&n);//number of marriages to be found
		for(i = 0; i < n; i++)
		{
			scanf("%d",&num);
			woman[num] =  queue();
			for(j = 0; j < n; j++)
			{
				scanf("%d",&p);
				woman[num].push_back(p);
			}
		}
		for(i = 0; i < n; i++)
		{
			scanf("%d",&num);
			man[num] =  queue();
			for(j = 0; j < n; j++)
			{
				scanf("%d",&p);
				man[num].push_back(p);
			}
		}
	}
}