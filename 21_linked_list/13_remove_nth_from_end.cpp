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

public:
    List() {
        Head = NULL;
    }

    // Insert at the end
    void push_back(int val) {
        Node* newNode = new Node(val);
        if (Head == NULL) {
            Head = newNode;
            return;
        }
        Node* temp = Head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Remove nth node from end
    void removeNthFromEnd(int n) {
        /*
        Logic:
        ------
        1. Use two pointers: first and second, both start at Head
        2. Move first pointer n steps ahead
        3. If first becomes NULL, remove head
        4. Move both pointers until first->next == NULL
        5. second->next = second->next->next (removes target)
        Time Complexity: O(n)
        Space Complexity: O(1)
        */
        Node* dummy = new Node(0); // dummy node to handle edge cases
        dummy->next = Head;
        Node* first = dummy;
        Node* second = dummy;

        // Move first n+1 steps ahead
        for (int i = 0; i <= n; i++) {
            if (first == NULL) return; // n is larger than list size
            first = first->next;
        }

        // Move first to the end, maintaining gap
        while (first != NULL) {
            first = first->next;
            second = second->next;
        }

        // Remove nth node
        Node* toDelete = second->next;
        second->next = second->next->next;
        delete toDelete;

        Head = dummy->next;
        delete dummy;
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
    ll.push_back(5);

    cout << "Original List:" << endl;
    ll.printList(); // 1 -> 2 -> 3 -> 4 -> 5 -> NULL

    int n = 2; // Remove 2nd node from end
    ll.removeNthFromEnd(n);

    cout << "After removing " << n << "th node from end:" << endl;
    ll.printList(); // 1 -> 2 -> 3 -> 5 -> NULL

    return 0;
}