#include <iostream>
#include <list>
#include <vector>
using namespace std;

/*
Zig-Zag Linked List:
-------------------
Given a linked list: 1->2->3->4->5
Reorder as: 1->5->2->4->3

Approach:
1. Copy elements into a vector for easy access to both ends.
2. Use two pointers: start (i=0) and end (j=n-1).
3. Take elements alternately from start and end, push_back to new list.
4. Stop when pointers cross.
*/

list<int> zigZagList(const list<int>& l) {
    vector<int> v(l.begin(), l.end()); // copy list to vector
    list<int> result;
    
    int i = 0;
    int j = v.size() - 1;
    while (i <= j) {
        if (i == j) { // If same element in middle
            result.push_back(v[i]);
        } else {
            result.push_back(v[i]);
            result.push_back(v[j]);
        }
        i++;
        j--;
    }
    
    return result;
}

int main() {
    list<int> l = {1, 2, 3, 4, 5};
    cout << "Original List: ";
    for (int val : l) cout << val << " ";
    cout << endl;

    list<int> zigzag = zigZagList(l);

    cout << "Zig-Zag List: ";
    for (int val : zigzag) cout << val << " ";
    cout << endl;

    return 0;
}

/*
Explanation:
------------
- Convert list to vector for random access.
- Use two pointers from start and end to take elements alternately.
- Time Complexity: O(n)
- Space Complexity: O(n) due to the vector copy

*/