#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int main()
{
	int n;
	while(scanf("%d",&n) != EOF)
	{
		vector <int> array(n);
		for(int i = 0; i < n; i++)
			cin >> array[i];
		int count = (array[0]) ? 1 : 0;
		for(int i = 1; i < n; i++)
		{
			int flag = 0,found = 1;
			int temp = array[i];
			if(temp == 0) continue;
			for(int j = i-1; j >= 0 && !flag; j--)
			{
				if(array[j] < temp)
				{
					flag = 1;
					found = 0;
				}
				else if(array[j] == temp)
				{
					found = 0;
					break;
				}
			}
			count += flag + found;
		}
		cout << count << endl;
	}
	return 0;
}


