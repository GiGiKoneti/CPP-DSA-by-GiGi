#include <iostream>
#include <vector>
using namespace std;

// Function to return indices of the two numbers such that they add up to target
vector<int> pairsum(vector<int> arr, int target) {
    int st = 0, end = arr.size() - 1;
    vector<int> ans;

    // Two-pointer technique (works on sorted array)
    while (st < end) {
        int cursum = arr[st] + arr[end];

        if (cursum == target) {
            ans.push_back(st);  // store the indices
            ans.push_back(end);
            break;              // stop after finding the first valid pair
        }

        if (cursum > target) {
            end--;              // move end pointer left to reduce sum
        } else {
            st++;               // move start pointer right to increase sum
        }
    }

    return ans; // returns empty if no pair is found
}

int main() {
    vector<int> vec {2, 7, 11, 15}; // Sorted input array
    int target = 9;

    vector<int> ans = pairsum(vec, target);

    // Check if a valid pair was found
    if (!ans.empty()) {
        cout << "Pair found at indices: " << ans[0] << ", " << ans[1] << endl;
    } else {
        cout << "No pair found with the given target sum." << endl;
    }

    return 0;
}
