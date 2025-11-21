#include <iostream>
#include <list> // STL list
using namespace std;

int main() {
    // Create a doubly linked list using STL
    list<int> ll;

    // 1. Insert elements at the front
    ll.push_front(3);  // List: 3
    ll.push_front(2);  // List: 2->3
    ll.push_front(1);  // List: 1->2->3

    // 2. Insert elements at the back
    ll.push_back(4);   // List: 1->2->3->4
    ll.push_back(5);   // List: 1->2->3->4->5

    // 3. Print size of the list
    cout << "Size of the list: " << ll.size() << endl;  // 5

    // 4. Access first and last elements
    cout << "First element: " << ll.front() << endl; // 1
    cout << "Last element: " << ll.back() << endl;   // 5

    // 5. Remove element from the front
    ll.pop_front();    // Removes 1, List: 2->3->4->5

    // 6. Remove element from the back
    ll.pop_back();     // Removes 5, List: 2->3->4

    // 7. Iterate and print the list
    cout << "Linked List elements: ";
    for (int val : ll) {
        cout << val << " -> ";
    }
    cout << "NULL" << endl;

    return 0;
}

/*
Explanation:

STL List Operations:
-------------------
1. push_front(val)  : Inserts element at the beginning. O(1)
2. push_back(val)   : Inserts element at the end. O(1)
3. pop_front()      : Removes element from the beginning. O(1)
4. pop_back()       : Removes element from the end. O(1)
5. front()          : Accesses first element. O(1)
6. back()           : Accesses last element. O(1)
7. size()           : Returns number of elements. O(1)
8. Iteration        : Using range-based for loop.

STL `list` is a **doubly linked list**, so all insertions and deletions at ends are efficient.
*/