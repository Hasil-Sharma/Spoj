#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int main()
{
	int n,c;
	c = 1;
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
			//cout << "POI : " << temp << endl;
			if(temp == 0) continue;
			for(int j = i-1; j >= 0 && !flag; j--)
			{
				//cout << "\t Comparing with" << array[j] << endl;
				if(array[j] < temp)
				{
					//cout << "\t\t Smaller than temp hence count++" << endl;
					flag = 1;
					found = 0;
				}
				else if(array[j] == temp)
				{
					//cout << "\t\t Same height as that of poi, nothing" << endl;
					found = 0;
					//flag = 0;
					break;
				}
			}
		  //cout << "\tAll are greater hence count++" << endl;
			count += flag + found;
		}
		cout <<"Case " << c <<": " << count << endl;
		c++;
	}
	return 0;
}
