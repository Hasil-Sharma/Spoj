#include<stdio.h>
int row_number(long int n, int alpha,int beta);
char seat_position(int n);
char direction(long int n);
int main()
{
	long int t,n,i=0;
	char sea_pos,dir;
	int row_num,temp;
	scanf("%ld",&t);
	while(i < t)
	{
		i++;
		scanf("%ld",&n);
		if (n != 1)
		{
			temp = n % 10;
			sea_pos = seat_position(temp);
			row_num = row_number()
			printf("%d %c %c\n",row_num,sea_pos,dir);	
		}
		else
			printf("poor conductor\n");
	}
	return 0;
}
char seat_position(int n)
{
	if (n == 1 || n == 2 || n == 6 || n == 7)
		return 'W';
	else if (n == 3 || n == 0 || n == 4 || n == 9)
		return 'A';
	else
		return 'M';	
}