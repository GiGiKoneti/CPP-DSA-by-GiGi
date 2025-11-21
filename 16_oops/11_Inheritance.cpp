#include <iostream>
using namespace std;

// ---------------- Base Class ----------------
class Animal {
    void sleep() { // private by default in class
        cout << "Sleeps" << endl;
    }

public:
    string color;

    void eat() {
        cout << "Eats" << endl;
    }

protected:
    void breath() {
        cout << "Breathes" << endl;
    }
};

// ---------------- Derived Classes ----------------

// Public Inheritance
class Fish : public Animal {
public:
    int fins;

    void swim() {
        cout << "Swims" << endl;
    }

    void showAccess() {
        eat();     // ✅ public stays public
        breath();  // ✅ protected stays protected
        // sleep(); // ❌ private not accessible
    }
};

// Protected Inheritance
class Dog : protected Animal {
public:
    void bark() {
        cout << "Barks" << endl;
    }

    void showAccess() {
        eat();     // ✅ becomes protected in Dog
        breath();  // ✅ remains protected
        // sleep(); // ❌ private not accessible
    }
};

// Private Inheritance
class Cat : private Animal {
public:
    void meow() {
        cout << "Meows" << endl;
    }

    void showAccess() {
        eat();     // ✅ becomes private in Cat
        breath();  // ✅ becomes private in Cat
        // sleep(); // ❌ private not accessible
    }
};

// ---------------- Main Function ----------------
int main() {
    // Public Inheritance
    Fish f1;
    f1.swim();
    f1.eat();      // ✅ accessible (still public)
    // f1.breath(); // ❌ not accessible (protected)

    // Protected Inheritance
    Dog d1;
    d1.bark();
    // d1.eat();   // ❌ inaccessible (became protected)
    // d1.breath();// ❌ inaccessible

    // Private Inheritance
    Cat c1;
    c1.meow();
    // c1.eat();   // ❌ inaccessible (became private)
    // c1.breath();// ❌ inaccessible

    return 0;
}

/*
📌 Modes of Inheritance in C++

When a class inherits from a base class, the **mode of inheritance** determines 
how the base class members (public, protected, private) are inherited.

---------------------------------------------------------
1. Public Inheritance (class Derived : public Base)
   - Public members of Base → remain Public in Derived.
   - Protected members of Base → remain Protected in Derived.
   - Private members of Base → NOT accessible in Derived.
   ✅ "IS-A" relationship → Fish IS-A Animal.

2. Protected Inheritance (class Derived : protected Base)
   - Public members of Base → become Protected in Derived.
   - Protected members of Base → remain Protected in Derived.
   - Private members of Base → NOT accessible in Derived.
   ⚠️ Used for restricted access where external world shouldn't 
      see base public interface directly.

3. Private Inheritance (class Derived : private Base)
   - Public members of Base → become Private in Derived.
   - Protected members of Base → become Private in Derived.
   - Private members of Base → NOT accessible in Derived.
   ⚠️ "Has-A" relationship but used rarely.

---------------------------------------------------------
📌 Variants of Each:
Inheritance interacts differently with **Base class members**:

Base Members →   Public Inheritance | Protected Inheritance | Private Inheritance
-----------------------------------------------------------------------------
Public          → Public            | Protected             | Private
Protected       → Protected         | Protected             | Private
Private         → Not Inherited     | Not Inherited         | Not Inherited
-----------------------------------------------------------------------------
*/