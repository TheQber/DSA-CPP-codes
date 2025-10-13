/*
 * Two Sum Problem with Hashing (Session 2)
 * 
 * This program solves the Two Sum problem using a hash table approach to efficiently
 * find pairs of numbers that sum to a target value. It uses an array-based hash table
 * with offset handling for negative numbers (-100 to 100 range). The algorithm stores
 * each number's index in the hash table and checks for the complement (target - current).
 * Input consists of array size, array elements, and target sum. Output displays the
 * indices of the first valid pair or indicates if no solution exists.
 */

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