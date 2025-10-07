// You are using GCC
// You are using GCC
// You are using GCC
// You are using GCC
#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    int size;
    cin>>size;
    int arr[size];
    float sum = 0;
    for (int i = 0 ; i < size ; i ++) {
        cin>>arr[i];
        sum+=arr[i];
    }
    int target;
    cin>>target;
    bool found = false;
    int count = 0;
    for (int j = 0 ; j < size ; j ++ ) {
        count++;
        if (target == arr[j]) {
            cout<<"Interaction ID "<<target<<" is present at index "<<j<<endl;
            found = true;
            break;
        }
    }
    if (!found) cout<<"Interaction ID "<<target<<" is not present"<<endl;
    cout<<"Total comparisons made: "<<count<<endl;
    cout<<"Sum of all interaction: "<<sum<<endl;
    cout<<"Average of all interaction: "<<fixed<<setprecision(2)<<sum/size;
}