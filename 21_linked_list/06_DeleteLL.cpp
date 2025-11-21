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

    // Function to delete the entire linked list
    void deleteList() {
        /*
        deleteList() logic:
        -------------------
        1. Start from the Head node.
        2. Traverse the list node by node.
        3. For each node, store the next pointer, delete the current node.
        4. Move to the next node using the stored pointer.
        5. After traversal, set Head and Tail to NULL.

        Aspect           | Description
        -----------------|--------------------------------
        Time Complexity  | O(n), need to traverse all nodes
        Space Complexity | O(1), only a temporary pointer is used
        */
        
        Node* current = Head;
        while (current != NULL) {
            Node* nextNode = current->next; // store next node
            delete current;                 // delete current node
            current = nextNode;             // move to next node
        }
        Head = Tail = NULL; // Linked List is now empty
    }
};

int main() {
    List ll;

    // Insert some nodes
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);

    cout << "Original Linked List:" << endl;
    ll.printList(); // 1 -> 2 -> 3 -> 4 -> NULL

    // Delete entire list
    ll.deleteList();

    cout << "After deleting the Linked List:" << endl;
    ll.printList(); // NULL

    return 0;
}