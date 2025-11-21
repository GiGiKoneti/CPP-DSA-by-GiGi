#include <iostream>
#include <list>
using namespace std;

/*
Merge Sort on Linked List:
--------------------------
1. Divide the list into two halves using iterators (fast & slow pointer technique).
2. Recursively sort both halves.
3. Merge the two sorted halves using a merge function.

Time Complexity: O(n log n) - Each split divides list in half (log n), merging takes O(n)
Space Complexity: O(n) - STL list uses extra space during merge because merge creates a new list temporarily
*/

list<int> mergeLists(list<int>& left, list<int>& right) {
    list<int> result;

    auto it1 = left.begin();
    auto it2 = right.begin();

    // Merge two sorted lists
    while (it1 != left.end() && it2 != right.end()) {
        if (*it1 <= *it2) {
            result.push_back(*it1);
            ++it1;
        } else {
            result.push_back(*it2);
            ++it2;
        }
    }

    // Append remaining elements
    while (it1 != left.end()) {
        result.push_back(*it1);
        ++it1;
    }
    while (it2 != right.end()) {
        result.push_back(*it2);
        ++it2;
    }

    return result;
}

list<int> mergeSort(list<int> lst) {
    // Base case: list with 0 or 1 element is already sorted
    if (lst.size() <= 1) return lst;

    // Split list into two halves
    list<int> left, right;
    auto it = lst.begin();
    size_t mid = lst.size() / 2;
    for (size_t i = 0; i < mid; ++i) {
        left.push_back(*it);
        ++it;
    }
    for (; it != lst.end(); ++it) {
        right.push_back(*it);
    }

    // Recursively sort left and right
    left = mergeSort(left);
    right = mergeSort(right);

    // Merge sorted halves
    return mergeLists(left, right);
}

int main() {
    list<int> ll = {6, 3, 7, 5, 2, 4};

    cout << "Original List: ";
    for (int val : ll) cout << val << " ";
    cout << endl;

    ll = mergeSort(ll);

    cout << "Sorted List:   ";
    for (int val : ll) cout << val << " ";
    cout << endl;

    return 0;
}

/*
Explanation:
------------
1. mergeSort() recursively splits the list into halves until each list has 0 or 1 element.
2. mergeLists() merges two sorted lists into a single sorted list.
3. STL list allows efficient insertion at back, so push_back() is used while merging.
4. We create new lists during merge since STL list does not provide direct array-like indexing.

Time Complexity:
- O(n log n) : log n levels of recursion for dividing + O(n) for merging at each level

Space Complexity:
- O(n) extra space used for creating temporary lists during merging
*/