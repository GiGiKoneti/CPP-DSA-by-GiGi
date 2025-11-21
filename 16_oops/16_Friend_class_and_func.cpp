#include <iostream>
using namespace std;

/* ===============================================================
   1. FRIEND CLASS
   - A friend class can access private and protected members 
     of another class.
================================================================ */
class Engine {
private:
    int horsepower;

public:
    Engine(int hp) {
        horsepower = hp;
    }

    // Declare Car as friend class → can access horsepower
    friend class Car;
};

class Car {
public:
    void showEnginePower(Engine &e) {
        cout << "Engine Horsepower (accessed by Friend Class): " 
             << e.horsepower << endl;
    }
};

/* ===============================================================
   2. FRIEND FUNCTION
   - A non-member function that is allowed to access 
     private/protected members of a class.
================================================================ */
class Box {
private:
    int length;

public:
    Box(int l) {
        length = l;
    }

    // Declare friend function
    friend void printLength(Box &b);
};

// Friend function defined outside
void printLength(Box &b) {
    cout << "Box length (accessed by Friend Function): " 
         << b.length << endl;
}

/* ==============================================================================
   3. DIFFERENCE BETWEEN FRIEND & INHERITANCE
   ------------------------------------------------------------------------------
   Aspect                | Friend                            | Inheritance
   -----------------------------------------------------------------------------
   Access private data   | YES (via friend declaration)      | NO (private 
                         | unless exposed with getter/setter)|
   Relationship type     | Not is-a (just access)            | is-a relationship
   Direction             | Friendship is one-way             | Inheritance is 
                         | (A→B doesn’t imply B→A)           | two-way hierarchy
   Usage purpose         | Access specific data/functions    | Code reusability
===============================================================================*/

int main() {
    cout << "=== Friend Class Demo ===" << endl;
    Engine e1(500);
    Car c1;
    c1.showEnginePower(e1);

    cout << "\n=== Friend Function Demo ===" << endl;
    Box b1(15);
    printLength(b1);

    cout << "\n=== Difference: Friend vs Inheritance ===" << endl;
    cout << "Friendship gives ACCESS, Inheritance gives RELATIONSHIP." << endl;

    return 0;
}