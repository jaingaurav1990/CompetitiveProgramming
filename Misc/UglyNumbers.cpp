/**
 * Problem: Find the nth ugly number
 * Author: gjain
 * Date: Jul 21, 2014
 */

#include <iostream>
#include <set>

using namespace std;

int main() {
    int n = 0;
    cin >> n;

    // Use greater for priority queue to act as a min-heap
    set<int> min_heap;
    min_heap.insert(1);

    for (int i = 1; i <= n; i++) {
        // Following returns the element of the set as sets are ordered
        set<int>::iterator it = min_heap.begin();
        int ith_ugly = (*it);
        min_heap.erase(it);

        if (i == n) {
            cout << ith_ugly << "\n";
        }

        min_heap.insert(2 * ith_ugly);
        min_heap.insert(3 * ith_ugly);
        min_heap.insert(5 * ith_ugly);
    }
    return 0;
}
