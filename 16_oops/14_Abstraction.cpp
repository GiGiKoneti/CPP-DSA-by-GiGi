#include <iostream>
using namespace std;

/* -------------------------------------------------------------------
1. ABSTRACTION
   - Definition: Abstraction is the process of hiding the internal 
     implementation details and showing only the essential features 
     to the user.
   - Achieved using Abstract Classes and Pure Virtual Functions.
------------------------------------------------------------------- */

/* -------------------------------------------------------------------
2. Abstract Class
   - A class that contains at least one PURE VIRTUAL FUNCTION.
   - It cannot be instantiated directly.
------------------------------------------------------------------- */
class Shape {
public:
    // 3. Pure Virtual Function (Abstract Function)
    virtual void draw() = 0; // no definition here, only declaration

    // Normal function inside abstract class
    void info() {
        cout << "This is a shape." << endl;
    }
};

/* Derived classes must override the pure virtual function */
class Circle : public Shape {
public:
    void draw() override {  // Overriding pure virtual function
        cout << "Drawing Circle" << endl;
    }
};

class Rectangle : public Shape {
public:
    void draw() override {
        cout << "Drawing Rectangle" << endl;
    }
};

/* -------------------------------------------------------------------
4. Difference b/w Virtual Function and Pure Virtual Function
   - Virtual Function:
       → Has a definition in base class
       → Can be overridden in child class
       → Base class can still be instantiated

   - Pure Virtual Function:
       → No definition in base class ( = 0 )
       → Must be overridden in child class
       → Makes the class ABSTRACT → cannot create object of base
------------------------------------------------------------------- */

/* Example Virtual Function */
class Animal {
public:
    virtual void sound() {   // normal virtual function
        cout << "Some generic sound" << endl;
    }
};

/* Example Pure Virtual Function (Abstract Function) */
class Vehicle {
public:
    virtual void start() = 0; // pure virtual → no body
};

/* -------------------------------------------------------------------
5. ERROR CASE:
   - If you try to create an object of abstract class, compiler error.
   Example:
       Shape s;   ❌ ERROR: cannot declare variable ‘s’ to be of abstract type ‘Shape’
------------------------------------------------------------------- */

int main() {
    cout << "=== Abstraction with Abstract Class ===" << endl;
    Circle c;
    Rectangle r;

    Shape *s1 = &c;
    Shape *s2 = &r;

    s1->draw();   // Circle version
    s2->draw();   // Rectangle version
    s1->info();   // Normal function from abstract class

    cout << "\n=== Virtual Function Example ===" << endl;
    Animal a;
    a.sound();  // Calls base version

    cout << "\n=== Pure Virtual Function Example (Abstract Class) ===" << endl;
    // Vehicle v;  // ❌ ERROR: Vehicle is abstract, cannot instantiate
    cout << "Cannot create object of Vehicle since it has a pure virtual function." << endl;

    return 0;
}