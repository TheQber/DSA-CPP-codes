/*
 * Word Search in Sentence (Searching - CY)
 * 
 * This program searches for a specific word within a given sentence using substring
 * comparison. It uses a custom substring function to extract potential word matches
 * and compares them with the target word. The algorithm checks all possible positions
 * in the sentence where the word could appear. Input consists of a sentence (with
 * spaces) followed by the word to search. Output indicates whether the word is
 * present in the sentence or not.
 */

// You are using GCC
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string substring (string sentence, int i, int j) {
    string word = "";
    for (int g = i; g < j ; g ++) {
        word+=sentence[g];
    }
    return word;
}
int main() {
    string sentence;
    getline(cin,sentence);
    int sentenceLength = sentence.length();
    string word;
    cin>>word;
    int wordLength = word.length();
    for (int i = 0 ; i < sentenceLength-wordLength ; i ++) {
        //cout<<substring(sentence,i,i+wordLength)<<" - "<<word<<endl;
        if (substring(sentence, i,i+wordLength) == word) {
            
            cout<<"The word '"<<word<<"' is present in the given sentence.";
            return 0;
        }
    }
    
    cout<<"The word '"<<word<<"' is not present in the given sentence.";
}