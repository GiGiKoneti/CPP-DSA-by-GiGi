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

    // Function to insert a node at the beginning of the list
    void push_front(int val) {
        Node* newNode = new Node(val); // dynamically allocate a new node

        /*
        push_front() logic:
        -------------------
        1. Create a new node with given value.
        2. If the list is empty (Head == NULL):
              -> make both Head and Tail point to newNode.
        3. Otherwise:
              -> point newNode->next to current Head
              -> update Head to newNode
        Time Complexity  : O(1), constant time insertion at front
        Space Complexity : O(1), only new node allocation
        */
        if (Head == NULL) {
            Head = Tail = newNode;
        } else {
            newNode->next = Head;
            Head = newNode;
        }
    }

    // Function to insert a node at the end of the list
    void push_back(int val) {
        Node* newNode = new Node(val); // dynamically allocate a new node

        /*
        push_back() logic:
        -------------------
        1. Create a new node with given value.
        2. If the list is empty (Head == NULL):
              -> make both Head and Tail point to newNode.
        3. Otherwise:
              -> point Tail->next to newNode
              -> update Tail to newNode
        Time Complexity  : O(1), constant time insertion using Tail pointer
        Space Complexity : O(1), only new node allocation
        */
        if (Head == NULL) {
            Head = Tail = newNode;
        } else {
            Tail->next = newNode;
            Tail = newNode;
        }
    }

    // Function to print the linked list
    void printList() {
        /*
        printList() logic:
        -------------------
        1. Start from the Head of the list.
        2. While the current node is not NULL:
              -> Print the current node's data.
              -> Move to the next node using current->next.
        3. When the end of the list is reached (current is NULL), print "NULL".
        
        Aspect           | Description
        -----------------|-------------------------------------------------
        Start point      | Begin traversal from the Head node.
        Iteration        | Move node by node using next until reaching NULL.
        Output           | Prints data of each node followed by -> and ends with NULL.
        Time Complexity  | O(n), traverses all nodes once.
        Space Complexity | O(1), only one temporary pointer temp is used.
        */
        Node* temp = Head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

// Main function to demonstrate Linked List operations
int main() {
    List ll;

    // Insert at front
    ll.push_front(3); // List: 3 -> NULL
    ll.push_front(2); // List: 2 -> 3 -> NULL
    ll.push_front(1); // List: 1 -> 2 -> 3 -> NULL

    // Insert at back
    ll.push_back(4);  // List: 1 -> 2 -> 3 -> 4 -> NULL
    ll.push_back(5);  // List: 1 -> 2 -> 3 -> 4 -> 5 -> NULL

    // Print the linked list
    ll.printList();

    return 0;
}