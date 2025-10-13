/*
 * Print Characters with Hyphens (Pattern Printing)
 * 
 * This program reads characters and prints them in a specific pattern with hyphens.
 * It prints the first 5 characters normally, then adds a hyphen after the 5th character,
 * and adds three hyphens ("---") if more than 6 characters are input. The program
 * demonstrates conditional formatting based on character count. Input consists of
 * individual characters. Output displays characters with hyphen formatting according
 * to the specified pattern.
 */

// You are using GCC
#include <iostream>
using namespace std;
int main() {
    char val;
    int count = 0;
    char printChar;
    while (true) {
        cin>>val;
        if (count == 5) {
            cout<<'-';
        }
        if (count>=6) {
            cout<<"---";
            return 0;
        }
        cout<<val;
        count++;
    }
}