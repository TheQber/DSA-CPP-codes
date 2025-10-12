// You are using GCC
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int size1;
    vector<int> arr1;
    vector<int> arr2;
    cin>>size1;
    for (int i = 0 ; i < size1 ; i ++) {
        int val;
        cin>>val;
        arr1.push_back(val);
    }
    int size2;
    cin>>size2;
    for (int i = 0 ; i < size2 ; i ++) {
        int val;
        cin>>val;
        arr2.push_back(val);
    }
    int count = 0;
    for (int i = 0 ; i < size2 ; i ++) {
        for (int j = 0 ; j < size1 ; j ++) {
            if (arr1[j] == arr2[i]) {
                count++;
                break;
            }
        }
    }
    cout<<count;
}