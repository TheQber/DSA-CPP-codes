/*
 * Find Number of Elements Greater Than Median (Mentor Analysis)
 * 
 * This program counts how many elements in an array are greater than the median value,
 * similar to analyzing mentor performance above median level. It first sorts the array
 * using selection sort, calculates the median, and then counts elements that exceed
 * the median value. For even-length arrays, it uses the lower median; for odd-length
 * arrays, it uses the middle element. Input consists of array size followed by the numbers.
 * Output displays the sorted array and the count of elements greater than the median.
 */

// You are using GCC
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
    int sum = 0;
    // cout<<length<<endl;
    if (size%2 == 0) {
        for (int i = length ; i < size ; i ++) {
            if (arr[i]>arr[length-1]) {
                sum++;
            }
        }
    }
    else {
        for (int i = length+1 ; i < size ; i ++) {
            if (arr[i]>arr[length]) {
                sum++;
            }
        }
    }
    cout<<sum;
}