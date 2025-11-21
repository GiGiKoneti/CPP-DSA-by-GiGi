#include<iostream>
using namespace std;

/*
    Class: Student
    -----------------
    - Demonstrates Object-Oriented Programming (OOP) basics in C++.
    - A class is a user-defined data type that contains:
        1. **Data Members (Attributes/Properties)**
        2. **Member Functions (Methods/Behaviors)**
*/
class Student {
    // By default, members of a class in C++ are private unless explicitly specified.

    string name;   // Data member: stores the name of the student.
    float cgpa;    // Data member: stores the CGPA of the student.

    // Member Function: used to calculate percentage from CGPA.
    void getPercentage() {
        cout << cgpa * 10 << "%" << endl;
    }
};

int main() {
    /*
        Object Creation:
        -----------------
        - 's1' is an object (instance) of the class 'Student'.
        - An object contains its own copy of the class's data members.
    */
    Student s1;

    /*
        sizeof(s1):
        -----------------
        - Returns the total size (in bytes) occupied by the object 's1'.
        - The size is determined by the sum of the sizes of data members
          (here: 'string' + 'float') + compiler-specific padding/alignments.
        - Private data members also occupy memory even though they are not directly accessible.
    */
    cout << sizeof(s1) << endl;

    return 0;
}

/*
    Key OOP Concepts Used:
    -----------------
    1. **Encapsulation**: 
       - The data members (name, cgpa) and method (getPercentage) are hidden inside the class.
       - They are private and cannot be accessed directly from outside.

    2. **Abstraction**:
       - The details of how percentage is calculated are hidden in getPercentage().

    Note:
    -----
    - Since all members are private by default and we haven’t declared any public members,
      we cannot access name, cgpa, or getPercentage() directly from 'main'.
*/ 