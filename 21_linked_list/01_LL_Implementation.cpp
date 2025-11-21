#include <iostream>
using namespace std;

// Node class to represent each element in the Linked List
class Node {
    int data;
    Node* next;

public:
    // Constructor
    Node(int val) {
        data = val;
        next = NULL;
    }

    // Grant access to List class (so it can access private members of Node)
    friend class List;
};

// Linked List class
class List {
    Node* Head;
    Node* Tail;

public:
    // Constructor: initialize Head and Tail as NULL
    List() {
        Head = NULL;
        Tail = NULL;
    }
};

int main() {
    /*
    ⚠️ Important Note:
    ------------------
    In C++, writing `List ll();` in main() does NOT create an object.
    Instead, it declares a function named "ll" that returns a List object 
    (this is called the "Most Vexing Parse" problem).

    ✅ Correct way:
        List ll;   // Creates an object 'll' of type List.

    */
    List ll;  // Object 'll' of class List created here.

    return 0;
}