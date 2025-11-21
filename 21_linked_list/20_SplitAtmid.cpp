#include <iostream>
#include <list>
using namespace std;

/*
Splitting a Linked List into two halves:
---------------------------------------
1. Use two iterators/pointers: slow and fast.
2. Move fast two steps at a time and slow one step at a time.
3. When fast reaches the end, slow will be at the middle.
4. Split the list at slow.
*/

void splitList(list<int>& original, list<int>& left, list<int>& right) {
    if (original.empty()) return;

    auto slow = original.begin();
    auto fast = original.begin();

    // Move fast by 2 steps and slow by 1 step
    while (fast != original.end()) {
        ++fast;
        if (fast != original.end()) {
            ++fast;
            ++slow;
        }
    }

    // slow now points to the last element of left half
    left.insert(left.end(), original.begin(), ++slow); // left half
    right.insert(right.end(), slow, original.end());    // right half
}

int main() {
    list<int> ll = {6, 3, 7, 5, 2, 4};
    list<int> left, right;

    splitList(ll, left, right);

    cout << "Left Half: ";
    for (int val : left) cout << val << " ";
    cout << "\nRight Half: ";
    for (int val : right) cout << val << " ";
    cout << endl;

    return 0;
}

/*
Explanation:
------------
- slow moves one step at a time, fast moves two steps.
- When fast reaches end, slow is at middle.
- Then we copy elements before slow into left list and elements from slow to end into right list.

Time Complexity: O(n) - Single traversal of the list
Space Complexity: O(1) additional (ignoring space for left and right lists created)
*/