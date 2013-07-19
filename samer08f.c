#include<stdio.h>
int main(){
	int t;
	scanf("%d",&t);
	while (t != 0){
		t = (t*(t+1)*(2*t+1))/6;
		printf("%d\n",t);
		scanf("%d",&t);
	}
	return 0;
}