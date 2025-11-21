#include <iostream>
#include <vector>
#include <queue> // For priority_queue in Question 5
#include <functional> // For std::greater in Question 5
using namespace std;

// Definition for singly-linked list node, used across all questions.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Helper Function: Print a linked list
void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

/***************************************************************************************************
 * Question 1: Intersection of Two Linked Lists
 * 
 * Logic:
 * 1. Calculate lengths of both linked lists.
 * 2. Align the start of both lists so remaining lengths are equal.
 * 3. Move both pointers together; the first node where they meet is intersection.
 *
 * Time Complexity: O(n + m) → traverse both lists once to find lengths + one traversal to find intersection
 * Space Complexity: O(1) → constant extra space
 ***************************************************************************************************/
ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    if (!headA || !headB) return nullptr;

    int lenA = 0, lenB = 0;
    ListNode *currA = headA, *currB = headB;

    while (currA) { lenA++; currA = currA->next; }
    while (currB) { lenB++; currB = currB->next; }

    currA = headA; currB = headB;
    if (lenA > lenB) for (int i = 0; i < lenA - lenB; i++) currA = currA->next;
    else for (int i = 0; i < lenB - lenA; i++) currB = currB->next;

    while (currA != currB) {
        currA = currA->next;
        currB = currB->next;
    }
    return currA;
}

void solveIntersection() {
    ListNode* headA = new ListNode(4);
    headA->next = new ListNode(5);
    ListNode* commonNode = new ListNode(6);
    commonNode->next = new ListNode(7);
    headA->next->next = commonNode;

    ListNode* headB = new ListNode(1);
    headB->next = new ListNode(2);
    headB->next->next = new ListNode(3);
    headB->next->next->next = commonNode; // Intersection

    cout << "List A: "; printList(headA);
    cout << "List B: "; printList(headB);

    ListNode* intersection = getIntersectionNode(headA, headB);
    if (intersection)
        cout << "Intersection at node with value: " << intersection->val << endl;
    else
        cout << "No intersection found." << endl;
}

/***************************************************************************************************
 * Question 2: Delete N Nodes After M Nodes
 * 
 * Logic:
 * - Skip M nodes, then delete next N nodes, repeat until end of list.
 *
 * Time Complexity: O(n) → traverse the list once
 * Space Complexity: O(1) → only a few pointers used
 ***************************************************************************************************/
void deleteNAfterM(ListNode* head, int m, int n) {
    ListNode* current = head;
    while (current) {
        for (int i = 1; i < m && current; i++) current = current->next;
        if (!current) break;

        ListNode* nodeToDelete = current->next;
        for (int i = 1; i <= n && nodeToDelete; i++) {
            ListNode* temp = nodeToDelete;
            nodeToDelete = nodeToDelete->next;
            delete temp;
        }
        current->next = nodeToDelete;
        current = nodeToDelete;
    }
}

void solveDeleteNAfterM() {
    ListNode* head = new ListNode(1);
    ListNode* temp = head;
    for (int i = 2; i <= 10; i++) {
        temp->next = new ListNode(i);
        temp = temp->next;
    }
    int m = 3, n = 2;

    cout << "Original List: "; printList(head);
    deleteNAfterM(head, m, n);
    cout << "Modified List: "; printList(head);
}

/***************************************************************************************************
 * Question 3: Swap Nodes in a Linked List
 * 
 * Logic:
 * - Locate nodes for values x and y and their previous nodes.
 * - Update the next pointers to swap nodes without swapping values.
 *
 * Time Complexity: O(n) → traverse list twice at most
 * Space Complexity: O(1)
 ***************************************************************************************************/
void swapNodes(ListNode*& head, int x, int y) {
    if (x == y) return;

    ListNode *prevX = nullptr, *currX = head;
    while (currX && currX->val != x) { prevX = currX; currX = currX->next; }

    ListNode *prevY = nullptr, *currY = head;
    while (currY && currY->val != y) { prevY = currY; currY = currY->next; }

    if (!currX || !currY) return;

    if (prevX) prevX->next = currY;
    else head = currY;
    if (prevY) prevY->next = currX;
    else head = currX;

    swap(currX->next, currY->next);
}

