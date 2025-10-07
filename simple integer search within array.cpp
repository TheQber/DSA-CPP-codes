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