/*
 * Find Value That Occurs Odd Number of Times (Hashing - Daily Challenge)
 * 
 * This program finds the value that appears an odd number of times in an array using
 * a dictionary-like structure to count frequencies. It maintains a vector of Dictionary
 * structures where each entry contains a data value and its count. After counting all
 * frequencies, it searches for the element with an odd count. Input consists of array
 * size followed by the integer values. Output displays the value that occurs an odd
 * number of times, or -1 if no such value exists.
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
    // int output = -1;
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
    int output = -1;
    for (int i = 0 ; i < arr1.size() ; i ++) {
        if (arr1[i].count%2 != 0) {
            output = arr1[i].data;
        }
    }
    cout<<output;
}
