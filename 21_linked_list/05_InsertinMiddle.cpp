#include <iostream>
using namespace std;

// Node class representing each element in the Linked List
class Node {
    int data;
    Node* next;

public:
    // Constructor to initialize a node with a value
    Node(int val) {
        data = val;
        next = NULL;
    }

    // Give access of Node's private members to List
    friend class List;
};

// Linked List class
class List {
    Node* Head;
    Node* Tail;

public:
    // Constructor initializes an empty list
    List() {
        Head = NULL;
        Tail = NULL;
    }

    // Function to insert a node at the front
    void push_front(int val) {
        Node* newNode = new Node(val);
        if (Head == NULL) {
            Head = Tail = newNode;
        } else {
            newNode->next = Head;
            Head = newNode;
        }
    }

    // Function to insert a node at the back
    void push_back(int val) {
        Node* newNode = new Node(val);
        if (Head == NULL) {
            Head = Tail = newNode;
        } else {
            Tail->next = newNode;
            Tail = newNode;
        }
    }

    // Function to insert a node at a specific position (middle insertion)
    void insertAt(int val, int position) {
        /*
        insertAt() logic:
        -------------------
        1. Create a new node with given value.
        2. If the position is 0, call push_front().
        3. Traverse the list to reach the node just before the desired position.
        4. Update newNode->next to current->next.
        5. Update current->next to newNode.
        6. If inserting at the end, update Tail pointer.
        
        Aspect           | Description
        -----------------|---------------------------------------------
        Time Complexity  | O(n), need to traverse up to position-1 nodes.
        Space Complexity | O(1), only one new node and temp pointer used.
        */
        
        Node* newNode = new Node(val);

        if (position == 0) {
            push_front(val);
            return;
        }

        Node* temp = Head;
        int count = 0;

        // Traverse to the node before the insertion point
        while (temp != NULL && count < position - 1) {
            temp = temp->next;
            count++;
        }

        if (temp == NULL) {
            // If position is beyond the current list length, insert at end
            push_back(val);
            return;
        }

        // Insert in the middle
        newNode->next = temp->next;
        temp->next = newNode;

        // Update Tail if inserted at the end
        if (newNode->next == NULL) {
            Tail = newNode;
        }
    }

    // Function to print the linked list
    void printList() {
        Node* temp = Head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    List ll;

    // Insert at front
    ll.push_front(3); // 3 -> NULL
    ll.push_front(2); // 2 -> 3 -> NULL
    ll.push_front(1); // 1 -> 2 -> 3 -> NULL

    // Insert at back
    ll.push_back(4);  // 1 -> 2 -> 3 -> 4 -> NULL
    ll.push_back(5);  // 1 -> 2 -> 3 -> 4 -> 5 -> NULL

    // Insert in the middle
    ll.insertAt(99, 2); // Insert 99 at position 2
    // Resulting list: 1 -> 2 -> 99 -> 3 -> 4 -> 5 -> NULL

    ll.printList();

    return 0;
}