// You are using GCC
// You are using GCC
#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;
int main() {
    int size;
    cin>>size;
    cin.ignore();
    long int arr[size];
    for (int i = 0 ; i < size ; i ++) {
        cin>>arr[i];
        cin.ignore();
    }
    
    bool swaps;
    while (true) {
        swaps = false;
        for (int i = 0 ; i < size-1 ; i ++) {
            if (arr[i]>arr[i+1]) {
                swap(arr[i],arr[i+1]);
                swaps = true;
            }
        }
        if (swaps == false) {
            break;
        }
    }
    cout<<"Sorted barcode numbers:"<<endl;
    for (int i = 0 ; i < size ; i ++) {
        cout<<arr[i]<<endl;
    }
}