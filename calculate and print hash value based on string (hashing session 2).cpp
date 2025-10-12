// You are using GCC
#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int TABLE_SIZE = 15;

// Simple hash function: sum of ASCII values mod TABLE_SIZE
int hashFunction(const string &key) {
    unsigned long hashValue = 0;
    for (char c : key)
        hashValue += c;
    return hashValue % TABLE_SIZE;
}

int main() {
    int n;
    cin >> n;
    vector<string> table(TABLE_SIZE, ""); // empty slots

    for (int i = 0; i < n; i++) {
        string key;
        cin >> key;

        int hashIndex = hashFunction(key);
        int originalIndex = hashIndex;
        int j = 1;

        // Quadratic probing: (h + i²) % TABLE_SIZE
        while (!table[hashIndex].empty()) {
            hashIndex = (originalIndex + j * j) % TABLE_SIZE;
            j++;
        }

        table[hashIndex] = key;
    }

    cout << "Hash Table:" << endl;
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (!table[i].empty()) {
            cout << "[" << i << "]: " << table[i] << endl;
        }
    }

    return 0;
}
