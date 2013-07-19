#include<stdio.h>
#include<math.h>

long int gcd(long int a,long int b){
	if (a%b == 0)
		return b;
	else
		return gcd(b,a%b);
}

int main(){
	long int i,t,a,b,j,g,ans;
	float sqt;
	scanf("%ld",&t);
	i = 1;
	while (i <= t){
		scanf("%ld %ld",&a,&b);
		if (a > b)
			g = gcd(a,b);
		else
			g = gcd(b,a);
		sqt = sqrt(g);
		ans = 0;
		j = 1;
		while (j <= sqt ){
			if (g % j == 0){
				ans = ans + 2;
				if (j == g/j)
					ans = ans - 1;
			}
			j += 1;
		}
		printf("%ld\n",ans);
		i += 1;

	}
	return 0;

}
