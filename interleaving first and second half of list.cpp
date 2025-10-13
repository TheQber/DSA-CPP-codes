/*
 * Interleave First and Second Half of Array
 * 
 * This program interleaves the first and second halves of an array, displaying
 * elements in alternating order from each half. For even-length arrays, it takes
 * equal halves, and for odd-length arrays, the first half gets one extra element.
 * The algorithm prints elements from both halves in alternating fashion.
 * Input consists of array size followed by the array elements.
 * Output displays the interleaved sequence.
 */

// You are using GCC
#include <iostream>
using namespace std;
int main() {
    int size;
    cin>>size;
    int arr[size];
    for (int i = 0 ; i < size ; i ++) {
        cin>>arr[i];
    }
    int half;
    if (size%2 == 0) {
        half = size/2;
    }
    else {
        half = (size+1)/2;
    }
    for (int i = 0 ; i < half ; i ++) {
        cout<<arr[i]<<" ";
        cout<<arr[i+half]<<" ";
    }
}