/*
 * Search Array of Numbers Within Another Array (Inventory System)
 * 
 * This program simulates an inventory search system where it searches for multiple items
 * from one array within another array (inventory). For each search item, it performs a
 * linear search and reports the position (1-indexed) if found or indicates if the item
 * is not in the inventory. Input consists of inventory size, inventory items, search array
 * size, and search items. Output shows the position of each found item or "not found" message.
 */

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