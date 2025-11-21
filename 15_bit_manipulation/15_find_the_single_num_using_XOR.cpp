/*
Question 2:
Given a non-empty array of integers nums, every element appears twice except for one. 
Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.

Hint: Think XOR.

Explanation:
- XOR properties:
    1. a ^ a = 0   (number XOR itself is 0)
    2. a ^ 0 = a   (number XOR 0 is the number itself)
    3. XOR is commutative and associative (order doesn't matter)
- If every element appears twice except one, XOR-ing all numbers will cancel out the ones appearing twice, 
  leaving only the single number.
- Time Complexity: O(n)
- Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

int singleNumber(vector<int>& nums) {
    int ans = 0;
    for (int num : nums) {
        ans ^= num;  // XOR all elements
    }
    return ans;
}

int main() {
    vector<int> nums = {4, 1, 2, 1, 2};
    cout << "The single number is: " << singleNumber(nums) << endl;
    return 0;
}