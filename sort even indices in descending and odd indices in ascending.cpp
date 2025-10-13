/*
 * Sort Even Indices in Descending and Odd Indices in Ascending Order
 * 
 * This program sorts an array in a specific pattern: elements at even indices (0, 2, 4, ...)
 * are sorted in descending order, while elements at odd indices (1, 3, 5, ...) are sorted
 * in ascending order. It separates the array into two subarrays based on index parity,
 * sorts each subarray independently, and then interleaves them back together.
 * Input consists of array size followed by the array elements. Output displays the
 * array with the specified sorting pattern applied.
 */

// You are using GCC
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void sortForward(int size, int arr[]) {
    for (int h = 0 ; h < size-1 ; h ++) {
        for (int i = 0 ; i < size-1 ; i ++) {
            if (arr[i]>arr[i+1]) {
                swap(arr[i],arr[i+1]);
            }
        }
    }
}
void sortBackward(int size, int arr[]) {
    for (int h = 0 ; h < size-1 ; h ++) {
        for (int i = 0 ; i < size-1 ; i ++) {
            if (arr[i]<arr[i+1]) {
                swap(arr[i],arr[i+1]);
            }
        }
    }
    
}
int main() {
    int size;
    cin>>size;
    int length1,length2;
    if (size%2 == 0) {
        length1 = size/2;
        length2 = size/2;
    }
    else {
        length1 = (size/2) + 1;
        length2 = size/2;
        
    }
    int arr1[length1];
    int arr2[length2];
    for (int i = 0 ; i < size ; i ++) {
        if (i%2 == 0) {
            cin>>arr1[i/2];
        }
        else {
            cin>>arr2[i/2];
            
        }
    }
    sortForward(length2,arr2);
    sortBackward(length1,arr1);
    for (int i = 0 ; i < size ; i ++) {
        if (i%2 == 0) {
            cout<<arr1[i/2]<<" ";
        }
        else {
            cout<<arr2[i/2]<<" ";
            
        }
    }
}