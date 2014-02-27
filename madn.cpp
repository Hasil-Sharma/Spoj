#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;
int main()
{
	int n,size,index=1,i,j,k;
	bool found;
	char vowel[] = {'A','U','E','O','I'},chr;
	scanf("%d",&n);
	map<int,vector<char> > val;
	map<int,vector<char> > :: iterator valitr;
	map<int ,char> vowels;
	map<char,int> charcount;
	map<int ,char> :: iterator itr;
	vector<char> vowelvector;
	for(i = 0; i < 4; i++)
		vowelvector.push_back(vowel[i]);
	vowels[1] = 'A';vowels[3] = 'U';vowels[5] = 'E';
	vowels[6] = 'O';vowels[9] = 'I';
	map<int,vector<char> > ::  iterator p;
	vector<char> :: iterator q;
	for(i = 0; i < 9; i++)
	{
		val[i+1];
		for(j = 0;;)
		{
			if('A' + i + j <= 'Z' && find(vowelvector.begin(),vowelvector.end(),'A' + i + j) == vowelvector.end())
				val[i+1].push_back('A' + i + j);
			else if('A' + i + j > 'Z') break;
			j+=9;
		}
	}
	/*for(valitr = val.begin(); valitr != val.end(); valitr++)
	{
		cout << valitr->first << ":";
		q = valitr->second.begin();
		while(q != valitr->second.end())
		{
			cout << " " << *q;
			q++;
		}
		cout << endl;
	}*/
	while(n--)
	{
		string s,sv,sc;
		scanf("%d",&size);
		for(i = 1; i < size+1; i++)
		{
			if(i%2 == 1)//odd position :vowels
			{
				//printf("Adding a vowel\n");
				itr = vowels.begin();
				while(itr != vowels.end())
				{
					chr = (itr->second);
					if(charcount[chr] < 21)
					{
						//printf("Adding %c\n",chr);
						charcount[chr]++;
						sv += chr;
						break;
					}
					itr++;
				}
			}
			else
			{
				//printf("Adding a constant\n");
				valitr = val.begin();
				found = false;
				while(valitr != val.end())
				{
					q = valitr->second.begin();
					while(q != valitr->second.end())
					{
						chr = (*q);
						if(charcount[chr] < 5)
						{
							//printf("Adding %c\n",chr);
							charcount[chr]++;
							sc += chr;
							found = true;
							break;
						}
						q++;
					}
					if(found) break;
					valitr++;
				}

			}

		}
		sort(sc.begin(),sc.end());
		sort(sv.begin(),sv.end());
		for(i = 1,j=0,k=0; i < size+1; i++)
		{
			if(i%2 == 1) s += sv[j++];
			else s += sc[k++];
		}
		cout << "Case "<< index <<": " << s << endl;
		index++;
		charcount.clear();
		
	}
}