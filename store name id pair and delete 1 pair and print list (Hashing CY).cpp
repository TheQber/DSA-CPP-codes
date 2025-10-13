/*
 * Store Name-ID Pairs and Delete One Pair (Hashing CY)
 * 
 * This program manages a collection of name-ID pairs using a vector of Dictionary
 * structures. It allows searching for a specific name and removing it from the
 * collection, then displays all remaining pairs. The implementation simulates
 * a simple hash table-like behavior for storing and retrieving key-value pairs.
 * Input consists of number of pairs, followed by name-ID pairs, and finally
 * a search name to delete. Output shows deletion confirmation and remaining pairs.
 */

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