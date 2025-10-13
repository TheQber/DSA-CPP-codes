/*
 * Element Frequency Counter Using Dictionary Structure (Hashing PAH)
 * 
 * This program counts the frequency of each element in an array using a dictionary-like
 * structure with value-count pairs. It maintains a vector of Dictionary structures
 * where each entry contains a data value and its count. The algorithm searches for
 * existing values and increments their count, or creates new entries for unseen values.
 * Input consists of array size followed by the integer values. Output displays each
 * unique value with its corresponding frequency count.
 */

// You are using GCC
#include <iostream>
#include <vector>
using namespace std;
struct Dictionary {
    int data;
    int count;
};
int main() {
    int size,val;
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
    for (int i = 0 ; i < arr1.size() ; i ++) {
        cout<<arr1[i].data<<" : "<<arr1[i].count<<endl;
    }
}
