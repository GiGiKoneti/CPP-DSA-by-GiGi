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

    // Destructor to delete entire linked list
    ~List() {
        Node* current = Head;
        while (current != NULL) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        Head = Tail = NULL;
        cout << "Destructor called: Entire Linked List deleted." << endl;
    }

    // Insert at front
    void push_front(int val) {
        Node* newNode = new Node(val);
        if (Head == NULL) {
            Head = Tail = newNode;
        } else {
            newNode->next = Head;
            Head = newNode;
        }
    }

    // Remove node from back
    void pop_back() {
        /*
        pop_back() logic:
        ----------------
        1. Check if list is empty: nothing to remove.
        2. If only one node exists: delete Head and set Head and Tail to NULL.
        3. Otherwise:
            - Traverse to the second-last node.
            - Delete Tail node.
            - Update Tail to second-last node and set Tail->next = NULL.
        
        Time Complexity  : O(n) - need to traverse to second-last node
        Space Complexity : O(1) - no extra memory
        */
        if (Head == NULL) {
            cout << "List is empty. Nothing to pop." << endl;
            return;
        }

        if (Head == Tail) {
            delete Head;
            Head = Tail = NULL;
            return;
        }

        Node* temp = Head;
        while (temp->next != Tail) { // traverse to second-last node
            temp = temp->next;
        }
        delete Tail;
        Tail = temp;
        Tail->next = NULL;
    }

    // Print linked list
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

    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);

    cout << "Linked List before pop_back:" << endl;
    ll.printList(); // 1 -> 2 -> 3 -> NULL

    ll.pop_back(); // removes 3
    cout << "After pop_back:" << endl;
    ll.printList(); // 1 -> 2 -> NULL

    ll.pop_back(); // removes 2
    ll.pop_back(); // removes 1
    cout << "After popping all elements:" << endl;
    ll.printList(); // NULL

    ll.pop_back(); // trying to pop from empty list

    return 0;
}