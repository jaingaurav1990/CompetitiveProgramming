/*
 * Problem Code: 120
 * Problem Name: Stacks of Flapjacks
 */
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

#define REP(i, n) for (int i = 0; i < n; i++)
#define V(x) vector <x>
#define DEBUG(x) for (int i = 0; i < x.size(); i++) { cout << x[i] << " "; } cout << "\n";

V(int) getFlipSequence(V(int) & pizza) {
    V(int) flipSequence;
    V(int) sorted = pizza;
    sort(sorted.begin(), sorted.end());

    int size = pizza.size();
    for (int i = size - 1; i >= 0; i--) {
        if (sorted[i] != pizza[i]) {
            // Flips required
            int item = sorted[i];
            int curr_pos = 0;
            REP(j, i) {
                if (pizza[j] == item) {
                    curr_pos = j;
                    break;
                }
            }
            if (curr_pos != 0) {
                // Item not at top. Need a flip to bring it at top
                int flip = size - curr_pos;
                flipSequence.push_back(flip);
                // Reverse the sub-array
                reverse(pizza.begin(), pizza.begin() + curr_pos + 1);
            }
            // Now, the big item is on top of stack. One more flip to put it 
            // in its right place
            int flip = size - i;
            flipSequence.push_back(flip);
            reverse(pizza.begin(), pizza.begin() + i + 1);
        }
    }
    return flipSequence;
}
int main() {
    // Use the standard line-reading idiom
    // http://stackoverflow.com/questions/8116808/read-integers-from-a-text-file-with-c-ifstream  
    string line;
    while (getline(cin, line)) {
        istringstream iss(line);
        int n;
        V(int) pizza;
        while (iss >> n) {
            pizza.push_back(n);
        }
        //DEBUG(pizza);
        int num_pizzas = pizza.size();
        REP(i, num_pizzas) {
            cout << pizza[i];
            if (i != num_pizzas - 1) {
                cout << " ";
            }
            else {
                cout << "\n";
            }
        }
        V(int) flips = getFlipSequence(pizza);
        if (flips.size() == 0) {
            cout << "0\n";
        }
        else {
            int size = flips.size();
            REP(i, size) {
                cout << flips[i] << " ";
            }
            cout << "0\n";
        }
    }
    return 0;
}
