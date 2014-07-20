/**
 * Author: gjain
 * Problem: Even Fibonacci numbers
 * Date: Jul 20, 2014
 * Note: Next weekend should be the 5-lake hike
 */

#include <iostream>

using namespace std;

#define sll signed long long 

int main() {
    sll sum = 2;
    int fib_prev1 = 1;
    int fib_prev2 = 2;
    while (true) {
        int fib = fib_prev1 + fib_prev2;
        if (fib > 4*1000000) {
            break;
        }
        if (fib % 2 == 0) {
            sum += fib;
        }
        fib_prev1 = fib_prev2;
        fib_prev2 = fib;
    }

    cout << sum << "\n";
}
