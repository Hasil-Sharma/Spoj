#include <cstdio>
#include <algorithm>
#include <vector>
#define maxsize 1100001
#define mod 100000
static unsigned long long int num[maxsize];
using namespace std;
bool compare(int a,int b)
{
	return a>b;
}
int main()
{
	int t,a,b,count,si,ei,j,index = 1;
	//finding all the number until 1100000
	for(unsigned long long int n = 1; n < maxsize; n++) 
		{
			num[n] = ((n%mod)*((n+1)%mod)*(2*n+1)%mod)%mod;
		}
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&a,&b);
		count = 1;
		si = a-1;
		ei = si+b;
		vector<unsigned long long int> v;
		while(si <= ei)
		{
			v.push_back(num[si]);
			si++;
		}
		make_heap(v.begin(),v.end(),compare);
		printf("Case %d:",index++);
		while(count <= 100 && v.size())
		{
			pop_heap(v.begin(),v.end(),compare);
			printf(" %llu",v.back());
			v.pop_back();
			count++;
		}
		printf("\n");
	}
	return 0;
}