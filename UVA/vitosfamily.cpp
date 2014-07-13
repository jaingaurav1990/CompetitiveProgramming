/*
 * Problem Code: 10041
 * Problem Name: Vito's Family
 *
 * Tonight is the night. Germany meets Argentina
 * in the World Cup Finals, 2014
 */
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define REP(i, n) for (int i = 0; i < n; i++)
#define V(x) vector<int> 

int getSumDev(int cand, V(int) & number) {
    int size = number.size();
    int sum = 0;
    REP(i, size) {
        sum += abs((cand - number[i]));
    }
    return sum;
}

int main() {
    int T = 0;
    cin >> T;
    while (T--) {
        int r = 0;
        cin >> r;
        V(int) number(r);
        REP(i, r) {
            cin >> number[i];
        }
        sort(number.begin(), number.end());
        if (r % 2 == 0) {
            int cand1 = number[r / 2];
            int cand2 = number[r / 2 - 1];
            int sumdev1 = getSumDev(cand1, number);
            int sumdev2 = getSumDev(cand2, number);
            cout << min(sumdev1, sumdev2) << "\n";
        }
        else {
            int cand = number[r / 2];
            cout << getSumDev(cand, number) << "\n";
        }
    }
    return 0;
}
