/**
 * ==============================================================================
 * Divide & Conquer Assignment Questions Solutions
 * ==============================================================================
 */

// Necessary Headers
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

// ==============================================================================
// Question 1: Apply Merge sort to sort an array of Strings.
// (Assume that all the characters in all the Strings are in lowercase). (EASY)
// Sample Input 1: arr = { "sun", "earth", "mars", "mercury" }
// Sample Output 1: arr = { "earth", "mars", "mercury", "sun"}
// ==============================================================================

/**
 * Explanation for Question 1: Merge Sort for Strings
 *
 * The core idea of Merge Sort is Divide and Conquer.
 * 1. Divide: Split the array of strings into two halves recursively until each
 * sub-array contains a single element (which is trivially sorted).
 * 2. Conquer (Merge): Merge the two sorted sub-arrays back into a single sorted
 * array.
 *
 * The sorting logic is applied during the 'Merge' step, where we compare two
 * strings, 'str1' and 'str2', using the standard string comparison operator (<).
 * String comparison in C++ works lexicographically (like dictionary order),
 * which is exactly what's needed here.
 */

// Helper function to merge two sorted sub-arrays (strings)
void mergeStrings(vector<string>& arr, int left, int mid, int right) {
    // Determine sizes of the two halves
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays for the two halves
    vector<string> leftArr(n1);
    vector<string> rightArr(n2);

    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[left..right]
    int i = 0; // Initial index of first sub-array
    int j = 0; // Initial index of second sub-array
    int k = left; // Initial index of merged sub-array

    while (i < n1 && j < n2) {
        // Standard lexicographical string comparison
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of leftArr[], if any
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Copy the remaining elements of rightArr[], if any
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// The main function that sorts arr[left..right] using merge()
void mergeSortStrings(vector<string>& arr, int left, int right) {
    if (left < right) {
        // Find the middle point
        int mid = left + (right - left) / 2;

        // Recursively sort the first and second halves
        mergeSortStrings(arr, left, mid);
        mergeSortStrings(arr, mid + 1, right);

        // Merge the sorted halves
        mergeStrings(arr, left, mid, right);
    }
}


// ==============================================================================
// Question 2: Given an array nums of size n, return the majority element. (MEDIUM)
// The majority element is the element that appears more than floor(n/2) times.
// You may assume that the majority element always exists in the array.
// Sample Input 1: nums=[3,2,3] -> Output: 3
// Sample Input 2: nums=[2,2,1,1,1,2,2] -> Output: 2
// ==============================================================================

/**
 * Explanation for Question 2: Majority Element using Divide and Conquer
 *
 * This problem can be solved efficiently using **Boyer-Moore Voting Algorithm**,
 * but a Divide and Conquer approach also exists.
 *
 * Divide and Conquer Approach:
 * 1. Divide: Split the array into two halves recursively.
 * 2. Conquer: Find the majority element for the left half and the right half.
 * 3. Combine:
 * a. If the majority element is the same for both halves, it's the majority
 * element for the whole array.
 * b. If they are different (or one is non-existent/unknown), we count the
 * occurrences of the two candidate majority elements (left_maj and right_maj)
 * in the entire range to see which one is the true majority element.
 *
 * Optimization (Boyer-Moore Voting Algorithm):
 * Given the constraint that the majority element *always* exists, the
 * Boyer-Moore algorithm is simpler, linear time ($O(n)$), and space ($O(1)$).
 * It relies on the fact that the majority element's count is $> n/2$.
 * The algorithm:
 * - Initialize 'count' to 0 and 'candidate' to an arbitrary value.
 * - Iterate through the array:
 * - If count is 0, set the current element as the new 'candidate' and set count to 1.
 * - If the current element equals 'candidate', increment 'count'.
 * - If the current element is different, decrement 'count'.
 * - The final 'candidate' is the majority element.
 */

int majorityElement(vector<int>& nums) {
    int count = 0;
    int candidate = 0; // Initialize candidate

    for (int num : nums) {
        if (count == 0) {
            candidate = num; // New candidate
            count = 1;
        } else if (num == candidate) {
            count++; // Current element matches candidate
        } else {
            count--; // Current element doesn't match, cancel out
        }
    }

    // Since the problem guarantees the majority element always exists,
    // the final candidate is the answer.
    return candidate;
}


// ==============================================================================
// Question 3: Given an array of integers. Find the Inversion Count in the array. (HARD)
// Inversion: two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.
// Sample Input 1: arr[]={2,4,1,3,5} -> Output: 3, because it has 3 inversions - (2, 1), (4, 1), (4, 3).
// (Hint: A sorting algorithm will be used to solve this question.)
// ==============================================================================

/**
 * Explanation for Question 3: Inversion Count using Modified Merge Sort
 *
 * The problem of counting inversions can be efficiently solved by modifying the
 * **Merge Sort** algorithm, which maintains the $O(n \log n)$ time complexity.
 *
 * Divide and Conquer Approach:
 * 1. Divide: Split the array into two halves (left and right).
 * 2. Conquer: Recursively find the inversion count for the left half (inv_left)
 * and the right half (inv_right).
 * 3. Combine (Count Split Inversions and Merge):
 * The crucial step is to count the **split inversions** (where i is in the
 * left half and j is in the right half, and arr[i] > arr[j]).
 * This is done during the standard 'merge' step:
 * - While merging the two sorted halves, if an element from the **right half**
 * (arr[j]) is moved into the result *before* an element from the **left half**
 * (arr[i]), it means arr[i] > arr[j].
 * - Since the left half (L) is sorted, *all* remaining elements in L (from
 * arr[i] to the end of L) must also be greater than arr[j].
 * - Therefore, the number of split inversions caused by arr[j] is the number
 * of remaining elements in the left sub-array (mid - i + 1).
 *
 * The total inversion count is: inv_left + inv_right + split_inversions.
 */

// Helper function to count split inversions and merge two sorted halves
long long mergeAndCount(vector<int>& arr, int left, int mid, int right) {
    // Create temporary array to hold the merged result
    vector<int> temp(right - left + 1);
    long long inversions = 0;

    int i = left;  // Start index for the left sub-array
    int j = mid + 1; // Start index for the right sub-array
    int k = 0;    // Start index for the temporary array

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            // No inversion: Element from the left is smaller/equal
            temp[k++] = arr[i++];
        } else {
            // Inversion found: arr[i] > arr[j] and i < j (since j is in the right half)
            // The number of inversions is (mid - i + 1), which is the count of
            // remaining elements in the left sub-array that are greater than arr[j].
            inversions += (mid - i + 1);
            temp[k++] = arr[j++];
        }
    }

    // Copy remaining elements of left half, if any
    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    // Copy remaining elements of right half, if any
    while (j <= right) {
        temp[k++] = arr[j++];
    }

    // Copy the merged results from temp back to the original array segment
    for (int l = 0; l < temp.size(); l++) {
        arr[left + l] = temp[l];
    }

    return inversions;
}

