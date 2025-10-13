/*
 * Merge Sort with Iteration Display
 * 
 * This program implements merge sort algorithm using divide-and-conquer approach to sort an array
 * of integers in ascending order. It recursively divides the array into halves, sorts each half,
 * and then merges the sorted halves back together. The program displays the array state after
 * each merge operation to show the sorting progress. Input consists of array size followed by
 * the array elements. Output shows the given array, array after each merge iteration, and final sorted array.
 */

#include <iostream>
#include <vector>
using namespace std;

int iteration = 0; // global counter

// Function to print the array
void printArray(const vector<int> &arr) {
    for (int x : arr) {
        cout << x << " ";
    }
    cout << "\n";
}

// Merge function
void merge(vector<int> &arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    // print array after every merge
    iteration++;
    cout << "After iteration " << iteration << "\n";
    printArray(arr);
}

// Merge sort function
void mergeSort(vector<int> &arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Given Array\n";
    printArray(arr);

    mergeSort(arr, 0, n - 1);

    cout << "Sorted Array\n";
    printArray(arr);

    return 0;
}
