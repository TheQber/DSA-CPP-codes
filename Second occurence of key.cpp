// You are using GCC
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
            }
            else if (val2 == -1) {
                val2 = i;
            }
            //return 0;
        }
    }
    if (val2 != -1) {
        cout<<"The index of the second occurrence of the key value is: "<<val2;
        return 0;
    }
    if (val == -1) {
        cout<<"Key not found.";
        return 0;
    }
    cout<<"Key found only once.";
    
}