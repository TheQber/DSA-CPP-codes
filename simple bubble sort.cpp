/*
 * Simple Bubble Sort Implementation
 * 
 * This program implements the bubble sort algorithm to sort an array of integers in ascending order.
 * It compares adjacent elements and swaps them if they are in the wrong order, repeating this process
 * until no more swaps are needed. The algorithm includes optimization to stop early when the array
 * is already sorted. Input consists of array size followed by the array elements.
 * Output displays the sorted array elements separated by spaces.
 */

// You are using GCC
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
    int size,val;
    cin>>size;
    int arr[size];
    for (int i = 0 ; i < size ; i ++) {
        cin>>arr[i];
    }
    int count = 0;
    int swapNumber = 0;
    while (true) {
        bool swaps = false;
        count++;
        swapNumber = 0;
        for (int i = 0 ; i < size-1 ; i ++) {
            if (arr[i]>arr[i+1]) {
                swap(arr[i],arr[i+1]);
                swaps = true;
                swapNumber++;
            }
        }
        //cout<<"Loop number: "<<count<<"; Swaps per loop: "<<swapNumber<<endl;
        if (swaps == false) {
            break;
        }
    }
    for (int j = 0 ; j < size ; j ++) {
        cout<<arr[j]<<" ";
    }
}