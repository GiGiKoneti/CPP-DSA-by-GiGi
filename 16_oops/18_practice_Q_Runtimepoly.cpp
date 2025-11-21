#include <iostream>
using namespace std;

/* ===========================================================
   DEMO: Run-Time Polymorphism
   -----------------------------------------------------------
   → Achieved using "virtual functions".
   → Base class pointer/reference can point to derived object.
   → Function call is resolved at RUNTIME (not compile time).
=========================================================== */

class Base {
public:
    virtual void show() {   // virtual function
        cout << "Base class show()" << endl;
    }
};

class Child : public Base {
public:
    void show() override {   // overriding base class function
        cout << "Child class show()" << endl;
    }
};

int main() {
    Base* ptr;        // base class pointer
    ptr = new Child(); // pointing to derived object

    ptr->show();  // Run-time polymorphism → calls Child::show()

    delete ptr;   // free memory
    return 0;
}

/* ===========================================================
   EXPECTED OUTPUT:
   Child class show()
=========================================================== */