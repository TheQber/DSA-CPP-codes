/*
 * Find First and Last Occurrence of Number in Array
 * 
 * This program finds the first and last occurrence positions of a target number in an array.
 * It uses a single pass through the array to track both the first occurrence (when found initially)
 * and the last occurrence (continuously updated when the target is found again). Input consists
 * of array size, followed by array elements, and finally the target number to search.
 * Output displays the first and last occurrence indices, or "NO OCCURRENCES" if not found.
 */

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
                val2 = i;
            }
            else {
                val2 = i;
            }
            //return 0;
        }
    }
    if (val != -1) {
        cout<<val<<" "<<val2;
        return 0;
    }
    cout<<"NO OCCURRENCES";
    
}