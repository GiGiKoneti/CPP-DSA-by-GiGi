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

    // Floyd's Cycle Detection Algorithm
    bool detectCycle() {
        /*
        Logic:
        ------
        1. Use two pointers: slow (moves 1 step) and fast (moves 2 steps)
        2. Traverse the linked list:
            - If there is no cycle, fast or fast->next will become NULL
            - If there is a cycle, slow and fast will meet at some node
        3. Return true if they meet, false otherwise

        Time Complexity: O(n) -> each pointer traverses at most n nodes
        Space Complexity: O(1) -> only two pointers used
        */
        Node* slow = Head;
        Node* fast = Head;

        while (fast && fast->next) {
            slow = slow->next;           // move slow by 1
            fast = fast->next->next;     // move fast by 2

            if (slow == fast) return true; // cycle detected
        }

        return false; // no cycle
    }
};

int main() {
    List ll;
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);

    // Uncomment the next line to create a loop (cycle) at position 2
    // ll.createLoop(2);

    if (ll.detectCycle())
        cout << "Cycle detected in the Linked List" << endl;
    else
        cout << "No cycle in the Linked List" << endl;

    return 0;
}