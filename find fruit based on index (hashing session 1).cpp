/*
 * Hash Table Implementation for Key-Value Lookup (Hashing Session 1)
 * 
 * This program implements a hash table for storing and searching key-value pairs
 * using linear probing for collision resolution. It uses a polynomial hash function
 * (31 * hash + character) to compute hash values for string keys. The implementation
 * supports insertion of key-value pairs and searching for existing keys. Input consists
 * of number of entries, followed by key-value pairs, and finally a search key.
 * Output indicates whether the search key exists in the hash table or not.
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int TABLE_SIZE = 100; // sufficient since n ≤ 30

struct Entry {
    string key;
    int value;
    bool occupied;
};

int computeHash(const string &key) {
    long long hashValue = 0;
    for (char c : key) {
        hashValue = 31 * hashValue + c;
    }
    return hashValue % TABLE_SIZE;
}

int main() {
    int n;
    cin >> n;

    vector<Entry> hashTable(TABLE_SIZE, {"", 0, false});

    for (int i = 0; i < n; i++) {
        string key;
        int value;
        cin >> key >> value;

        int index = computeHash(key);
        // Linear probing for collision resolution
        while (hashTable[index].occupied) {
            index = (index + 1) % TABLE_SIZE;
        }
        hashTable[index] = {key, value, true};
    }

    string searchKey;
    cin >> searchKey;

    int index = computeHash(searchKey);
    int start = index;
    bool found = false;

    // Search with linear probing
    while (hashTable[index].occupied) {
        if (hashTable[index].key == searchKey) {
            found = true;
            break;
        }
        index = (index + 1) % TABLE_SIZE;
        if (index == start) break; // full cycle
    }

    if (found)
        cout << "Key \"" << searchKey << "\" exists in the dictionary." << endl;
    else
        cout << "Key \"" << searchKey << "\" does not exist in the dictionary." << endl;

    return 0;
}
