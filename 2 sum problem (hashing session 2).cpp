//header
#include <iostream>

using namespace std;

//middle code
// You are using GCC
void twoSum(int* nums, int numsSize, int target) {
    int offset = 100; // to handle negative numbers (-100 to 100)
    int hash[201];    // index = num + offset; value = index in array
    for (int i = 0; i < 201; i++) hash[i] = -1; // initialize all to -1

    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        int compIndex = complement + offset;

        if (compIndex >= 0 && compIndex < 201 && hash[compIndex] != -1) {
            cout << "[" << hash[compIndex] << ", " << i << "]";
            return;
        }
        hash[nums[i] + offset] = i;
    }

    cout << "No solution found.";
}


//footer
int main() {
    int nums[1000];
    int numsSize, target;

    cin >> numsSize;

    for (int i = 0; i < numsSize; i++) {
        cin >> nums[i];
    }

    cin >> target;

    twoSum(nums, numsSize, target);

    return 0;
}