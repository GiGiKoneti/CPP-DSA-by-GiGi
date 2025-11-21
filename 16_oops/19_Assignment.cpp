#include <iostream>
#include <string>
using namespace std;

/* ===========================================================
   Question 1:
   Create a class to store Complex numbers. Using operator 
   overloading, create the logic to subtract one complex 
   number from another.
   -----------------------------------------------------------
   RULE: real1 - real2 , imag1 - imag2
=========================================================== */

class Complex {
private:
    int real;
    int imag;

public:
    Complex(int r = 0, int i = 0) {
        real = r;
        imag = i;
    }

    // Overload - operator
    Complex operator-(const Complex& other) {
        return Complex(this->real - other.real, this->imag - other.imag);
    }

    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};

/* ===========================================================
   Question 2:
   Create a class BankAccount with private attributes 
   accountNumber and balance. Implement public methods 
   deposit(), withdraw(), and getBalance().
=========================================================== */

class BankAccount {
private:
    string accountNumber;
    double balance;

public:
    BankAccount(string accNo, double bal) {
        accountNumber = accNo;
        balance = bal;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited: " << amount << endl;
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
        } else {
            cout << "Insufficient funds!" << endl;
        }
    }

    double getBalance() {
        return balance;
    }
};

/* ===========================================================
   Question 3:
   Base class Person → attributes: name, age
   Derived class Student → adds studentID
   Method: displayStudentInfo()
   -----------------------------------------------------------
   NOTE: When creating Student object, base constructor is 
   called first (using initializer list).
=========================================================== */

class Person {
protected:
    string name;
    int age;

public:
    Person(string n, int a) {
        name = n;
        age = a;
    }
};

class Student : public Person {
private:
    string studentID;

public:
    // Call base class constructor using initializer list
    Student(string n, int a, string id) : Person(n, a) {
        studentID = id;
    }

    void displayStudentInfo() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Student ID: " << studentID << endl;
    }
};

/* ===========================================================
   MAIN FUNCTION - TESTING ALL QUESTIONS
=========================================================== */
int main() {
    cout << "=== Question 1: Complex Number Subtraction ===" << endl;
    Complex c1(10, 5), c2(3, 2);
    Complex c3 = c1 - c2;
    c3.display();  // Expected: 7 + 3i

    cout << "\n=== Question 2: BankAccount Management ===" << endl;
    BankAccount acc("ACC123", 1000.0);
    acc.deposit(500);
    acc.withdraw(300);
    cout << "Balance: " << acc.getBalance() << endl;

    cout << "\n=== Question 3: Student Inheritance ===" << endl;
    Student student("Alice", 20, "S12345");
    student.displayStudentInfo();

    return 0;
}