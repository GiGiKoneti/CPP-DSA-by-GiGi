#include <iostream>
using namespace std;

class Student {
private:
    // private data members (cannot be accessed directly outside class)
    string name;
    float cgpa;

public:
    // Setter: assigns values to private members
    void setName(string n) {
        name = n;
    }

    void setCgpa(float c) {
        cgpa = c;
    }

    // Getter: retrieves values of private members
    string getName() {
        return name;
    }

    float getCgpa() {
        return cgpa;
    }
};

int main() {
    Student s1;

    // Using setters to assign values
    s1.setName("GiGi");
    s1.setCgpa(9.1);

    // Using getters to access values
    cout << "Name: " << s1.getName() << endl;
    cout << "CGPA: " << s1.getCgpa() << endl;

    return 0;
}

/*
👉 Explanation:
- Private members (name, cgpa) cannot be accessed directly from main().
- Setters (setName, setCgpa) are used to assign values.
- Getters (getName, getCgpa) are used to retrieve values.
- This ensures **data encapsulation** and controlled access to class data.
*/