#include <cstdio>
#include <cstring>

int main()
{
	int len,count,sum,num,num2,i;
	int array[] = {1,3,2,-1,-3,-2};
	int yes;
	char str[245],chr;
	while(scanf("%s",str) != EOF)
	{
		len = strlen(str);
		for(i = 0,count = 0,sum = 0,num = 0,num2 = 0,yes = 0; i < len; i++)
		{
			chr = str[i];
			if(chr == '0')
			{
				continue;
			}
			else if(chr == '1')
			{
				count++;
			}
			else if(chr == '2')
			{
				if((str[len-1]-48)%2 == 0)
					count++;
			}
			else if(chr == '3')
			{
				if(sum == 0)
				{
					for(int j = 0; j < len; j++)
					{
						sum += (str[j] - 48);
					}
				}
				if(sum % 3 == 0)
					count ++;
			}
			else if(chr == '4')
			{
				if(num == 0)
				{
					num = 10*(str[len-2] - 48) + (str[len-1] - 48);
				}
				if(num%4 == 0)
					count++;
			}
			else if(chr == '5')
			{
				if((str[len-1]-48)%5 == 0)
					count++;
			}
			else if(chr == '6')
			{
				if(sum == 0)
				{
					for(int j = 0; j < len; j++)
					{
						sum += (str[j] - 48);
					}
				}
				if(sum%3 == 0 && (str[len-1]-48)%2 == 0)
					count++;
			}
			else if(chr == '7')
			{
				if(yes == 1) count++;
				else if(yes == -1) continue;
				else
				{
					int numk,k = 0,nsum = 0;
					for(int j = len-1; j >=0 ; j--)
					{
						numk = str[j] - 48;
						nsum += array[k]*numk;
						k = (k+1)%6;
					}
					if(nsum% 7 == 0)
					{
						count++;
						yes = 1;
					}
					else yes = -1;
				}
			}
			else if(chr == '8')
			{
				if(num2 == 0)
				{
					num2 = 100*(str[len-3]-48) + 10*(str[len-2]-48) + str[len-1]-48;
				}
				if(num2%8 == 0)
					count++;
			}
			else if(chr == '9')
			{
				if(sum == 0)
				{
					for(int j = 0; j < len; j++)
					{
						sum += (str[j] - 48);
					}
				}
				if(sum % 9 == 0)
					count++;
			}
		}
		printf("%d\n",count);
	}
}