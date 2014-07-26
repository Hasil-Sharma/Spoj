#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;
struct object{
	long long int matrix[4][4];
};

struct object Matrix;
struct object* mod(struct object* Ans, int m);
struct object* power(struct object* Ans, int k, int m);
struct object* multiply(struct object* a,struct object* b, int m);
/*void print(struct object* Ans)
{
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
			printf("%lld ",Ans->matrix[i][j]);
		printf("\n");
	}
}*/
int main()
{
	int t,n,m;
	Matrix.matrix[0][0] = Matrix.matrix[0][1] = 1ll;
	Matrix.matrix[0][2] = Matrix.matrix[1][0] = Matrix.matrix[3][2] = 1ll;
	Matrix.matrix[0][3] = Matrix.matrix[1][1] = Matrix.matrix[1][2] = Matrix.matrix[1][3] = 0ll;
	Matrix.matrix[2][0] = Matrix.matrix[2][1] = 0ll;
	Matrix.matrix[3][0] = Matrix.matrix[3][1] = Matrix.matrix[3][3] = 0ll;
	Matrix.matrix[2][2] = 2ll;
	Matrix.matrix[2][3] = -1ll;
	scanf("%d",&t);
	while(t--)
	{
			struct object *Ans;
			Ans = (struct object *)malloc(sizeof(struct object));
			memcpy(Ans->matrix,Matrix.matrix,sizeof(long long int)*16);
			scanf("%d %d",&n,&m);
			if(n == 0 || n == 1)
			{
				if(n == 0) printf("0\n");
				else printf("%d\n",1%m);
				continue;
			}
			int k = n - 1;
			Ans = mod(power(Ans,k,m),m);
			//print(Ans);
			printf("%lld\n",(Ans->matrix[0][0]%m + Ans->matrix[0][2]%m)%m);
	}
	return 0;
}

struct object* multiply(struct object* a,struct object* b, int m)
{
	struct object* temp;
	temp = (struct object*)malloc(sizeof(struct object));
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			temp->matrix[i][j] = 0;
			for(int k = 0; k < 4; k++)
				temp->matrix[i][j] += ((a->matrix[i][k]%m)*(b->matrix[k][j]%m))%m;
			temp->matrix[i][j] %= m;
		}
	}
	return temp;
}
struct object* power(struct object* Ans, int k,  int m)
{
	struct object *temp;
	Ans = mod(Ans,m);
	if(k == 1) return mod(Ans,m);
	else if(k%2 == 1) return mod(multiply(mod(Ans,m),mod(power(Ans,k-1,m),m),m),m);
	temp = mod(power(mod(Ans,m),k/2,m),m);
	temp = mod(multiply(temp,temp,m),m);
	return temp;
}

struct object* mod(struct object* Ans, int m)
{
	struct object *temp;
	temp = (struct object *) malloc(sizeof(struct object));
	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
			temp->matrix[i][j] = Ans->matrix[i][j]%m;
	return temp;
}
