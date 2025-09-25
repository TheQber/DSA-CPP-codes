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