#include <iostream>
using namespace std;

/* ------------------------------------------------------------------
1. POLYMORPHISM
   - Definition: Polymorphism means "many forms".
     A single entity (function/operator) behaves differently
     based on input, context, or the type of object.

   Types:
   (a) Compile-Time Polymorphism → achieved by FUNCTION OVERLOADING 
       and OPERATOR OVERLOADING.
   (b) Run-Time Polymorphism → achieved by FUNCTION OVERRIDING 
       using Virtual Functions.
------------------------------------------------------------------ */

/* ------------------------------------------------------------------
2. Compile-Time Polymorphism
   A. Function Overloading → Same function name, different parameters.
------------------------------------------------------------------ */
class Calculator {
public:
    // Function with 2 integers
    int add(int a, int b) {
        return a + b;
    }

    // Function with 3 integers
    int add(int a, int b, int c) {
        return a + b + c;
    }

    // Function with double
    double add(double a, double b) {
        return a + b;
    }
};

/* ------------------------------------------------------------------
2. Compile-Time Polymorphism
   B. Operator Overloading → redefine operators for user-defined types.
   Example: Complex numbers addition
------------------------------------------------------------------ */
class Complex {
public:
    int real, imag;

    Complex(int r = 0, int i = 0) {
        real = r;
        imag = i;
    }

    // Operator overloading for '+'
    Complex operator+(Complex &obj) {
        Complex res;
        res.real = this->real + obj.real;
        res.imag = this->imag + obj.imag;
        return res;
    }

    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};

/* ------------------------------------------------------------------
3. Run-Time Polymorphism
   A. Function Overriding → Same function in parent & child, 
      executed based on object type.
------------------------------------------------------------------ */
class Parent {
public:
    void show() {
        cout << "Parent class function" << endl;
    }
};

class Child : public Parent {
public:
    void show() {
        cout << "Child class function" << endl;
    }
};

/* ------------------------------------------------------------------
3. Run-Time Polymorphism
   B. Virtual Functions → Using base class pointer to call 
      overridden functions dynamically at runtime.
------------------------------------------------------------------ */
class Base {
public:
    virtual void display() {   // virtual keyword enables dynamic dispatch
        cout << "Display from Base class" << endl;
    }
};

class Derived : public Base {
public:
    void display() override {
        cout << "Display from Derived class" << endl;
    }
};

/* ------------------------------------------------------------------
MAIN FUNCTION
------------------------------------------------------------------ */
int main() {
    cout << "=== Compile-Time Polymorphism: Function Overloading ===" << endl;
    Calculator calc;
    cout << "add(2, 3) = " << calc.add(2, 3) << endl;
    cout << "add(2, 3, 4) = " << calc.add(2, 3, 4) << endl;
    cout << "add(2.5, 3.5) = " << calc.add(2.5, 3.5) << endl;

    cout << "\n=== Compile-Time Polymorphism: Operator Overloading ===" << endl;
    Complex c1(3, 4), c2(1, 2);
    Complex c3 = c1 + c2;  // operator + overloaded
    cout << "c1 + c2 = ";
    c3.display();

    cout << "\n=== Run-Time Polymorphism: Function Overriding ===" << endl;
    Parent p;
    Child c;
    p.show();   // Parent version
    c.show();   // Child version

    cout << "\n=== Run-Time Polymorphism: Virtual Functions ===" << endl;
    Base *ptr;
    Derived d;
    ptr = &d;   // Base class pointer pointing to Derived object
    ptr->display(); // Calls Derived's display() (runtime resolution)

    return 0;
}