#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Function to count words in a title
int wordCount(const string &s) {
    int count = 0;
    bool inWord = false;
    for (char c : s) {
        if (c != ' ') {
            if (!inWord) {
                inWord = true;
                count++;
            }
        } else {
            inWord = false;
        }
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    cin.ignore();

    vector<string> titles(n);
    for (int i = 0; i < n; i++) {
        getline(cin, titles[i]);
    }

    // Find max word count for bucket size
    int maxWords = 0;
    vector<int> counts(n);
    for (int i = 0; i < n; i++) {
        counts[i] = wordCount(titles[i]);
        maxWords = max(maxWords, counts[i]);
    }

    // Create buckets: each index = word count
    vector<vector<string>> buckets(maxWords + 1);
    for (int i = 0; i < n; i++) {
        buckets[counts[i]].push_back(titles[i]);
    }

    cout << "Sorted book titles:" << endl;

    // Traverse buckets
    for (int i = 0; i <= maxWords; i++) {
        if (!buckets[i].empty()) {
            // Sort each bucket lexicographically
            sort(buckets[i].begin(), buckets[i].end());
            for (string &title : buckets[i]) {
                cout << title << endl;
            }
        }
    }

    return 0;
}
