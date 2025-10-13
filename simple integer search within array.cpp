/*
 * Simple Integer Search Within Array
 * 
 * This program performs a linear search to find the first occurrence of a target integer
 * in an array. It traverses the array from beginning to end and returns the index of the
 * first match. The search stops immediately when the target is found. Input consists of
 * array size, followed by array elements, and finally the target number to search.
 * Output displays the index of the first occurrence or indicates if the target is not present.
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
    for (int j = 0 ; j < size ; j ++ ) {
        if (target == arr[j]) {
            cout<<j<<endl;
            return 0;
        }
    }
    cout<<target<<" not present"<<endl;
}