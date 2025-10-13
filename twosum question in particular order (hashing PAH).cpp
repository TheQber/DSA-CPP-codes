/*
 * Two Sum Problem with Hashing (PAH - Programming Assignment Helper)
 * 
 * This program solves the Two Sum problem using a hash table approach for efficient
 * lookups. It finds pairs of numbers in an array that sum to a target value using
 * a boolean array as a hash table. The algorithm processes each element and checks
 * if its complement (target - current element) exists in the hash table. Input consists
 * of array size, array elements, and target sum. Output displays all valid pairs
 * that sum to the target or indicates if no such pairs exist.
 */

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[100];
    for (int i = 0; i < n; ++i) cin >> arr[i];
    int target;
    cin >> target;

    // Values in array are in range 0..100 per constraints
    bool present[101] = {false};
    bool found = false;

    for (int i = 0; i < n; ++i) {
        int x = arr[i];
        int comp = target - x;
        if (comp >= 0 && comp <= 100 && present[comp]) {
            cout << "Pairs: " << x << " and " << comp << "\n";
            found = true;
        }
        // mark current number as seen for future elements
        if (x >= 0 && x <= 100) present[x] = true;
    }

    if (!found) cout << "No such pairs\n";
    return 0;
}
