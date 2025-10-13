/*
 * Find Person with Most Votes (Hashing - Daily Challenge)
 * 
 * This program finds the person with the most votes using a dictionary-like structure
 * to count vote frequencies. It maintains a vector of Dictionary structures where each
 * entry contains a candidate name and vote count. After counting all votes, it finds
 * the candidate with the highest vote count, with lexicographically smaller names
 * breaking ties. Input consists of number of votes followed by candidate names.
 * Output displays the name of the candidate with the most votes.
 */

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
