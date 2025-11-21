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
        Node* newNode = new Node(val);   // dynamically allocate a new node

        /*
        push_front() logic:
        -------------------
        1. Create a new node with given value.
        2. If the list is empty (Head == NULL):
              -> make both Head and Tail point to newNode.
        3. Otherwise:
              -> point newNode->next to current Head
              -> update Head to newNode
        */

        if (Head == NULL) {
            Head = Tail = newNode;   // first node in the list
        } else {
            newNode->next = Head;   // new node points to old head
            Head = newNode;         // update Head to the new node
        }
    }

    // Helper function to print the linked list
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

    ll.push_front(3);   // List: 3 -> NULL
    ll.push_front(2);   // List: 2 -> 3 -> NULL
    ll.push_front(1);   // List: 1 -> 2 -> 3 -> NULL

    ll.printList();

    return 0;
}