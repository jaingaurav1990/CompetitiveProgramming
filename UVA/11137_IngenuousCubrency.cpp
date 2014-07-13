#include <iostream>
#include <vector>

using namespace std;

#define MAX_AMOUNT 10000
#define REP(i, n) for (int i = 0; i < n; i++)

int main()
{
    vector <int> ways(MAX_AMOUNT);
    ways[0] = 1; // Exactly one way to have nothing
    vector <int> coins;
    for (int i = 1; i*i*i < MAX_AMOUNT; i++) {
        coins.push_back(i*i*i);
    }

    for (int amount = 1; amount < MAX_AMOUNT; amount++) {
        int total_ways = 0;
        int num_coins = coins.size();
        for (int i = 0; i < num_coins; i++) {
            int coin = coins[i];
            if (amount - coin >= 0) {
                total_ways += ways[amount - coin];
                cout << "(" << amount << "," << coin << ")\n";
            }
            else {
                break;
            }
        }
        ways[amount] = total_ways;
        cout << "ways[" << amount << "] = " << total_ways << "\n";
    }

    int amount = 0;
    while (cin >> amount) {
        cout << ways[amount] << "\n";
    }

    return 0;
}
