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
    int size2;
    cin>>size2;
    int arr2[size2];
    bool found;
    int pos;
    for (int i = 0 ; i < size2 ; i ++) {
        cin>>arr2[i];
        found = false;
        for (int j = 0 ; j < size ; j ++ ) {
            if (arr2[i] == arr[j]) {
                pos = j;
                found = true;
                break;
            }
        }
        if (found) {
            cout<<arr2[i]<<" found at position "<<pos+1<<endl;
        }
        else {
            cout<<arr2[i]<<" not found in the inventory"<<endl;
        }    
    }
}