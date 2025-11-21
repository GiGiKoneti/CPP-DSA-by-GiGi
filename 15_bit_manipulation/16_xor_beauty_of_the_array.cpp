/*
Question 3: XOR Beauty of Array

You are given a 0-indexed integer array nums.

The effective value of three indices i, j, and k is defined as:
    ((nums[i]) | nums[j]) & nums[k])

The xor-beauty of the array is the XOR of the effective values of all the possible triplets (i, j, k)
where 0 <= i, j, k < n.

Return the xor-beauty of nums.

---

Explanation:
---------------
If we try to calculate the "effective value" for all triplets (i, j, k), 
it would be O(n^3), which is too slow for large arrays.

We can use bit manipulation observation:

1. Let’s check each bit position separately.
2. For a bit to be set in the final XOR, it must be set in an odd number of triplets.
3. The formula ((nums[i]) | nums[j]) & nums[k]) means:
   - First OR nums[i] and nums[j].
   - Then AND the result with nums[k].
4. After mathematical simplification (bitwise logic), it turns out that the XOR beauty
   of the array is simply the XOR of all nums[i].

This is because every bit’s contribution across all triplets appears an even number of times 
except when it appears in the XOR of the original numbers.

So:
    xor_beauty = nums[0] ^ nums[1] ^ ... ^ nums[n-1]
   
Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
using namespace std;

int xorBeauty(int nums[], int n) {
    int result = 0;
    for (int i = 0; i < n; i++) {
        result ^= nums[i]; // XOR each element
    }
    return result;
}

int main() {
    int nums[] = {1, 4, 3};
    int n = sizeof(nums) / sizeof(nums[0]);
    
    cout << "XOR Beauty: " << xorBeauty(nums, n) << endl;
    return 0;
}