/**
 * Problem: Multiples of 3 and 5
 * Author: gjain
 * Date: Jul 20, 2014
 */

#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    set<int> multiples;
    int i = 1;
    bool done3 = false;
    bool done5 = false;
    while (true) {
        int multiple = 3 * i;
        if (multiple >= 1000) {
            done3 = true;
        }
        else {
            multiples.insert(multiple);
        }

        multiple = 5 * i;
        if (multiple >= 1000) {
            done5 = true;
        }
        else {
            multiples.insert(multiple);
        }

        if (done3 && done5) {
            break;
        }
        i = i + 1;
    }

    int sum = 0;
    for (set<int>::iterator it = multiples.begin(); it != multiples.end(); it++) {
        sum = sum + (*it);
    }

    cout << sum << "\n";
}
