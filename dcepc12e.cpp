#include<stdio.h>
#include<iostream>
using namespace std;
long long int mul[100][100];
int a[100][100],b[100][100];
void getinput(int n,int a[][100])
{
	int i,j;
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			scanf("%d",&a[i][j]);
}

void multiply(int n)
{
	int i,j,k;
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			mul[i][j] = 0;
			for(k = 0; k < n; k++)
			{
				mul[i][j] += a[i][k]*b[k][j];
			}
		}
	}
}

long long int getsum(int n)
{
	int i,j;
	long long int ans = 0;
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			ans += mul[i][j];

	return ans;
}

void modifya(int I, int J, int n)
{
	int i,j,k;
	for(j = 0; j < n; j++)
	{
		mul[I][j] = 0;
		for(k = 0; k < n; k++)
		{
			mul[I][j] += a[I][k] * b[k][j];
		}
	}
}

void modifyb(int I, int J, int n)
{
	int i,j,k;
	for(j = 0; j < n; j++)
	{
		mul[j][J] = 0;
		for(k = 0; k < n; k++)
		{
			mul[j][J] += a[j][k] * b[k][J];
		}
	}
}

int main()
{
	int n,i,j,q,k;
	long long int ans;
	char name;
	scanf("%d",&n);
	getinput(n,a);
	getinput(n,b);
	multiply(n);
	scanf("%d",&q);
	while(q--)
	{
		cin >> name >> i >> j >> k;
		//name = getchar();
		//scanf("%c%d%d%d",&name,&i,&j,&k);
		if(name == 'A')
		{
			a[i][j] = k;
			modifya(i,j,n);
			ans = getsum(n);
		}
		else if(name == 'B')
		{
			b[i][j] = k;
			modifyb(i,j,n);
			ans = getsum(n);
		}
		printf("%lld\n",ans);
	}

}