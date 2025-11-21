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

    // Insert at the end
    void push_back(int val) {
        Node* newNode = new Node(val);
        if (Head == NULL) {
            Head = Tail = newNode;
        } else {
            Tail->next = newNode;
            Tail = newNode;
        }
    }

    // Iterative reverse
    void reverseIterative() {
        /*
        Logic:
        ------
        1. Initialize three pointers: prev=NULL, curr=Head, next=NULL
        2. Traverse the list:
            - next = curr->next
            - curr->next = prev
            - prev = curr
            - curr = next
        3. Update Head = prev
        Time Complexity : O(n)
        Space Complexity: O(1)
        */
        Node* prev = NULL;
        Node* curr = Head;
        Node* next = NULL;

        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        Head = prev;
    }

    // Recursive reverse helper
    Node* reverseRecursiveHelper(Node* node) {
        /*
        Logic:
        ------
        Base Case: If node is NULL or node->next is NULL, return node
        Recursive Case: reverse rest of the list
        Connect node->next->next = node
        node->next = NULL
        Return new head
        Time Complexity : O(n)
        Space Complexity: O(n) due to recursion stack
        */
        if (node == NULL || node->next == NULL) return node;
        Node* newHead = reverseRecursiveHelper(node->next);
        node->next->next = node;
        node->next = NULL;
        return newHead;
    }

    void reverseRecursive() {
        Head = reverseRecursiveHelper(Head);
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
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);

    cout << "Original List:" << endl;
    ll.printList(); // 1 -> 2 -> 3 -> 4 -> NULL

    ll.reverseIterative();
    cout << "After Iterative Reverse:" << endl;
    ll.printList(); // 4 -> 3 -> 2 -> 1 -> NULL

    ll.reverseRecursive();
    cout << "After Recursive Reverse (back to original):" << endl;
    ll.printList(); // 1 -> 2 -> 3 -> 4 -> NULL

    return 0;
}