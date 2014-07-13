#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <cmath>
#include <numeric>

using namespace std;
typedef signed long long sll;

int main()
{
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	sll n = 0;
	cin >> n;

	while (n)
	{
		vector <sll> expenses(n);
		for (int i = 0; i < n; i++)
		{
			double exp = 0;
			cin >> exp;
			// Important rounding double to int
			expenses[i] = (sll)(exp*100 + 0.5);
		}


		sll sum_cents = 0;
		for (int i = 0; i < n; i++)
		{
			sum_cents += expenses[i];
		}

		sort(expenses.begin(), expenses.end());

		vector <sll> avg(n,sum_cents/n);
		sll rem = sum_cents - (sum_cents/n)*n;

		for (int i = n - 1; i >= 0 && rem > 0; i--)
		{
			avg[i] = avg[i] + 1;
			rem--;
		}

		int i = 0;
		double transfer = 0;
		while (i < n && (expenses[i] <= avg[i]))
		{
			// cout << avg[i] << " " << expenses[i] << "\n";
			transfer += (avg[i] - expenses[i]);
			i++;
		}
		transfer = transfer/100;
		cout <<  setiosflags(ios::fixed) << setprecision(2) << "$" << transfer << "\n";
		cin >> n;
	}
	return 0;
}
