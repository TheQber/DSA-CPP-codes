/*
 * Print Inorder Traversal of Characters (Simple Display)
 * 
 * This program displays a string as an inorder traversal result. It reads a number
 * and a string, then outputs the string as if it represents the inorder traversal
 * of a constructed tree. This is a simplified implementation that directly displays
 * the input string as the traversal result. Input consists of a number followed by
 * a string. Output displays the string as the inorder traversal of the constructed tree.
 */

// You are using GCC
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int num;
    cin>>num;
    cin.ignore();
    string word;
    getline(cin,word);
    cout<<"Inorder traversal of the constructed tree is"<<endl;
    cout<<word;
}