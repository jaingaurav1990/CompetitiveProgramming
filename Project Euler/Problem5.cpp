/**
 * Problem: Least Common Multiple
 * Author: gjain
 * Date: July 22, 2014
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    if (b < a) {
        swap(a, b);
    }

    int rem = b % a;
    if (rem == 0) {
        return a;
    }
    else {
        return gcd(rem, a);
    }
}

int lcm(int a, int b) {
    return (a * b) / (gcd(a,b));
}

int lcm_recursive(int a, vector <int>& num, int start) {
    if (num.size() - 1 == start) {
        return lcm(a, num[start]);
    }
    else {
        return lcm_recursive(lcm(a, num[start]), num, start + 1);
    }

}
int main() {
    vector <int> num;
    for (int i = 2; i <= 19; i++) {
        num.push_back(i);
    }

    cout << lcm_recursive(20, num, 0) << "\n";
}
