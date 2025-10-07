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