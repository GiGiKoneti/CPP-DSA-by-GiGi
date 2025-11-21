#include <iostream>
#include <list>
using namespace std;

/*
Merging Two Sorted Linked Lists:
--------------------------------
1. Two sorted lists, left and right.
2. Compare the front elements of both lists.
3. Move the smaller element to the merged list.
4. Continue until one of the lists becomes empty.
5. Append the remaining elements from the non-empty list.
*/

list<int> mergeSortedLists(const list<int>& left, const list<int>& right) {
    list<int> merged;
    auto it1 = left.begin();
    auto it2 = right.begin();

    // Compare elements and merge
    while (it1 != left.end() && it2 != right.end()) {
        if (*it1 <= *it2) {
            merged.push_back(*it1);
            ++it1;
        } else {
            merged.push_back(*it2);
            ++it2;
        }
    }

    // Append remaining elements
    while (it1 != left.end()) {
        merged.push_back(*it1);
        ++it1;
    }
    while (it2 != right.end()) {
        merged.push_back(*it2);
        ++it2;
    }

    return merged;
}

int main() {
    list<int> left = {1, 3, 5};
    list<int> right = {2, 4, 6};

    list<int> merged = mergeSortedLists(left, right);

    cout << "Merged List: ";
    for (int val : merged) cout << val << " ";
    cout << endl;

    return 0;
}

/*
Explanation:
------------
- Two iterators traverse both lists simultaneously.
- Compare elements at iterators and push the smaller into the merged list.
- After one list ends, append the remaining elements of the other list.

Time Complexity: O(n + m) where n and m are sizes of the two lists
Space Complexity: O(n + m) for the merged list
*/