#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define REP(i, n) for (int i = 0; i < n; i++)

void print(vector < vector <int> > L, int n, int m)
{
	REP(i, n + 1)
	{
		REP(j, m + 1)
		{
			cout << L[i][j] << " ";
		}
		cout << "\n";
	}
}

int main()
{
	string s1;
	string s2;
	
	while (getline(cin, s1))
	{
		getline(cin, s2);
		int n = s1.length();
		int m = s2.length();	

		//cout << n << " " << m << "\n";
		vector < vector <int> > L (n + 1, vector <int> (m + 1));
		REP(i, n + 1)
		{
			L[i][0] = 0;
		}

		REP(i, m + 1)
		{
			L[0][i] = 0;
		}

		for (int j = 1; j < m + 1; j++)
		{
			for (int i = 1; i < n + 1; i++)
			{
				if (s1[i - 1] == s2[j - 1])
				{
					//cout << "Alphabets match\n" << s1[i - 1] << " " << s2[j - 1] << "\n";
					L[i][j] = L[i - 1][j - 1] + 1;
				}
				else
				{
					L[i][j] = max(L[i - 1][j], L[i][j - 1]);
				}
			}
		}

		cout << L[n][m] << "\n";
		//print(L, n, m);
	}
}
