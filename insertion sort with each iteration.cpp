/*
 * Insertion Sort with Iteration Display
 * 
 * This program implements insertion sort algorithm to sort an array of integers in descending order.
 * It builds the sorted array one element at a time by inserting each element into its correct position
 * among the already sorted elements. The program displays the array state after each iteration,
 * showing the sorting progress. Input consists of array size followed by the array elements.
 * Output shows initial order, array after each iteration, and final sorted order.
 */

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    // Print initial order
    cout << "Initial order: ";
    for (int x : a) cout << x << " ";
    cout << "\n";

    // Insertion sort (descending) with iteration prints
    for (int i = 1; i < n; ++i) {
        int key = a[i];
        int j = i - 1;
        // shift elements smaller than key to the right (to get descending order)
        while (j >= 0 && a[j] < key) {
            a[j + 1] = a[j];
            --j;
        }
        a[j + 1] = key;

        cout << "After Iteration " << i << ": ";
        for (int x : a) cout << x << " ";
        cout << "\n";
    }

    // Final sorted order
    cout << "Sorted order: ";
    for (int x : a) cout << x << " ";
    cout << "\n";

    return 0;
}
