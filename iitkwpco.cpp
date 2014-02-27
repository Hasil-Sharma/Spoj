#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
struct number
{
	int num;
	bool visited;
}node;

typedef struct number number;

bool array_sorter(number first, number second)
{
	return (first.num < second.num);
}
int main()
{
	int t,n,i,a,count,val;
	vector<number> array;
	vector<number>::iterator p;
	scanf("%d",&t);
	while(t--)
	{
		count = 0;
		scanf("%d",&n);
		for(i = 0; i < n; i++)
		{
			scanf("%d",&a);
			node.num = a;
			node.visited = false;
			array.push_back(node);
		}
		sort(array.begin(),array.end(),array_sorter);
		for(i = 0; i < n; i++)
		{
			if(array[i].visited == false)
			{
				val = 2*array[i].num;
				p = array.begin();
				//cout << "Checking " << array[i].num << endl;
				while(p != array.end())
				{
					if(p->num == val && p->visited == false)
					{
						count++;
						//cout << array[i].num << " and " << p->num << endl;
						array[i].visited = true;
						p->visited = true;
						break;
					}
					p++;
				}
			}
		}
		printf("%d\n",count);
		array.clear();

	}
}