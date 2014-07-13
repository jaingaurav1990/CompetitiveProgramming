#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#define REP(i, n) for (int i = 0; i < n; i++)

int main()
{
	int n = 0;
	cin >> n;
	while (!cin.eof())
	{
		vector <int> seq(n);
		REP(i, n)
		{
			cin >> seq[i];	
		}

		vector <int> found(n);
		REP(i, n - 1)
		{
			int diff = abs(seq[i] - seq[i + 1]);
			if (diff < n)
			{
				found[diff] = 1;
			}
		}

		int sum = 0;
		REP(i, n)
		{
			sum += found[i];
		}

		if (sum != (n - 1))
		{
			cout << "Not jolly\n";

		}
		else 
		{
			cout << "Jolly\n";
		}

		cin >> n;
	}
}
