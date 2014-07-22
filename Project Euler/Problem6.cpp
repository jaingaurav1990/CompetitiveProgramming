/**
 * Problem: Difference of square of sum and sum of squares
 * Author: gjain
 * Date: July 22, 2014
 */

#include <iostream>

using namespace std;

int main() {
    signed long long result;
    int max = 10;
    cin >> max;
    for (int i = 1; i <= max; i++) {
        for (int j = i + 1; j <= max; j++) {
            result += (i * j);
        }
    }

    cout << 2 * result << "\n";
    return 0;
}
