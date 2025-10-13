/*
 * Find Median of Sorted List Using Selection Sort
 * 
 * This program calculates the median of a list of numbers after sorting them using
 * selection sort algorithm. It sorts the array in ascending order and then calculates
 * the median: for even-length arrays, it takes the average of the two middle elements;
 * for odd-length arrays, it takes the middle element. Input consists of array size
 * followed by the numbers. Output displays the sorted array and the calculated median
 * with one decimal place precision.
 */

#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>
using namespace std;
int main() {
    int size;
    cin>>size;
    float arr[size];
    for (int i = 0 ; i < size ; i ++) {
        cin>>arr[i];
    }
    for (int i = 0 ; i < size-1 ; i ++) {
        for (int j = i+1 ; j < size ; j ++) {
            if (arr[j]<arr[i]) {
                swap(arr[j],arr[i]);
            }
        }
    }
    for (int i = 0 ; i < size ; i ++ ) { 
        cout<<arr[i]<<" ";    
        
    }
    cout<<endl;
    int length = size/2;
    // cout<<length<<endl;
    if (size%2 == 0) {
        cout<<fixed<<setprecision(1)<<(arr[length]+arr[length-1])/2;
    }
    else {
        cout<<fixed<<setprecision(1)<<(arr[length]);
    }
}