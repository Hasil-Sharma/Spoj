#include <cstdio>
#include <algorithm>
#include <vector>
#define maxsize 1100001
#define mod 100000
static int fibNum[maxsize];
using namespace std;
bool compare(int a,int b)
{
	return a>b;
}
int main()
{
	int t,a,b,count,si,ei,j,index = 1;
	fibNum[0] = 0;
	fibNum[1] = 1;
	//finding all the fibo number unti 1100000
	for(int i = 2; i < maxsize; i++) fibNum[i] = (fibNum[i-1]%mod + fibNum[i-2]%mod)%mod;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&a,&b);
		count = 1;
		si = a-1;
		ei = si+b;
		j = 0;
		vector<int> v;
		while(si <= ei)
		{
			v.push_back(fibNum[si]);
			si++;
		}
		make_heap(v.begin(),v.end(),compare);
		printf("Case %d:",index++);
		while(count <= 100 && v.size())
		{
			pop_heap(v.begin(),v.end(),compare);
			printf(" %d",v.back());
			v.pop_back();
			count++;
		}
		printf("\n");
	}
	return 0;
}