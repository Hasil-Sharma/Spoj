#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
	int t,x,y,z;
	long long double temp;
	long long int ans,den;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&x,&y,&z);
		ans = x*x + y*y + 2*y*z;
		temp = z*sqrt(ans);
		den = y + 2*z;
		if(temp%den == 0 && (z*x%den) == 0)
		{
			t = z*x/den + tem/den;
			if(t <= x) 
			{
				printf("%d\n",t);
				continue;
			}
			t = z*x/den - tem/den;
			if(0 <= t && t <= x)
			{
				printf("%d\n",t)
				continue;
			}
			printf("Not this time.\n");
		}
		else
		{
			printf("Not this time.\n");
		}
	}	
}