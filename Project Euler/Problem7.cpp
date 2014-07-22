/**
 * Problem: 10001 st Prime
 * Author: gjain
 * Date: July 22, 2014
 */

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int index = 0;
    cin >> index;

    unsigned long long max_limit = 2;
    while (true) {
        vector <int> primes(max_limit + 1);
        vector <int> prime;
        for (int i = 2; i <= max_limit; i++) {
            if (primes[i] == 0) {
               prime.push_back(i); 
               for (int j = 2 * i; j <= max_limit; j = j + i) {
                   primes[j] = 1;
               }
            }
        }
        if (prime.size() >= index) {
            cout << "Prime number " << index << " : " << prime[index - 1] << "\n";
            return 0;
        }
        else {
            max_limit = 2 * max_limit;
        } 
    }
}
