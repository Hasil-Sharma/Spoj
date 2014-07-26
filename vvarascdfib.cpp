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
	//fibNum[0] = 0;
	//fibNum[1] = 1;
	//finding all the fibo number unti 1100000
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
		j = 0;
		vector<unsigned long long int> v;
		vector<unsigned long long int> :: iterator p;
		while(si <= ei)
		{
			v.push_back(num[si]);
			si++;
		}
		sort(v.begin(),v.end());
		printf("Case %d:",index++);
		p = v.begin();
		while(count <= 100 &&  p!= v.end())
		{
			//pop_heap(v.begin(),v.end(),compare);
			printf(" %llu",*p);
			p++;
			count++;
		}
		printf("\n");
	}
	return 0;
}