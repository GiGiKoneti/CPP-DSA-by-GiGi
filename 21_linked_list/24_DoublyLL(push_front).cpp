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
    // Constructor initializes empty list
    DoublyLinkedList() {
        Head = nullptr;
        Tail = nullptr;
    }

    // Function to insert node at the front
    void push_front(int val) {
        Node* newNode = new Node(val);

        /*
        push_front() logic:
        -------------------
        1. Create a new node with given value.
        2. If list is empty (Head == nullptr):
              -> Head and Tail both point to newNode.
        3. Otherwise:
              -> newNode->next points to current Head
              -> current Head->prev points back to newNode
              -> update Head to newNode
        */

        if (Head == nullptr) {
            Head = Tail = newNode;
        } else {
            newNode->next = Head;
            Head->prev = newNode;
            Head = newNode;
        }
    }

    // Function to print the list forward
    void printForward() {
        Node* temp = Head;
        cout << "Forward: ";
        while (temp) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Function to print the list backward
    void printBackward() {
        Node* temp = Tail;
        cout << "Backward: ";
        while (temp) {
            cout << temp->data << " <-> ";
            temp = temp->prev;
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

    dll.printForward();
    dll.printBackward();

    return 0;
}

/*
Explanation:
------------
- Doubly Linked List (DLL) has nodes with two pointers: next and prev.
- push_front inserts a node at the start:
  1. If list empty: Head and Tail point to new node.
  2. Else: new node points to old head, old head points back to new node, update Head.
- printForward iterates from Head to Tail.
- printBackward iterates from Tail to Head.

Time Complexity:
----------------
- push_front: O(1) – direct insertion at head.
- printForward/printBackward: O(n) – traverse all nodes.

Space Complexity:
-----------------
- O(1) extra memory per operation; nodes dynamically allocated.
*/