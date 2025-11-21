#include <iostream>
#include <string>
using namespace std;

class Car {
public: 
    string name;
    string color;
    int *mileage;  // dynamically allocated memory (pointer)

    // Parameterized Constructor
    Car(string name, string color) {
        this->name = name;
        this->color = color;
        mileage = new int;   // allocate memory dynamically
        *mileage = 12;       // default mileage value
    }

    // Custom Copy Constructor for DEEP COPY
    Car(Car &original) {
        cout << "Copying original object to new object..." << endl;
        name = original.name;   
        color = original.color; 
        mileage = new int;              // allocate NEW memory
        *mileage = *original.mileage;   // copy the VALUE, not the pointer
    }
};

int main() {
    Car c1("Mercedes", "Black"); // Original object
    Car c2(c1);                  // Deep copy constructor called

    cout << *c2.mileage << endl; // prints 12

    // Modify mileage of c2
    *c2.mileage = 10;

    // Since it's deep copy → c1 remains unaffected
    cout << *c1.mileage << endl; // prints 12
    cout << *c2.mileage << endl; // prints 10

    return 0;
}

/*
📌 Shallow Copy vs Deep Copy in C++

1. Shallow Copy (default behavior by compiler):
   - Copies all data members bit by bit (including pointer addresses).
   - Both objects end up pointing to the SAME memory location.
   - Changes in one object’s pointer data will reflect in the other.
   - Example: 
       Car c2 = c1; // compiler-generated copy constructor
       *c2.mileage = 10;  → also changes *c1.mileage

2. Deep Copy (user-defined copy constructor):
   - Allocates SEPARATE memory for the copied object.
   - Copies the VALUE stored at the pointer, not the pointer address.
   - Both objects work independently without affecting each other.
   - Example:
       Custom copy constructor ensures new memory is created for c2.
       *c2.mileage = 10; → does NOT affect *c1.mileage.

✔ Use shallow copy when class has no pointers/dynamic memory.
✔ Use deep copy when class manages dynamic resources (pointers, heap memory).
*/