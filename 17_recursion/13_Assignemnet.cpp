/*
Question 1: Write a recursive function to perform Binary Search.
Input: arr[] = {1,2,3,4,5,6,7}, n = 7, key = 5
Output: 4 (index of key)
Use the starting index & ending index logic used in rotated, sorted array Qs.
*/

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

// Question 1: Recursive Binary Search
int binarySearch(int arr[], int start, int end, int key) {
    if (start > end) {
        return -1;
    }
    int mid = start + (end - start) / 2;
    if (arr[mid] == key) {
        return mid;
    }
    if (arr[mid] > key) {
        return binarySearch(arr, start, mid - 1, key);
    } else {
        return binarySearch(arr, mid + 1, end, key);
    }
}

/*
Question 2: For a given integer array of size N. 
You have to find all the occurrences (indices) of a given element (Key) and print them.
Use a recursive function to solve this problem.
Sample Input: arr[] = {3,2,4,5,6,2,7,2,2} key=2
Sample Output: 1 5 7 8
*/

// Question 2: Find all occurrences of a key in an array
void findOccurrences(int arr[], int n, int key, int i) {
    if (i == n) {
        return;
    }
    if (arr[i] == key) {
        cout << i << " ";
    }
    findOccurrences(arr, n, key, i + 1);
}

/*
Question 3: We are given a string S, we need to find the count of all 
contiguous substrings starting and ending with the same character.
[Leetcode Premium Qs]
Sample Input 1 : S = "abcab"
Sample Output 1: 7
There are 15 substrings of "abcab": a, ab, abc, abca, abcab, b, bc, bca, bcab, c, ca, cab, a, ab, b
Out of the above substrings, there are 7 substrings: a, abca, b, bcab, c, a and b.
So, only 7 contiguous substrings start and end with the same character.
Sample Input 2 : S = "aba"
Sample Output 2: 4
The substrings are a, b, a and aba
*/

// Question 3: Count contiguous substrings starting and ending with the same character
int countSubstrings(string s, int i, int j, int n) {
    if (n <= 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }

    int res = countSubstrings(s, i + 1, j, n - 1) + 
              countSubstrings(s, i, j - 1, n - 1) - 
              countSubstrings(s, i + 1, j - 1, n - 2);

    if (s[i] == s[j]) {
        res++;
    }
    return res;
}

/*
Question 4: TOWER OF HANOI (Important!)
You have 3 towers and N disks of different sizes which can slide onto any tower. 
The puzzle starts with disks sorted in ascending order of size from top to bottom 
(i.e., each disk sits on top of an even larger one).
You have the following constraints:
(1) Only one disk can be moved at a time.
(2) A disk is slid off the top of one tower onto another tower.
(3) A disk cannot be placed on top of a smaller disk.
Write a program to move the disks from the first tower to the last using Stacks.
Let rod 1 = 'A', rod 2 = 'B', rod 3 = 'C'.
An example with 2 disks i.e. N=2:
Step 1: Shift the first disk from 'A' to 'B'.
Step 2: Shift the second disk from 'A' to 'C'.
Step 3: Shift the first disk from 'B' to 'C'.
An example with 3 disks i.e. N=3:
Step 1: Shift the first disk from 'A' to 'C'.
Step 2: Shift second disk from 'A' to 'B'.
Step 3: Shift the first disk from 'C' to 'B'.
Step 4: Shift the third disk from 'A' to 'C'.
Step 5: Shift the first disk from 'B' to 'A'.
Step 6: Shift second disk from 'B' to 'C'
Step 7: Shift the first disk from 'A' to 'C'.
The Approach here is:
- Shift 'n-1' disks from 'A' to 'B', using C.
- Shift the last disk from 'A' to 'C'.
- Shift 'n-1' disks from 'B' to 'C', using A.
*/

// Question 4: Tower of Hanoi
void towerOfHanoi(int n, char src, char dest, char helper) {
    if (n == 0) {
        return;
    }
    towerOfHanoi(n - 1, src, helper, dest);
    cout << "Shift the disk " << n << " from '" << src << "' to '" << dest << "'" << endl;
    towerOfHanoi(n - 1, helper, dest, src);
}

/*
Question 5: A digit string is good if the digits (0-indexed) at 
even indices are even and the digits at odd indices are prime (2, 3, 5, or 7).
For example, "2582" is good because the digits (2 and 8) at 
even positions are even and the digits (5 and 2) at odd positions are prime.
However, "3245" is not good because 3 is at an even index but is not even.
Given an integer n, return the total number of good digit strings of length n. 
Since the answer may be large, return it modulo 10^9+7.
A digit string is a string consisting of digits 0 through 9 that may contain leading zeros.
Input: n=1
Output: 5
Explanation: The good numbers of length 1 are "0", "2", "4", "6", "8".
Hint: This Qs uses the binary exponentiation technique we learnt in the Bit Manipulation chapter.
*/

// Question 5: Good Digit Strings (Binary Exponentiation)
long long power(long long base, long long exp) {
    long long res = 1;
    long long mod = 1e9 + 7;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            res = (res * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

int main() {
    // Solution for Question 1
    cout << "--- Question 1: Binary Search ---" << endl;
    int arr1[] = {1, 2, 3, 4, 5, 6, 7};
    int n1 = 7;
    int key1 = 5;
    int result1 = binarySearch(arr1, 0, n1 - 1, key1);
    if (result1 != -1) {
        cout << "Output: " << result1 << " (index of key)" << endl;
    } else {
        cout << "Output: Key not found" << endl;
    }
    cout << endl;

    // Solution for Question 2
    cout << "--- Question 2: Find All Occurrences ---" << endl;
    int arr2[] = {3, 2, 4, 5, 6, 2, 7, 2, 2};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int key2 = 2;
    cout << "Sample Output: ";
    findOccurrences(arr2, n2, key2, 0);
    cout << endl << endl;

    // Solution for Question 3
    cout << "--- Question 3: Count Substrings ---" << endl;
    string s3_1 = "abcab";
    cout << "Sample Input 1: " << s3_1 << endl;
    cout << "Sample Output 1: " << countSubstrings(s3_1, 0, s3_1.length() - 1, s3_1.length()) << endl;

    string s3_2 = "aba";
    cout << "Sample Input 2: " << s3_2 << endl;
    cout << "Sample Output 2: " << countSubstrings(s3_2, 0, s3_2.length() - 1, s3_2.length()) << endl;
    cout << endl;

    // Solution for Question 4
    cout << "--- Question 4: Tower of Hanoi ---" << endl;
    int n4 = 3;
    cout << "Steps to solve Tower of Hanoi with " << n4 << " disks:" << endl;
    towerOfHanoi(n4, 'A', 'C', 'B');
    cout << endl;

    // Solution for Question 5
    cout << "--- Question 5: Good Digit Strings ---" << endl;
    int n5 = 1;
    long long even_count = 5;  
    long long prime_count = 4;
    long long total_count;
    if (n5 % 2 == 0) {
        long long even_places = n5 / 2;
        long long odd_places = n5 / 2;
        total_count = (power(even_count, even_places) * power(prime_count, odd_places)) % (1000000007);
    } else {
        long long even_places = (n5 / 2) + 1;
        long long odd_places = n5 / 2;
        total_count = (power(even_count, even_places) * power(prime_count, odd_places)) % (1000000007);
    }
    cout << "Input: n = " << n5 << endl;
    cout << "Output: " << total_count << endl;

    return 0;
}