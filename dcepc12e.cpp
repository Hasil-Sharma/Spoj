#include<stdio.h>
#include<iostream>
#define N 101
long long A[N][N];
long long B[N][N];
long long ans[N][N];
long long sum;
using namespace std;
void getarray(long long int (*array)[N], int n)
{
	
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			scanf("%lld",&array[i][j]);

	return;
}

void multiply(int n)
{
	sum = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
		{
			ans[i][j] = 0;
				for(int k = 0; k < n; k++)
				{
					ans[i][j] += A[i][k]*B[k][j];
				}
			sum += ans[i][j];
		}
	return;
}
int main()
{
	int n,q,i,j,k;
	char c;
	scanf("%d",&n);
	getarray(A,n);
	getarray(B,n);
	multiply(n);
	cin >> q;
	while(q--)
	{
		cin >> c >> i >> j >> k;
		if(c == 'A')
		{
			for(int p = 0; p < n; p++)
				sum -= ans[i][p];
			A[i][j] = k;
			for(int a = 0; a < n; a++)
			{
				ans[i][a] = 0;
				for(int b = 0; b < n; b++)
						ans[i][a] += A[i][b]*B[b][a];
				sum += ans[i][a];
			}
		}
		else
		{
			for(int p = 0; p < n; p++)
				sum -= ans[p][j];
			B[i][j] = k;
			for(int a = 0; a < n; a++)
			{
				ans[a][j] = 0;
				for(int b = 0; b < n; b++)
					ans[a][j] += A[a][b]*B[b][j];
				sum += ans[a][j];
			}
		}
		cout << sum << endl;
	}
	return 0;
}
