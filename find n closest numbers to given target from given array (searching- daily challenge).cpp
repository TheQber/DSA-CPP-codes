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