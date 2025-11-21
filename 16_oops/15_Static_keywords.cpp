#include <iostream>
using namespace std;

/* ===============================================================
   1. STATIC KEYWORD
   - "static" can be used with:
        → variables
        → class members
        → objects
================================================================ */

/* ===============================================================
   TABLE 1: Normal Variable vs Static Variable (inside function)
   ---------------------------------------------------------------
   Aspect                | Normal Variable       | Static Variable
   ---------------------------------------------------------------
   Initialization        | Every function call   | Only once (first call)
   Lifetime              | Scope of function     | Till program ends
   Value Retention       | Does NOT retain       | Retains between calls
   Memory Allocation     | Stack                 | Data Segment
=================================================================*/

/* 2.01 Normal vs Static variable inside a FUNCTION */
void demoFunction() {
    int normalVar = 0;        // re-initialized every function call
    static int staticVar = 0; // initialized once, retains value

    normalVar++;
    staticVar++;

    cout << "Normal Var: " << normalVar << " | Static Var: " << staticVar << endl;
}

/* 2.2 Static variable inside a CLASS */
class Student {
public:
    string name;
    static int count;  // static member → shared across all objects

    Student(string name) {
        this->name = name;
        count++;
    }

    void display() {
        cout << "Student: " << name << ", Total Students: " << count << endl;
    }
};

// 2.2.1 Assigning a constant value to static member OUTSIDE class
int Student::count = 0;  // Must be defined outside the class

/* ===============================================================
   TABLE 2: Normal Object vs Static Object
   ---------------------------------------------------------------
   Aspect                | Normal Object         | Static Object
   ---------------------------------------------------------------
   Creation              | On entering scope     | On entering scope
   Destruction           | On leaving scope      | At program termination
   Lifetime              | Scope of block        | Entire program duration
   Constructor call      | Every time block runs | Only first time block runs
   Destructor call       | At block end          | At program end
=================================================================*/

/* 3. Static Object */
class Test {
public:
    Test() {
        cout << "Constructor called!" << endl;
    }
    ~Test() {
        cout << "Destructor called!" << endl;
    }
};

void objectDemo() {
    cout << "Entering block..." << endl;
    {
        Test normalObj; // Normal object → destroyed at end of block
    }
    cout << "Exited block (normalObj destroyed)" << endl;

    cout << "\nEntering block with static object..." << endl;
    {
        static Test staticObj; // Created only ONCE, lives till program ends
    }
    cout << "Exited block (staticObj NOT destroyed here)" << endl;
}

/* ===============================================================
   MAIN FUNCTION
=================================================================*/
int main() {
    cout << "=== Static Variable Demo (Function) ===" << endl;
    demoFunction(); // Normal=1, Static=1
    demoFunction(); // Normal=1, Static=2
    demoFunction(); // Normal=1, Static=3

    cout << "\n=== Static Variable Demo (Class) ===" << endl;
    Student s1("GiGi");
    s1.display();
    Student s2("Molki");
    s2.display();

    cout << "\n=== Static Object Demo ===" << endl;
    objectDemo();

    cout << "\nProgram is ending... now static objects will be destroyed." << endl;

    return 0;
}