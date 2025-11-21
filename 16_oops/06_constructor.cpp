#include <iostream>
using namespace std;

/*
OOP Concepts Illustrated:
1. Constructor:
   - Special member function called automatically when an object is created.
   - Used to initialize object attributes.

2. Constructor Overloading:
   - Multiple constructors with different parameters in the same class.
   - Allows creating objects in different ways.

3. Parameterized Constructor:
   - Constructor that takes arguments to initialize attributes.

4. 'this' Pointer:
   - Refers to the current object.
   - Used to differentiate between class attributes and parameters with the same name.

5. Memory Allocation of Attributes:
   - When a constructor is called, memory for the object's attributes is allocated automatically.
*/

class Car {
    string name;   // private data member
    string colour; // private data member

public:
    // Non-parameterized constructor (default)
    Car() {
        cout << "Constructor without parameters called.\n";
        cout << "Automatically initializes object and allocates memory for attributes.\n";
    }

    // Parameterized constructor (overloaded)
    Car(string name, string colour) {
        cout << "Constructor with parameters called.\n";
        // 'this' pointer differentiates between object attributes and parameters
        this->name = name;
        this->colour = colour;
    }

    // Member functions
    void start() {
        cout << "Car started." << endl;
    }

    void stop() {
        cout << "Car stopped." << endl;
    }

    // Getter for name
    string getName() {
        return name;
    }
};

int main() {
    // Calls default constructor
    Car c0;

    // Calls parameterized constructor
    Car c1("Mercedes", "Black"); // memory for 'name' and 'colour' allocated automatically

    cout << "Car name: " << c1.getName() << endl;

    return 0;
}

/*
Key Points Recap:
1. Constructor is automatically invoked when object is created.
2. Constructor Overloading allows multiple constructors with different parameters.
3. 'this->' pointer is used to refer to current object's attributes.
4. Parameterized constructor initializes object attributes directly.
5. Memory for attributes is allocated automatically during constructor execution.
*/