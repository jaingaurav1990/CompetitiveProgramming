#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int i = 0; int j = 0;

	while (cin >> i)
	{
		cin >> j;
		int max = -1;

		int lower = i; int upper = j;
		if (i > j)
		{
			lower = j;
			upper = i;
		}

		for (int n = lower; n <= upper; n++)
		{
			int num = n;
			int cycle_len = 1;
			while (num != 1)
			{	
				if (num % 2 == 0)
				{
					num = num/2;
				}
				else
				{
					num = 3*num + 1;
				}
				cycle_len += 1;
			}
			if (cycle_len > max)
					max = cycle_len;


		}	
		cout << i << " " << j << " " << max << "\n";
	}
}
