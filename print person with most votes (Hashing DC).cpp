// You are using GCC
// You are using GCC
#include <iostream>
#include <vector>
using namespace std;
struct Dictionary {
    string data;
    int count;
};
int main() {
    int size;
    string val;
    cin>>size;
    vector<Dictionary> arr1;
    for (int i = 0 ; i < size ; i ++) {
        cin>>val;
        bool found = false;
        for (int j = 0 ; j < arr1.size() ; j ++) {
            if (arr1[j].data == val) {
                arr1[j].count++;
                found = true;
                break;
            }
        }
        if (!found) {
            Dictionary d;
            d.data = val;
            d.count = 1;
            arr1.push_back(d);
        }
    }
    int max = 0;
    string biggest = "";
    for (int i = 0 ; i < arr1.size() ; i ++) {
        if (max<arr1[i].count) {
            max = arr1[i].count;
            biggest = arr1[i].data;
        }
        else if (max == arr1[i].count) {
            if (arr1[i].data<biggest) {
                biggest = arr1[i].data;
            }
        }
    }
    cout<<biggest;
}
