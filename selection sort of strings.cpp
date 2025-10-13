/*
 * Selection Sort for String Array with Iteration Display
 * 
 * This program sorts an array of strings using selection sort algorithm and displays
 * the sorting process step by step. It finds the minimum string in each iteration
 * and swaps it with the current position. The algorithm includes detailed output
 * showing the array state after each iteration to demonstrate the sorting process.
 * Input consists of array size followed by string values. Output shows initial order,
 * array after each iteration, and final sorted order.
 */

// You are using GCC
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
    int size;
    cin>>size;
    string arr[size];
    int count = 1;
    for (int i = 0 ; i < size ; i ++) {
        cin>>arr[i];
    }
    cout<<"Initial order: ";
    for (int i = 0 ; i < size ; i ++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int minIndex;
    string currentSmallest;
    bool swapNecessary;
    for (int j = 0 ; j < size-1 ; j ++) {
        swapNecessary = false;
        currentSmallest = "zzzzzzzzzzzzzzzzz";
        for (int k = j+1 ; k < size ; k ++) {
            if (arr[j]>arr[k]) {
                swapNecessary = true;
                if (arr[k]<currentSmallest) {
                    currentSmallest = arr[k];
                    minIndex = k;
                }
            }
            
        }
        if (swapNecessary) {
            swap(arr[j],arr[minIndex]);
        }
        cout<<"After Iteration "<<count<<": ";
        for (int t = 0 ; t < size ; t ++) {
            cout<<arr[t]<<" ";
        }
        cout<<endl;
        count++;
    }
    cout<<"Sorted order: ";
    for (int i = 0 ; i < size ; i ++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}