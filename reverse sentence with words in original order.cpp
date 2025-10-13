/*
 * Reverse Sentence with Words in Original Order
 * 
 * This program reverses the order of words in a sentence while keeping the characters
 * within each word in their original order. It parses the input sentence into individual
 * words and stores them in an array, then prints the words in reverse order.
 * The algorithm handles word separation by spaces and preserves word integrity.
 * Input consists of a sentence string. Output displays the words in reverse order
 * separated by spaces.
 */

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