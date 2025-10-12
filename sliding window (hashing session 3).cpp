//header
#include <iostream> 
#include <map> 
using namespace std; 

//middle code
void countDistinct(int arr[], int k, int n) 
{ 
    int mod = 101; // a prime number chosen for hash mapping
    map<int, int> hashTable; // key: element, value: frequency

    // Initialize the first window
    for (int i = 0; i < k; i++) {
        int index = arr[i] % mod; 
        hashTable[index]++;
    }

    // Print distinct count for first window
    cout << hashTable.size() << endl;

    // Slide the window
    for (int i = k; i < n; i++) {
        int oldIndex = arr[i - k] % mod;
        int newIndex = arr[i] % mod;

        // Remove the element going out of the window
        hashTable[oldIndex]--;
        if (hashTable[oldIndex] == 0)
            hashTable.erase(oldIndex);

        // Add the new element entering the window
        hashTable[newIndex]++;

        // Print count of distinct elements for current window
        cout << hashTable.size() << endl;
    }
} 


//footer
int main() 
{ 
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    int k;
    cin >> k;
    countDistinct(arr, k, n); 
    
    return 0; 
} 
