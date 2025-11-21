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

    // Remove node from front
    void pop_front() {
        /*
        pop_front() logic:
        -----------------
        1. Check if list is empty: nothing to remove.
        2. Store Head in temp pointer.
        3. Move Head to next node.
        4. Delete the old Head.
        5. If Head becomes NULL, also set Tail to NULL.
        
        Time Complexity  : O(1) - constant time
        Space Complexity : O(1) - no extra space
        */
        if (Head == NULL) {
            cout << "List is empty. Nothing to pop." << endl;
            return;
        }

        Node* temp = Head;
        Head = Head->next;
        if (Head == NULL) {
            Tail = NULL; // List is now empty
        }
        delete temp;
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

    cout << "Linked List before pop_front:" << endl;
    ll.printList(); // 1 -> 2 -> 3 -> NULL

    ll.pop_front(); // removes 1
    cout << "After pop_front:" << endl;
    ll.printList(); // 2 -> 3 -> NULL

    ll.pop_front(); // removes 2
    ll.pop_front(); // removes 3
    cout << "After popping all elements:" << endl;
    ll.printList(); // NULL

    ll.pop_front(); // trying to pop from empty list

    return 0;
}