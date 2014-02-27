#include <stdio.h>
#include <malloc.h>
#include <iostream>
using namespace std;
int *getlength(char *str,int *count);

int main(void) {
	int t,length,max_freq,word_count,index,i,max_char,max_count,flag,j=1;
	int *arr;
	char str[10010],schar,temp[10010],chr;
	cin >> t;
	getchar();
	while(t--)
	{
		int count[27] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; // for getting count of all the str skipping spaces
		//gets(str);
		//scanf("%10009[0-9a-zA-Z ]s", str);
		cin.getline(str,10010);
		arr = getlength(str,count);
		printf("Case #%d:\n",j++);
		schar = 'a'+arr[0]-1;
		word_count = arr[1];
		index = 0;
		while(word_count--) // Taking out every word one by one
		{
			int wcount[27] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
			for(i=0,max_count=0;(str[index] !=' ') && (str[index] != '\0');index++,i++)
			{
				temp[i] = str[index];
				wcount[temp[i]-'a'+1]++;
				if(wcount[temp[i]-'a'+1] > max_count)
				{
					max_count = wcount[temp[i]-'a'+1];
					max_char = temp[i];
				}
			}// got the maximum repeating char in word and its count
			
			temp[i] = '\0';
			if (max_char == schar)// it maximum repeating char is same as special char
			{
				for(i = 1,flag = 0; i <= 26; i++)// checking if same count is found for any other char in given word 
				{
					if(wcount[i])
					{
						if(wcount[i] == max_count) flag++;
					}
				}
				if(flag == 1) printf("%s\n",temp); // if only one such char is found , then print the str ... it is special
			}
			index++;// skipping the ' ' or '\0' if any found
		}
	}
	return 0;
}

int *getlength(char *str, int *count)
{
	int len = 0,index,max = 0,max_index,wcount=0;
	int *array;
	char c;
	c = str[len];
	
	index = c - 'a' + 1; // index is alway there , min length of str is 1
	count[index]++;
	if(count[index] > max)
	{
		max = count[index];
		max_index = index;
	}
	
	while(c!= '\0')
	{
		len++;
		c = str[len];
		if(c != ' ')
		{
			index = c - 'a' + 1;
			count[index]++;
			if(count[index] > max)
			{
				max = count[index];
				max_index = index;
			}
		}
		else wcount++;
	}
	wcount++;
	array = (int *)malloc(2*sizeof(int));
	array[0] = max_index; //length of str
	array[1] = wcount; // index of special character
	
	return array;
}

