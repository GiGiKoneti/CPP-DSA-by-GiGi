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

    // Destructor deletes the entire linked list
    ~List() {
        /*
        Destructor logic:
        -----------------
        1. Start from Head.
        2. Traverse the list node by node.
        3. Delete each node.
        4. After deletion, Head and Tail automatically become NULL (as object is destroyed).

        Aspect           | Description
        -----------------|--------------------------------
        Time Complexity  | O(n), each node is visited once
        Space Complexity | O(1), only a temporary pointer used
        */
        Node* current = Head;
        while (current != NULL) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        Head = Tail = NULL;
        cout << "Destructor called: Entire Linked List deleted." << endl;
    }

    // Function to insert a node at the end
    void push_back(int val) {
        Node* newNode = new Node(val);
        if (Head == NULL) {
            Head = Tail = newNode;
        } else {
            Tail->next = newNode;
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
    {
        List ll; // Linked List object

        // Insert some nodes
        ll.push_back(1);
        ll.push_back(2);
        ll.push_back(3);
        ll.push_back(4);

        cout << "Linked List:" << endl;
        ll.printList(); // 1 -> 2 -> 3 -> 4 -> NULL

        // Destructor will automatically be called at the end of this block
    }

    cout << "End of main. Linked List object out of scope." << endl;

    return 0;
}