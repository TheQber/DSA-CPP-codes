/*
 * Find N Closest Numbers to Target (Searching - Daily Challenge)
 * 
 * This program finds the N closest numbers to a target value in an array by removing
 * the target if present and sorting remaining elements by their distance from the target.
 * It uses a custom sorting approach that considers both absolute difference and value
 * magnitude for tie-breaking. Elements with equal distance are sorted in descending order.
 * Input consists of array size, array elements, target value, and number of closest
 * elements to find. Output displays the N closest numbers to the target.
 */

// You are using GCC
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int difference (int a, int b) {
    if (a>=b) {
        return a-b;
    }
    else {
        return b-a;
    }
}
int main() {
    int size;
    cin>>size;
    int arr[size];
    for (int i = 0 ; i < size ; i ++) {
        cin>>arr[i];
    }
    // for (int i = 0 ; i < size ; i ++) {
    //     cout<<arr[i]<<" ";
    // }
    int target;
    cin>>target;
    for (int i = 0 ; i < size ; i ++) {
        if (arr[i] == target) {
            for (int j = i ; j < size-1 ; j ++) {
                swap(arr[j],arr[j+1]);
            }
            arr[size-1] = 9999;
            size--;
            break;
        }
    }
    for (int i = 0 ; i < size ; i ++) {
        for (int j = 0 ; j < size-1 ; j ++) {
            if (difference(target,arr[j])>difference(target,arr[j+1])) {
                swap(arr[j],arr[j+1]);
            }
            else if (difference(target,arr[j]) == difference(target,arr[j+1])) {
                if (arr[j+1]>arr[j]) swap(arr[j],arr[j+1]);
            }
            
        }
    }
    int num;
    cin>>num;
    if (num>size) num = size;
    for (int i = 0 ; i < num ; i ++) {
        cout<<arr[i]<<" ";
    }
}