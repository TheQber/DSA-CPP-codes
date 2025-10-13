/*
 * Double Hashing Implementation (Hashing Session 3)
 * 
 * This program implements a hash table using double hashing for collision resolution.
 * It uses two hash functions: the primary hash function (key % TABLE_SIZE) and a
 * secondary hash function (7 - (key % 7)) to determine the step size for probing.
 * When collisions occur, it uses the formula (index + i * step) % TABLE_SIZE to
 * find the next available slot. Input consists of number of keys followed by the
 * key values. Output displays the complete hash table with indices and stored values.
 */

#include <iostream>
using namespace std;

#define TABLE_SIZE 15

int secondHash(int key) {
    return 7 - (key % 7);
}

void insert(int hashTable[], int key) {
    int index = key % TABLE_SIZE;
    int step = secondHash(key);
    int i = 0;

    while (hashTable[(index + i * step) % TABLE_SIZE] != -1 && i < TABLE_SIZE) {
        i++;
    }

    if (i < TABLE_SIZE) {
        hashTable[(index + i * step) % TABLE_SIZE] = key;
    }
}

void display(int hashTable[]) {
    cout << "Hash Table:\n";
    for (int i = 0; i < TABLE_SIZE; i++) {
        cout << "[" << i << "]: " << hashTable[i] << "\n";
    }
}

int main() {
    int n;
    cin >> n;
    int keys[n];
    for (int i = 0; i < n; i++) {
        cin >> keys[i];
    }

    int hashTable[TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        insert(hashTable, keys[i]);
    }

    display(hashTable);
    return 0;
}
