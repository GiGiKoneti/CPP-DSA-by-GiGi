#include <iostream>
#include <stack>
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
    Node* Head;

public:
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

    // Print Linked List
    void printList() {
        Node* temp = Head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Check if palindrome
    bool isPalindrome() {
        /*
        Logic:
        ------
        1. Use two-pointer technique (fast and slow) to find middle
        2. Push first half elements into a stack
        3. For the second half, compare elements with stack top
        4. If all match, return true, else false
        Time Complexity: O(n)
        Space Complexity: O(n) due to stack
        */
        if (!Head || !Head->next) return true; // empty or single node

        Node* slow = Head;
        Node* fast = Head;
        stack<int> s;

        // Push first half into stack
        while (fast && fast->next) {
            s.push(slow->data);
            slow = slow->next;
            fast = fast->next->next;
        }

        // If odd number of elements, skip the middle node
        if (fast) slow = slow->next;

        // Compare second half with stack
        while (slow) {
            if (s.top() != slow->data) return false;
            s.pop();
            slow = slow->next;
        }
        return true;
    }
};

int main() {
    List ll;
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(2);
    ll.push_back(1);

    ll.printList();

    if (ll.isPalindrome())
        cout << "Linked List is a Palindrome" << endl;
    else
        cout << "Linked List is NOT a Palindrome" << endl;

    return 0;
}