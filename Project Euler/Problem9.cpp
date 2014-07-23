/**
 * Problem: Special Pythagorean Triplet
 * Author: gjain
 * Date: July 23, 2014
 */

#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;

#define REP(i, n) for (int i = 0; i < n; i++)
#define F first
#define S second

bool check(int c, int a, int b) {
    if ((c * c) == ((a * a) + (b  * b))) {
        return true;
    }
    else {
        return false;
    } 
}

int main() {
    vector < pair <int, pair<int, int> > > two_table;
    for (int a = 1; a <= 500; a++) {
        for (int b = a + 1; a + b < 1000; b++) {
            pair<int, int> tuple = make_pair(a, b);
            pair<int, pair<int, int> > entry = make_pair(a + b, tuple);
            two_table.push_back(entry);
        }
    }
    sort(two_table.begin(), two_table.end());
    int size = two_table.size();
    REP(i, size) {
        int c = 1000 - (two_table[i].F);
        bool is_pythagorean = check(c, two_table[i].S.F, two_table[i].S.S);
        if (is_pythagorean) {
            cout << c <<  " " << two_table[i].S.F << " " << two_table[i].S.S << "\n";
            cout << c * two_table[i].S.F * two_table[i].S.S << "\n";
            return 0;
        }
    }
    return 0;
}
