#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[100];
    for (int i = 0; i < n; ++i) cin >> arr[i];
    int target;
    cin >> target;

    // Values in array are in range 0..100 per constraints
    bool present[101] = {false};
    bool found = false;

    for (int i = 0; i < n; ++i) {
        int x = arr[i];
        int comp = target - x;
        if (comp >= 0 && comp <= 100 && present[comp]) {
            cout << "Pairs: " << x << " and " << comp << "\n";
            found = true;
        }
        // mark current number as seen for future elements
        if (x >= 0 && x <= 100) present[x] = true;
    }

    if (!found) cout << "No such pairs\n";
    return 0;
}
