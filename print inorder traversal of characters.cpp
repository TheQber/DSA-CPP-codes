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