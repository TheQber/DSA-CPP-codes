// You are using GCC
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main() {
    string list;
    getline(cin,list);
    int arr[25];
    int count = 0;
    int length = list.length();
    for (char c : list) {
        if (c != ' ') {
            arr[count] = c-'0';
            count++;
        }
    }
    int target,min,max,CAL,SAL = 9999;
    cin>>target;
    int sum;
    for (int i = 0 ; i < count-1 ; i ++) {
        sum = 0;
        CAL = 0;
        for (int j = i; j < count ; j ++) {
            CAL++;
            sum+=arr[j];
            if (sum == target && SAL == 9999) {
                min = i;
                max = j;
                SAL = CAL;
            }
            else if (sum == target && CAL>SAL) {
                min = i;
                max = j;
                SAL = CAL;
                
            }
        }
        
    }
    if (!(SAL == 9999)) {
        cout<<"("<<min<<", "<<max<<")";
        return 0;
    }
    min = 0;
    max = -1;
    cout<<"("<<min<<", "<<max<<")";
    //cout<<"(0, -1)";
}