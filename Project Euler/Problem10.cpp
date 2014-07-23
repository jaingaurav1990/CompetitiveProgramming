/**
 * Problem: Summation of Primes
 * Author: gjain
 * Date: July 23, 2014
 */

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int max = 2 * 1000000;
    vector <int> primes(max + 1);

    signed long long sum = 0;
    for (int i = 2; i <= max; i++) {
        if (primes[i] == 0) { // is prime
            sum += i;
            for (int j = 2 * i; j <= max; j = j + i) {
                primes[j] = 1;
            }
        }
    }

    cout << sum << "\n";
}