void solveSwapNodes() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    int x = 2, y = 4;

    cout << "Original List: "; printList(head);
    swapNodes(head, x, y);
    cout << "Modified List: "; printList(head);
}

/***************************************************************************************************
 * Question 4: Odd-Even Linked List
 * 
 * Logic:
 * - Create two separate lists for even and odd nodes while preserving order.
 * - Connect even list to odd list.
 *
 * Time Complexity: O(n) → traverse each node once
 * Space Complexity: O(1) → only few pointers used, no extra list allocation
 ***************************************************************************************************/
ListNode* oddEvenList(ListNode* head) {
    if (!head) return nullptr;

    ListNode dummyEven(0), dummyOdd(0);
    ListNode *evenTail = &dummyEven, *oddTail = &dummyOdd;

    ListNode* curr = head;
    while (curr) {
        if (curr->val % 2 == 0) {
            evenTail->next = curr;
            evenTail = evenTail->next;
        } else {
            oddTail->next = curr;
            oddTail = oddTail->next;
        }
        curr = curr->next;
    }

    evenTail->next = dummyOdd.next;
    oddTail->next = nullptr;

    return dummyEven.next;
}

void solveOddEvenList() {
    ListNode* head = new ListNode(8);
    head->next = new ListNode(12);
    head->next->next = new ListNode(10);
    head->next->next->next = new ListNode(5);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(1);
    head->next->next->next->next->next->next = new ListNode(6);

    cout << "Original List: "; printList(head);
    head = oddEvenList(head);
    cout << "Modified List (Evens then Odds): "; printList(head);
}

/***************************************************************************************************
 * Question 5: Merge k Sorted Lists
 * 
 * Logic:
 * - Use a min-heap (priority queue) to always pick the smallest node among k lists.
 *
 * Time Complexity: O(N log k) → N = total nodes, k = number of lists
 * Space Complexity: O(k) → min-heap stores at most k nodes
 ***************************************************************************************************/
struct CompareNodes {
    bool operator()(ListNode* const& a, ListNode* const& b) {
        return a->val > b->val;
    }
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*, vector<ListNode*>, CompareNodes> minHeap;
    for (ListNode* head : lists) if (head) minHeap.push(head);

    ListNode dummy(0);
    ListNode* tail = &dummy;

    while (!minHeap.empty()) {
        ListNode* minNode = minHeap.top();
        minHeap.pop();
        tail->next = minNode;
        tail = tail->next;
        if (minNode->next) minHeap.push(minNode->next);
    }
    return dummy.next;
}

void solveMergeKLists() {
    vector<ListNode*> lists(3);
    lists[0] = new ListNode(1); lists[0]->next = new ListNode(3);
    lists[1] = new ListNode(6); lists[1]->next = new ListNode(8);
    lists[2] = new ListNode(9); lists[2]->next = new ListNode(10);

    cout << "Input Lists:" << endl;
    for(size_t i = 0; i < lists.size(); ++i) {
        cout << "List " << i+1 << ": ";
        printList(lists[i]);
    }

    ListNode* mergedHead = mergeKLists(lists);
    cout << "Merged Sorted List: ";
    printList(mergedHead);
}

// Main Driver
int main() {
    cout << "========================================" << endl;
    cout << "       Executing Linked List Solutions" << endl;
    cout << "========================================" << endl;

    cout << "\n--- Question 1: Intersection of Two Linked Lists ---" << endl;
    solveIntersection();

    cout << "\n--- Question 2: Delete N Nodes After M Nodes ---" << endl;
    solveDeleteNAfterM();
    
    cout << "\n--- Question 3: Swapping Nodes in a Linked List ---" << endl;
    solveSwapNodes();

    cout << "\n--- Question 4: Odd-Even Linked List ---" << endl;
    solveOddEvenList();
    
    cout << "\n--- Question 5: Merge k Sorted Lists ---" << endl;
    solveMergeKLists();

    cout << "\n========================================" << endl;
    cout << "           All tasks completed." << endl;
    cout << "========================================" << endl;

    return 0;
}