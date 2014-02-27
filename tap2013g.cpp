#include<stdio.h>
#include<list>
using namespace std;
int main()
{
	int s,sol,count = 0,flag;
	scanf("%d",&s);
	list<int> quad;
	list<int> nlogo;
	for(int i = 0; i < s; i++)
	{
		scanf("%d",&sol);
		quad.push_back(sol);
	}
	for(int i = 0; i < s; i++)
	{
		flag = 1;
		printf("\nInput the soldier of nlogo : ");
		scanf("%d",&sol);
		list<int> :: iterator p = quad.begin();
		while(p != quad.end())
		{
			if(*p < sol)
			{
				count++;
				quad.remove(*p);
				flag = 0;
				break;
			}
			p++;
		}
		if(flag)
		{
			list<int> :: iterator p = quad.begin();
			while(p != quad.end())
			{
				if(*p == sol)
					quad.remove(sol);
				p++;
			}
		}

	}
	printf("%d\n",count);
	return 0;
}