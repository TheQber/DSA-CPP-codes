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
