/*
 * Barcode Sorting Implementation
 * 
 * This program sorts barcode numbers using bubble sort algorithm in ascending order.
 * It reads barcode numbers as long integers and applies bubble sort with early termination
 * optimization to stop when no more swaps are needed. The algorithm compares adjacent
 * elements and swaps them if they are in wrong order. Input consists of array size
 * followed by barcode numbers. Output displays sorted barcode numbers, one per line.
 */

// You are using GCC
// You are using GCC
#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;
int main() {
    int size;
    cin>>size;
    cin.ignore();
    long int arr[size];
    for (int i = 0 ; i < size ; i ++) {
        cin>>arr[i];
        cin.ignore();
    }
    
    bool swaps;
    while (true) {
        swaps = false;
        for (int i = 0 ; i < size-1 ; i ++) {
            if (arr[i]>arr[i+1]) {
                swap(arr[i],arr[i+1]);
                swaps = true;
            }
        }
        if (swaps == false) {
            break;
        }
    }
    cout<<"Sorted barcode numbers:"<<endl;
    for (int i = 0 ; i < size ; i ++) {
        cout<<arr[i]<<endl;
    }
}