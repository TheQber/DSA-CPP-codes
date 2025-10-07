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