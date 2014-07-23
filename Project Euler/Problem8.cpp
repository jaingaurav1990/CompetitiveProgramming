/**
 * Problem: Largest Product in a Series
 * Author: gjain
 * Date: July 23, 2014
 */

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

#define REP(i, n) for (int i = 0; i < n; i++)

int main() {
    vector < int > digit;
    string line;
    while (getline(cin, line)) {
        int len = line.size();
        REP(i, len) {
            int dig =  line[i] - '0';
            digit.push_back(dig);
            cout << " (" << line[i] << "," << dig << ") ";
        }
        cout << "\n";
    }

    signed long long max_product = 1;
    int series_len = 13;
    for (int i = 0; i < series_len; i++) {
        max_product *= digit[i];
    }
    signed long long product = max_product;
    for (int i = 1; i <= (digit.size() - series_len); i++) {
        if (digit[i - 1] != 0) {
            product = (product / digit[i - 1]) * digit[i + series_len - 1];
        }
        else {
            product = 1;
            for (int j = i; j < i + series_len; j++) {
                product *= digit[j];
            }
        }
        if (product > max_product) {
                max_product = product;
        }
    }
    cout << max_product << "\n";
    return 0;
}
