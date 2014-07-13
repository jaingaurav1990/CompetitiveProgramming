#include <iostream>
#include <vector>

using namespace std;

void inc_neighbors(int i, int j, int n, int m, vector < vector <int> > * field_p);

void print(int n, int m, vector < vector <int> > * field_p);

int main()
{
	int n = 0, m = 0;
	int count = 1;
	cin >> n >> m;

	while (n != 0 && m != 0)
	{
		vector < vector <int> > field(n, vector <int> (m));
		
		char c;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> c; 
				if (c == '*')
				{
					field[i][j] = c;
					inc_neighbors(i, j, n, m, &field);	
				}
			}
		}

		cout << "Field #" << count <<":" << "\n";
		count += 1;
		print(n, m, &field);
		cin >> n >> m;
		if (n != 0 && m != 0)
				cout << "\n";
	}	
}

void print(int n, int m, vector < vector <int> > * field_p)
{
	for (int i = 0; i < n; i++ )
	{
		for (int j = 0; j < m; j++)
		{
			int f = (*field_p)[i][j];
			if ((char)f == '*')
			{
				cout << (char)f;
			}
			else
			{
				cout << f;
			}
		}
		cout << "\n";
	}
}

void inc_neighbors(int i, int j, int n, int m, vector < vector <int> > * field_p)
{
	for (int row = i - 1; row <= i + 1; row++)
	{
		for (int col = j - 1; col <= j + 1; col++)
		{
			if (row >= 0 && row < n && col >= 0 && col < m )
			{
				int f = (*field_p)[row][col];
				if (!(row == i && col == j) && (char)f != '*')
				{
					(*field_p)[row][col] += 1;
					//cout << row << " " << col << " " << (*field_p)[row][col] << "\n";
				}
			}	
		}
	}
}
