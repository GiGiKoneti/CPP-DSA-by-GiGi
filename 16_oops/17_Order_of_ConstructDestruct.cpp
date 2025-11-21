#include <iostream>
using namespace std;

/* ===============================================================
   DEMO: Order of Constructor & Destructor Calls
   ---------------------------------------------------------------
   RULE:
   1. Base class (Parent) constructor is called BEFORE Derived (Child).
   2. Derived class (Child) constructor is called AFTER Base.
   3. Destruction order is REVERSE:
        → Derived (Child) destructor first
        → Base (Parent) destructor last
================================================================ */

class Parent {
public:
    Parent() {
        cout << "Parent Constructor called" << endl;
    }

    ~Parent() {
        cout << "Parent Destructor called" << endl;
    }
};

class Child : public Parent {
public:
    Child() {
        cout << "Child Constructor called" << endl;
    }

    ~Child() {
        cout << "Child Destructor called" << endl;
    }
};

int main() {
    cout << "=== Object Creation ===" << endl;
    Child obj;   // Creating Child object (triggers Parent+Child constructors)

    cout << "\n=== End of main() ===" << endl;
    return 0;    // Object goes out of scope → destructors called
}

/* ===============================================================
   EXPECTED OUTPUT
   ---------------------------------------------------------------
   === Object Creation ===
   Parent Constructor called
   Child Constructor called

   === End of main() ===
   Child Destructor called
   Parent Destructor called
================================================================ */