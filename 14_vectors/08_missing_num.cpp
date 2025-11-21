#include <iostream>
#include <vector>
using namespace std;

/*
    🧾 Question:
    You are given an array `nums` containing `n` integers where each integer is between 1 and n (inclusive).
    There is exactly one number that is duplicated, and one number that is missing.

    Your task is to find:
      - The number that occurs twice
      - The number that is missing

    🔁 Return them as a vector: [duplicate, missing]

    📥 Example:
        Input: nums = [1, 2, 2, 4]
        Output: [2, 3]
*/

vector<int> findErrorNums(vector<int>& nums) {
    int n = nums.size();
    vector<int> freq(n + 1, 0);  // Frequency array of size n+1 (index 1 to n)
    vector<int> result(2);       // [duplicate, missing]

    // Count frequency of each number
    for (int num : nums) {
        freq[num]++;
    }

    // Identify duplicate and missing
    for (int i = 1; i <= n; i++) {
        if (freq[i] == 0) {
            result[1] = i;  // Missing number
        } else if (freq[i] == 2) {
            result[0] = i;  // Duplicate number
        }
    }

    return result;
}

int main() {
    vector<int> nums = {1, 2, 2, 4};
    vector<int> result = findErrorNums(nums);

    cout << "[" << result[0] << "," << result[1] << "]" << endl;  // Output: [2,3]

    return 0;
}