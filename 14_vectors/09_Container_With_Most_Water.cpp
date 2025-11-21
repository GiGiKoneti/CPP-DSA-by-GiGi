#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Question 2: Container With Most Water

You are given an integer array `height` of length `n`. There are `n` vertical lines 
drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container 
contains the most water. Return the maximum amount of water a container can store.

Note: You may not slant the container.

Example:
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49

Explanation:
The vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. 
The max area of water the container can contain is 49, 
formed between lines at index 1 (height 8) and index 8 (height 7):
Area = min(8,7) * (8 - 1) = 7 * 7 = 49.
*/

int maxArea(vector<int>& height) {
    int max_water = 0;

    // Two pointers approach: start from both ends
    int left = 0;
    int right = height.size() - 1;

    // Continue while left pointer is before right
    while (left < right) {
        // Calculate the height and width of the container
        int h = min(height[left], height[right]);
        int w = right - left;

        // Calculate area and update max if it's larger
        max_water = max(max_water, h * w);

        // Move the pointer with the smaller height to try for a larger container
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }

    return max_water;
}

int main() {
    vector<int> height = {1,8,6,2,5,4,8,3,7};

    cout << "Maximum water the container can store: " << maxArea(height) << endl;

    return 0;
}