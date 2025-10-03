// You are using GCC
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main() {
    string sentence;
    getline(cin,sentence);
    int totalLength = sentence.length();
    int j = 0;
    string arr[100] = {""};
    string word = "";
    char letter;
    for (int i = 0 ; i < totalLength ; i ++) {
        if (sentence[i] == ' ') {
            arr[j] = word;
            j++;
            word = "";
            continue;
        }
        letter = sentence[i];
        word += letter;
        if (i == totalLength-1) {
            arr[j] = word;
            j++;
            word = "";
        }
    }
    for (int i = 99 ; i >= 0 ; i --) {
        cout<<arr[i]<<" ";
    }
}