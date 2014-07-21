/**
 * Problem: Largest Prime Factor
 * Author: gjain
 * Date: Jul 21, 2014
 * Note: Nice weather outside. It's raining :)
 */

#include <iostream>
#include <cmath>
#include <vector>
#include <set>

using namespace std;

int main() {
    double n = 0;
    cin >> n;

    signed long long to_check = static_cast<signed long long>(n);

    double nroot = sqrt(n);
    int n_root = ceil(nroot);

    // Construct the seive of Erastothenes
    vector <int> prime(n_root + 1);
    set<int> primes;
    for (int i = 2; i <= n_root + 1; i++) {
        if (prime[i] == 0) { // is prime
            primes.insert(i);
            int next = 2 * i;
            for (next = 2 * i; next <= n_root + 1; next = next + i) {
                prime[next] = 1;
            }
        }
    } 

    for (set<int>::reverse_iterator rit = primes.rbegin(); rit != primes.rend(); ++rit) {
       if (to_check % (*rit) == 0) {
           cout << "Max Prime Factor: " << (*rit) << "\n";
           return 0;
       } 
    }

    // Number is prime
    cout << "Max Prime Factor (itself): " << to_check << "\n";
    return 0;
}
