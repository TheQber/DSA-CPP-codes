// You are using GCC
// You are using GCC
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
    int size;
    cin>>size;
    int arr[size];
    int count = 1;
    for (int i = 0 ; i < size ; i ++) {
        cin>>arr[i];
    }
    cout<<"Student's height order before sorting: ";
    for (int i = 0 ; i < size ; i ++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int minIndex;
    int currentSmallest;
    bool swapNecessary;
    for (int j = 0 ; j < size-1 ; j ++) {
        swapNecessary = false;
        currentSmallest = 99999;
        for (int k = j+1 ; k < size ; k ++) {
            if (arr[j]>arr[k]) {
                swapNecessary = true;
                if (arr[k]<currentSmallest) {
                    currentSmallest = arr[k];
                    minIndex = k;
                }
            }
            
        }
        if (swapNecessary) {
            swap(arr[j],arr[minIndex]);
        }
        cout<<"Height order of students after iteration "<<count<<": ";
        for (int t = 0 ; t < size ; t ++) {
            cout<<arr[t]<<" ";
        }
        cout<<endl;
        count++;
    }
    cout<<"After final comparison of all students, the height order becomes: ";
    for (int i = 0 ; i < size ; i ++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}