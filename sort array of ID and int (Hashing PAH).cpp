// You are using GCC
#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
int main() {
    int size;
    cin>>size;
    string word;
    int val;
    vector<string> arr1;
    vector<int> arr2;
    for (int i = 0 ; i < size ; i ++) {
        cin>>word>>val;
        arr1.push_back(word);
        arr2.push_back(val);
    }
    for (int t = 0 ; t < size ; t ++) {
        for (int i = 0 ; i < size-1 ; i ++) {
            if (arr1[i]>arr1[i+1]) {
                swap(arr1[i],arr1[i+1]);
                swap(arr2[i],arr2[i+1]);
            }
        }
    }
    for (int i = 0 ; i < size ; i ++) {
        cout<<arr1[i]<<" "<<arr2[i]<<endl;
    }
}