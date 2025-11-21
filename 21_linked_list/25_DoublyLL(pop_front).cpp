#include <iostream>
using namespace std;

// Node class for Doubly Linked List
class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

// Doubly Linked List class
class DoublyLinkedList {
    Node* Head;
    Node* Tail;

public:
    DoublyLinkedList() {
        Head = nullptr;
        Tail = nullptr;
    }

    // Push front function
    void push_front(int val) {
        Node* newNode = new Node(val);
        if (Head == nullptr) {
            Head = Tail = newNode;
        } else {
            newNode->next = Head;
            Head->prev = newNode;
            Head = newNode;
        }
    }

    // Pop front function
    void pop_front() {
        /*
        pop_front() logic:
        ------------------
        1. If the list is empty (Head == nullptr), do nothing or print message.
        2. Else:
           a. Store Head in a temporary pointer.
           b. Move Head to Head->next.
           c. If Head is not null, set Head->prev = nullptr.
           d. If Head becomes null (list had 1 node), Tail = nullptr.
           e. Delete the old head node.
        */
        if (Head == nullptr) {
            cout << "List is empty, cannot pop front." << endl;
            return;
        }

        Node* temp = Head;
        Head = Head->next;

        if (Head != nullptr) {
            Head->prev = nullptr;
        } else {
            Tail = nullptr; // list became empty
        }

        delete temp;
    }

    // Function to print list forward
    void printForward() {
        Node* temp = Head;
        cout << "Forward: ";
        while (temp) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

// Driver code
int main() {
    DoublyLinkedList dll;

    dll.push_front(3); // List: 3
    dll.push_front(2); // List: 2 <-> 3
    dll.push_front(1); // List: 1 <-> 2 <-> 3

    cout << "Original List:" << endl;
    dll.printForward();

    dll.pop_front(); // Removes 1
    cout << "After pop_front():" << endl;
    dll.printForward();

    dll.pop_front(); // Removes 2
    dll.pop_front(); // Removes 3
    dll.pop_front(); // Try popping from empty list

    return 0;
}

/*
Explanation:
------------
- pop_front removes the first node (Head) from DLL.
- Steps:
  1. Save Head in temp.
  2. Move Head to next node.
  3. Update new Head's prev to nullptr.
  4. If list becomes empty, Tail = nullptr.
  5. Delete the old Head node.

Time Complexity: O(1) – Direct deletion at head.
Space Complexity: O(1) – Only uses a temporary pointer.
*/