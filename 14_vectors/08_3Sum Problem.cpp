#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
    🧾 Question 3:
    Given an integer array `nums`, return all the unique triplets [nums[i], nums[j], nums[k]]
    such that:
        - i != j, i != k, and j != k
        - nums[i] + nums[j] + nums[k] == 0

    ⚠️ The result should not contain duplicate triplets.

    📥 Input:
        nums = [-1, 0, 1, 2, -1, -4]

    📤 Output:
        [[-1, -1, 2], [-1, 0, 1]]

    💡 Explanation:
        - Triplets like (-1 + 0 + 1) = 0 and (-1 + -1 + 2) = 0.
        - The order of triplets and the elements inside doesn’t matter.
        - Avoid duplicates in the output.

    📚 Note: Use the built-in sorting function for vectors: `sort(nums.begin(), nums.end());`
*/

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());  // Sort the array

    int n = nums.size();
    for (int i = 0; i < n - 2; i++) {
        // Skip duplicate elements for the first number
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        int target = -nums[i];
        int left = i + 1, right = n - 1;

        while (left < right) {
            int sum = nums[left] + nums[right];

            if (sum == target) {
                result.push_back({nums[i], nums[left], nums[right]});
                left++;
                right--;

                // Skip duplicates for the second and third numbers
                while (left < right && nums[left] == nums[left - 1]) left++;
                while (left < right && nums[right] == nums[right + 1]) right--;

            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
    }

    return result;
}

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> triplets = threeSum(nums);

    for (auto triplet : triplets) {
        cout << "[";
        for (int i = 0; i < triplet.size(); i++) {
            cout << triplet[i];
            if (i < triplet.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }

    return 0;
}