// The main function that uses modified merge sort to count inversions
long long getInversionCount(vector<int>& arr, int left, int right) {
    long long inversions = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;

        // 1. Count inversions in the left half
        inversions += getInversionCount(arr, left, mid);

        // 2. Count inversions in the right half
        inversions += getInversionCount(arr, mid + 1, right);

        // 3. Count split inversions and merge the two halves
        inversions += mergeAndCount(arr, left, mid, right);
    }
    return inversions;
}


// ==============================================================================
// Main function for testing the solutions
// ==============================================================================

int main() {
    cout << "--- Divide & Conquer Assignment Solutions ---" << endl << endl;

    // --------------------------------------------------------------------------
    // TEST FOR QUESTION 1: Merge Sort for Strings
    // --------------------------------------------------------------------------
    cout << "== Question 1: Merge Sort for Strings ==" << endl;
    vector<string> arr1 = { "sun", "earth", "mars", "mercury" };
    cout << "Original Array: ";
    for (const string& s : arr1) cout << s << " ";
    cout << endl;

    mergeSortStrings(arr1, 0, arr1.size() - 1);

    cout << "Sorted Array:   ";
    for (const string& s : arr1) cout << s << " ";
    cout << " (Expected: earth mars mercury sun)" << endl;
    cout << "------------------------------------------" << endl << endl;

    // --------------------------------------------------------------------------
    // TEST FOR QUESTION 2: Majority Element (Boyer-Moore)
    // --------------------------------------------------------------------------
    cout << "== Question 2: Majority Element ==" << endl;

    // Sample 1
    vector<int> nums2_1 = {3, 2, 3};
    int maj2_1 = majorityElement(nums2_1);
    cout << "Array: [3, 2, 3] -> Majority Element: " << maj2_1
         << " (Expected: 3)" << endl;

    // Sample 2
    vector<int> nums2_2 = {2, 2, 1, 1, 1, 2, 2};
    int maj2_2 = majorityElement(nums2_2);
    cout << "Array: [2, 2, 1, 1, 1, 2, 2] -> Majority Element: " << maj2_2
         << " (Expected: 2)" << endl;
    cout << "------------------------------------------" << endl << endl;

    // --------------------------------------------------------------------------
    // TEST FOR QUESTION 3: Inversion Count (Modified Merge Sort)
    // --------------------------------------------------------------------------
    cout << "== Question 3: Inversion Count ==" << endl;

    // Sample 1
    vector<int> arr3_1 = {2, 4, 1, 3, 5};
    vector<int> arr3_1_copy = arr3_1; // Preserve original for display
    long long count3_1 = getInversionCount(arr3_1, 0, arr3_1.size() - 1);
    cout << "Array: [2, 4, 1, 3, 5] -> Inversion Count: " << count3_1
         << " (Expected: 3)" << endl;

    // Sample 2 (Already Sorted)
    vector<int> arr3_2 = {2, 3, 4, 5, 6};
    vector<int> arr3_2_copy = arr3_2;
    long long count3_2 = getInversionCount(arr3_2, 0, arr3_2.size() - 1);
    cout << "Array: [2, 3, 4, 5, 6] -> Inversion Count: " << count3_2
         << " (Expected: 0)" << endl;

    // Sample 3 (All same elements)
    vector<int> arr3_3 = {5, 5, 5};
    vector<int> arr3_3_copy = arr3_3;
    long long count3_3 = getInversionCount(arr3_3, 0, arr3_3.size() - 1);
    cout << "Array: [5, 5, 5] -> Inversion Count: " << count3_3
         << " (Expected: 0)" << endl;

    // Example with Max Inversions ({5, 4, 3, 2, 1} -> 4+3+2+1 = 10)
    vector<int> arr3_4 = {5, 4, 3, 2, 1};
    vector<int> arr3_4_copy = arr3_4;
    long long count3_4 = getInversionCount(arr3_4, 0, arr3_4.size() - 1);
    cout << "Array: [5, 4, 3, 2, 1] -> Inversion Count: " << count3_4
         << " (Expected: 10)" << endl;
    cout << "------------------------------------------" << endl;

    return 0;
}