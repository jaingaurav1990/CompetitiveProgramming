/**
 * Problem: Largest Palindrome Product
 * Author: gjain
 * Date: Jul 21, 2014 
 * Note: It's raining! Yay!
 */

#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

bool is_palindrome(int to_check) {
    string str;
    ostringstream parsed;
    parsed << to_check;
    str = parsed.str();
    string orig = str;
    reverse(str.begin(), str.end());
    if (str.compare(orig) != 0) {
        return false;
    }
    else {
        return true;
    }
}

int main() {
    int max_prod = 1;
    for (int i = 999; i >= 100; i--) {
        for (int j = 999; j >= 100; j--) {
            int prod = i * j;
            if (is_palindrome(prod) && prod > max_prod) {
                max_prod = prod;
            }
        }
    }

    cout << max_prod << "\n";
}
