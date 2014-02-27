#include <cstdio>
#include <malloc.h>
using namespace std;
int main()
{
	int *a,c;
	a = (int *)malloc(sizeof(int));
	*a = 1;
	void b;
	b = &a;
	c = b;
	printf("%d\n",c);
}