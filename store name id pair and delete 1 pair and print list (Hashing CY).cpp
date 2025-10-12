// You are using GCC
#include <iostream>
#include <vector>
using namespace std;
struct Dictionary {
    string data;
    string id;
};
int main() {
    int size;
    cin>>size;
    string name,id;
    vector<Dictionary> arr;
    for (int i = 0 ; i < size ; i ++) {
        cin>>name>>id;
        Dictionary d = {name,id};
        arr.push_back(d);
    }
    // for (int i = 0 ; i < size ; i ++) {
    //     cout<<"Key: "<<arr[i].data<<"; Value: "<<arr[i].id<<endl;
        
    // }
    string search;
    cin>>search;
    bool found = false;
    for (int i = 0 ; i < size ; i ++) {
        if (arr[i].data == search) {
            cout<<"The given key is removed!"<<endl;
            found = true;
        }
    }
    if (!found) {
        cout<<"The given key is not found!"<<endl;
    }
    for (int i = 0 ; i < size ; i ++) {
        if (arr[i].data != search) {
            cout<<"Key: "<<arr[i].data<<"; Value: "<<arr[i].id<<endl;
        }
    }
}