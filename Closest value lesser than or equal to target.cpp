/*
 * Find Closest Value Less Than or Equal to Target (Warehouse Search)
 * 
 * This program finds the closest item ID that is less than or equal to a target value
 * in a warehouse inventory system. It searches through an array of item IDs and
 * identifies the largest value that doesn't exceed the target. The algorithm uses
 * a single pass through the array to find the optimal match. Input consists of
 * array size, followed by item IDs, and finally the target value. Output displays
 * the closest matching item ID or indicates if no suitable item exists.
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
    int val = -1, mainVal;
    for (int i = 0 ; i < size ; i ++) {
        if (target >= arr[i]) {
            if (arr[i] <= target && arr[i]>val) {
                
                val = arr[i];
            }
            //return 0;
        }
    }
    if (val != -1) {
        cout<<"The closest item ID less than or equal to "<<target<<" is "<<val;
        return 0;
    }
    cout<<"No closest item with an ID less than or equal to "<<target<<" exists in the warehouse";
    
}