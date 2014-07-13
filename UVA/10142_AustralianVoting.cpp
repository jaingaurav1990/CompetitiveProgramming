#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	int cases = 0;
	string str;
	getline(cin, str);
	stringstream ss(str);
    ss >> cases;

	// Consume blank line
	getline(cin, str);
	while (cases--)
	{
		int num = 0;
		getline(cin, str);
		stringstream ss1(str);
	    ss1	>> num;

		vector <string> names(num);

		for (int i = 0; i < num; i++)
		{
			getline(cin, names[i]);	
		}	

		vector < vector <int> > all_votes(1000, vector <int> (num));
		int votecount = 0;
		string line;
		while (getline(cin, line))
		{
			stringstream ss2(line);
			if (line != "")
			{
				vector <int> vote(num);
				for (int j = 0; j < num; j++)
				{
					ss2 >> vote[j];	
				}

				all_votes[votecount] = vote;
				votecount++;
			}
			else
			{
					break;
			}
		}

		/*
		for (int i = 0; i < num; i++)
		{
			cout << names[i];
		}
		for (int i = 0; i < votecount; i++)
		{
			for (int j = 0; j < num; j++)
			{
					cout << all_votes[i][j] << " ";
			}
			cout << "\n";

		}
		*/
		// Go through first choice of each voter
		vector <int> candidate(num);
		bool decided = false;
		vector < int > eliminated;

			for (int i = 0; i < num; i++)
			{
				candidate[i] = 0;
			}

			for (int i = 0; i < votecount; i++)
			{
				int vote_pos = 0;
				int vote_for = all_votes[i][vote_pos] - 1;
				while (find(eliminated.begin(), eliminated.end(), vote_for) != eliminated.end())
				{
					vote_pos++;
					vote_for = all_votes[i][vote_pos] - 1;
				}

				candidate[vote_for] += 1;
				voted_for[i] = vote_for;
			}
			
			/*
			for (int i = 0; i < num; i++)
			{
				cout << i << ":" << candidate[i] << "\n";
			}
			*/
		while (!decided)
		{
			int thresh = (votecount + 1)/2;
			int min = candidate[0];
			int all_tied = true;
			for (int i = 0; i < num; i++)
			{
				if (candidate[i] < min)
				{
					min = candidate[i];
				}
				if (candidate[i] != candidate[0])
				{
					all_tied = false;
				}
			}

			if (all_tied)
			{
				for (int i = 0; i < num; i++)
				{
					if (find(eliminated.begin(), eliminated.end(), i) == eliminated.end())
					{
						cout << names[i] << "\n";
					}
				}
				decided = true;
				continue;
			}

			for (int i = 0; i < num; i++)
			{
				//cout << "Checking for votes greater than " << thresh << "\n";
				if (candidate[i] >= thresh)
				{
					decided = true;
					cout << names[i] << "\n";
					break;
				}
				else if (candidate[i] == min)
				{
					// Eliminate this candidate
					eliminated.push_back(i);
					for (int j = 0; j < votecount; j++)
					{
						if (voted_for[j] - 1 == i)
						{
							int vote_pos = 0;
							int vote_for = all_votes[j][vote_pos] - 1;
							while (find(eliminated.begin(), eliminated.end(), vote_for) != eliminated.end)
							{
								vote_pos++;
								vote_for = all_votes[j][vote_pos];
							}
							candidate[vote_for] += 1;
						}

					}
				}
			}
		}

		cout << "\n";

	}	
}
