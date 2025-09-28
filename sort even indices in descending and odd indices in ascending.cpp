// You are using GCC
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void sortForward(int size, int arr[]) {
    for (int h = 0 ; h < size-1 ; h ++) {
        for (int i = 0 ; i < size-1 ; i ++) {
            if (arr[i]>arr[i+1]) {
                swap(arr[i],arr[i+1]);
            }
        }
    }
}
void sortBackward(int size, int arr[]) {
    for (int h = 0 ; h < size-1 ; h ++) {
        for (int i = 0 ; i < size-1 ; i ++) {
            if (arr[i]<arr[i+1]) {
                swap(arr[i],arr[i+1]);
            }
        }
    }
    
}
int main() {
    int size;
    cin>>size;
    int length1,length2;
    if (size%2 == 0) {
        length1 = size/2;
        length2 = size/2;
    }
    else {
        length1 = (size/2) + 1;
        length2 = size/2;
        
    }
    int arr1[length1];
    int arr2[length2];
    for (int i = 0 ; i < size ; i ++) {
        if (i%2 == 0) {
            cin>>arr1[i/2];
        }
        else {
            cin>>arr2[i/2];
            
        }
    }
    sortForward(length2,arr2);
    sortBackward(length1,arr1);
    for (int i = 0 ; i < size ; i ++) {
        if (i%2 == 0) {
            cout<<arr1[i/2]<<" ";
        }
        else {
            cout<<arr2[i/2]<<" ";
            
        }
    }
}