#include<stdio.h>
int main(){
	int n,d,s,r,llst,i;
	scanf("%d %d",&n,&d);
	while(n != 0 && d != 0){
		printf("Inside first while\n");
		int lst[n];
		for (i=0; i<n;i++)
			lst[i] = i+1; 
		s = 0;
		llst = sizeof(lst)/sizeof(lst[0]);
		printf("%d\n",llst);
		while (llst > 1){
			printf("inside second while");
			r = s + d - 1;
			if (r >= llst){
				r = r%llst;
			}
			for(i = r; i < llst-1 ; i++){
				lst[r] = lst[r+1];
			}
			llst = llst - 1;
			s = r;
			if (s >= llst){
				s = s%llst;
			}
		}
		printf("%d",lst[0]);
		scanf("%d %d",&n,&d);
		}
	return 0;
}