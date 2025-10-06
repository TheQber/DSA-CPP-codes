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
    int half;
    if (size%2 == 0) {
        half = size/2;
    }
    else {
        half = (size+1)/2;
    }
    for (int i = 0 ; i < half ; i ++) {
        cout<<arr[i]<<" ";
        cout<<arr[i+half]<<" ";
    }
}