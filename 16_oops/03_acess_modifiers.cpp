#include <iostream>
using namespace std;

/*
    Access Modifiers in C++:
    -------------------------
    1. private   : Accessible only within the class. (Default for class)
    2. public    : Accessible from anywhere (inside and outside the class).
    3. protected : Accessible within the class AND by derived (child) classes,
                   but NOT from outside the class.
*/

class Base {
private:    // Private members
    int privateVar;

public:     // Public members
    int publicVar;

protected:  // Protected members
    int protectedVar;

public:
    // Constructor to initialize values
    Base() {
        privateVar = 10;
        publicVar = 20;
        protectedVar = 30;
    }

    // Public function can access private & protected members inside the class
    void showBaseData() {
        cout << "Inside Base Class:" << endl;
        cout << "Private Var: " << privateVar << endl;
        cout << "Public Var: " << publicVar << endl;
        cout << "Protected Var: " << protectedVar << endl;
    }
};

// Derived class (Child) inherits from Base
class Derived : public Base {
public:
    void showDerivedData() {
        cout << "\nInside Derived Class:" << endl;

        // cout << "Private Var: " << privateVar << endl;   // ❌ Error: Not accessible

        cout << "Public Var: " << publicVar << endl;        // ✅ Accessible (public stays public)
        cout << "Protected Var: " << protectedVar << endl;  // ✅ Accessible because derived can access protected
    }
};

int main() {
    Base b;
    Derived d;

    cout << "--- Accessing from Base object ---" << endl;
    b.showBaseData();              // ✅ Works (public method can access everything inside class)

    cout << "\nTrying direct access using object:" << endl;
    // cout << b.privateVar;       // ❌ Error: private not accessible outside class
    cout << "Public Var: " << b.publicVar << endl;   // ✅ Accessible (public)
    // cout << b.protectedVar;     // ❌ Error: protected not accessible outside class

    cout << "\n--- Accessing from Derived class ---" << endl;
    d.showDerivedData();           // ✅ Derived can access public & protected

    return 0;
}