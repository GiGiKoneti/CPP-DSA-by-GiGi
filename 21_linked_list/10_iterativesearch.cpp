#include <iostream>
using namespace std;

// Node class representing each element in the Linked List
class Node {
    int data;
    Node* next;

public:
    Node(int val) {
        data = val;
        next = NULL;
    }

    friend class List;
};

// Linked List class
class List {
    Node* Head;
    Node* Tail;

public:
    List() {
        Head = NULL;
        Tail = NULL;
    }

    // Insert at the end (push_back)
    void push_back(int val) {
        Node* newNode = new Node(val);
        if (Head == NULL) {
            Head = Tail = newNode;
        } else {
            Tail->next = newNode;
            Tail = newNode;
        }
    }

    // Iterative search in Linked List
    bool searchIterative(int key) {
        /*
        Iterative Search Logic:
        ----------------------
        1. Start from the Head node.
        2. Traverse node by node using next pointer.
        3. Compare each node's data with the key.
            - If found, return true.
            - Otherwise, continue to next node.
        4. If end of list reached (NULL), key not found.
        
        Time Complexity  : O(n) – may traverse all nodes in worst case.
        Space Complexity : O(1) – no extra memory used.
        */
        Node* temp = Head;
        while (temp != NULL) {
            if (temp->data == key) {
                return true; // key found
            }
            temp = temp->next;
        }
        return false; // key not found
    }

    // Print Linked List
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
    ll.push_back(10);
    ll.push_back(20);
    ll.push_back(30);
    ll.push_back(40);

    cout << "Linked List:" << endl;
    ll.printList(); // 10 -> 20 -> 30 -> 40 -> NULL

    int key = 30;
    if (ll.searchIterative(key)) {
        cout << key << " found in the Linked List." << endl;
    } else {
        cout << key << " not found in the Linked List." << endl;
    }

    key = 50;
    if (ll.searchIterative(key)) {
        cout << key << " found in the Linked List." << endl;
    } else {
        cout << key << " not found in the Linked List." << endl;
    }

    return 0;
}