#include <iostream>
using namespace std;

// Node class
class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to print linked list
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Function to reverse a linked list
Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    Node* next;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// Function to find middle node of linked list
Node* findMiddle(Node* head) {
    Node* slow = head;
    Node* fast = head->next; // For first half to have one extra if odd
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Function to reorder list in zig-zag fashion: 1->2->3->4->5 => 1->5->2->4->3
void zigZagList(Node* &head) {
    if (!head || !head->next) return;

    // Step 1: Find middle
    Node* mid = findMiddle(head);

    // Step 2: Reverse second half
    Node* second = reverseList(mid->next);
    mid->next = nullptr; // split first and second half

    // Step 3: Merge alternately
    Node* first = head;
    Node* temp1;
    Node* temp2;

    while (first && second) {
        temp1 = first->next;
        temp2 = second->next;

        first->next = second;
        if (!temp1) break; // in case of odd nodes
        second->next = temp1;

        first = temp1;
        second = temp2;
    }
}

// Driver code
int main() {
    // Create linked list: 1->2->3->4->5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Original List: ";
    printList(head);

    zigZagList(head);

    cout << "Zig-Zag List: ";
    printList(head);

    return 0;
}

/*
Explanation:
------------
1. Find the middle of the linked list using slow and fast pointers.
2. Reverse the second half of the list.
3. Merge the two halves alternately:
   - first node from first half, first node from second half, second node from first half, second node from second half, ...
4. Time Complexity: O(n) – traverses the list multiple times but linear.
5. Space Complexity: O(1) – in-place operation, no extra memory used.
*/