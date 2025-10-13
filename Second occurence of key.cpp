/*
 * Find Second Occurrence of Key in Array
 * 
 * This program finds the second occurrence of a target value in an array. It tracks
 * both the first and second occurrences of the target element during a single pass
 * through the array. If the element occurs at least twice, it displays the index of
 * the second occurrence. Input consists of array size, followed by array elements,
 * and finally the target number. Output displays the second occurrence index or indicates
 * if the element is not found or found only once.
 */

// You are using GCC
// You are using GCC
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
    int target;
    cin>>target;
    int val = -1,val2 = -1;
    for (int i = 0 ; i < size ; i ++) {
        if (target == arr[i]) {
            if (val == -1) {
                val = i;
            }
            else if (val2 == -1) {
                val2 = i;
            }
            //return 0;
        }
    }
    if (val2 != -1) {
        cout<<"The index of the second occurrence of the key value is: "<<val2;
        return 0;
    }
    if (val == -1) {
        cout<<"Key not found.";
        return 0;
    }
    cout<<"Key found only once.";
    
}