#include <iostream> 
#include <string>
using namespace std;

class Car {
public: 
    string name;
    string color;

    // Parameterized Constructor
    Car(string name, string color) {
        this->name = name;
        this->color = color;
    }

    // Custom Copy Constructor
    Car(Car &original) {
        cout << "Copying original object to new object..." << endl;
        name = original.name;   // Copy attributes from original
        color = original.color; // Copy attributes from original
    }
};

int main() {
    Car c1("Mercedes", "Black"); // Normal object creation

    // Copy constructor is called when a new object is created from an existing one
    Car c2(c1);  

    cout << c2.name << endl;
    cout << c2.color << endl;

    return 0;
}

/*
📌 Copy Constructor in C++

Definition:
A copy constructor is a special constructor in C++ that initializes a new object 
as a copy of an existing object.

Types:
1. Default Copy Constructor (provided by compiler)
   - Performs a shallow copy (copies member values directly).
   - Example: Car c2 = c1;  // compiler auto-generates copy constructor.

2. Custom Copy Constructor (user-defined)
   - You define how copying should happen.
   - Useful when class has dynamically allocated memory or pointers.

When is it called?
- When you create a new object from an existing object.
- Passed by value to a function.
- Returned by value from a function.

In this example:
- c2 is created from c1 → our custom copy constructor is invoked.
- It explicitly copies `name` and `color`.

Key Notes:
✔ If you don’t define a copy constructor, C++ automatically provides one.
✔ Custom copy constructor is important for deep copies (when you deal with pointers).
✔ Prevents unwanted shallow copies which may cause bugs in memory handling.
*/