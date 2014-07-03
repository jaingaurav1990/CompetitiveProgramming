#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define REP(i, n) for (int i = 0; i < n; i++)

int main()
{
    int testcases = 0;
    cin >> testcases;
    while (testcases--) {
        int N = 0, M = 0;
        cin >> N >> M;
        vector < vector<int> > matrix(N, vector<int> (M));
        REP(i, N) {
            REP(j, M) {
                cin >> matrix[i][j];
            }
        }

        vector < vector <int> > pathLengths(N, vector<int> (M));
        int maxLen = 1;
        REP(i, N) {
            REP(j, M) {
                if (i == 0 && j == 0) {
                    pathLengths[i][j] = 1;
                    continue;
                }
                int current = matrix[i][j];
                int top = 0, left = 0;
                int topPathLen = 0, leftPathLen = 0;
                if (i - 1 >= 0) {
                    top = matrix[i-1][j];
                    if (current > top && (pathLengths[i - 1][j] != 0)) {
                        topPathLen = pathLengths[i - 1][j] + 1;
                    }

                }
                if (j - 1 >= 0) {
                    left = matrix[i][j - 1];
                    if (current > left && (pathLengths[i][j - 1] != 0)) {
                        leftPathLen = pathLengths[i][j - 1] + 1;
                    }
                }
                int pathLen = max(topPathLen, leftPathLen);
                pathLengths[i][j] = pathLen;
                if (pathLen > maxLen) {
                    maxLen = pathLen;
                }
            }
        }

        cout << maxLen << "\n";
    }
    return 0;
}
