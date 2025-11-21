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

    // Recursive search helper
    bool searchRecursiveHelper(Node* node, int key) {
        /*
        Recursive Search Logic:
        -----------------------
        1. Base Case: If node is NULL, return false (key not found).
        2. Check if node->data == key. If yes, return true.
        3. Otherwise, recursively call searchRecursiveHelper on node->next.
        
        Time Complexity  : O(n) – may traverse all nodes in worst case.
        Space Complexity : O(n) – due to recursive call stack.
        */
        if (node == NULL) {
            return false; // key not found
        }
        if (node->data == key) {
            return true; // key found
        }
        return searchRecursiveHelper(node->next, key);
    }

    // Public function to call recursive search
    bool searchRecursive(int key) {
        return searchRecursiveHelper(Head, key);
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

    int key = 20;
    if (ll.searchRecursive(key)) {
        cout << key << " found in the Linked List." << endl;
    } else {
        cout << key << " not found in the Linked List." << endl;
    }

    key = 50;
    if (ll.searchRecursive(key)) {
        cout << key << " found in the Linked List." << endl;
    } else {
        cout << key << " not found in the Linked List." << endl;
    }

    return 0;
}