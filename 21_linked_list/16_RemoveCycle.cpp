#include <iostream>
using namespace std;

// Node class representing each element in the Linked List
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }

    friend class List;
};

// Linked List class
class List {
public:
    Node* Head;

    List() {
        Head = NULL;
    }

    // Insert at end
    void push_back(int val) {
        Node* newNode = new Node(val);
        if (!Head) {
            Head = newNode;
            return;
        }
        Node* temp = Head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    // Function to create a loop for testing
    void createLoop(int pos) {
        if (pos == 0) return;
        Node* temp = Head;
        Node* loopNode = nullptr;
        int count = 1;
        while (temp->next) {
            if (count == pos) loopNode = temp;
            temp = temp->next;
            count++;
        }
        temp->next = loopNode; // create loop
    }

    // Function to detect and remove cycle
    void removeCycle() {
        /*
        Logic:
        ------
        1. Detect cycle using Floyd's algorithm (slow & fast pointers)
        2. Once cycle is detected (slow == fast):
            - Reset one pointer to Head
            - Move both pointers one step at a time
            - They will meet at the start of the loop
        3. To remove cycle:
            - Traverse until the node whose next points to loop start
            - Set that node's next to NULL

        Time Complexity: O(n)
        Space Complexity: O(1)
        */
        Node* slow = Head;
        Node* fast = Head;
        bool cycleFound = false;

        // Step 1: Detect cycle
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                cycleFound = true;
                break;
            }
        }

        if (!cycleFound) {
            cout << "No cycle to remove." << endl;
            return;
        }

        // Step 2: Find start of loop
        slow = Head;
        Node* prev = nullptr; // to keep track of node before meeting point
        while (slow != fast) {
            prev = fast;
            slow = slow->next;
            fast = fast->next;
        }

        // Step 3: Remove cycle
        prev->next = NULL;
        cout << "Cycle removed from the Linked List." << endl;
    }

    // Helper function to print the linked list
    void printList() {
        Node* temp = Head;
        while (temp) {
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

    // Create a cycle at position 2 (node with value 2)
    ll.createLoop(2);

    ll.removeCycle();   // Detect and remove cycle
    ll.printList();     // Should print: 1->2->3->4->5->NULL

    return 0;
}