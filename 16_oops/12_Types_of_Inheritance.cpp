#include <iostream>
using namespace std;

/* --------------------------------------------------
1. Single Inheritance (Animal -> Mammal)
-------------------------------------------------- */
class Animal {
public:
    void eat() {
        cout << "Animal eats" << endl;
    }
};

class Mammal : public Animal {
public:
    void walk() {
        cout << "Mammal walks" << endl;
    }
};

/* --------------------------------------------------
2. Multilevel Inheritance (Animal -> Mammal -> Dog)
-------------------------------------------------- */
class Dog : public Mammal {
public:
    void bark() {
        cout << "Dog barks" << endl;
    }
};

/* --------------------------------------------------
3. Multiple Inheritance (Student + Teacher -> TeachingAssistant)
-------------------------------------------------- */
class Student {
public:
    void study() {
        cout << "Student studies" << endl;
    }
};

class Teacher {
public:
    void teach() {
        cout << "Teacher teaches" << endl;
    }
};

class TeachingAssistant : public Student, public Teacher {
public:
    void assist() {
        cout << "Teaching Assistant helps both students and teachers" << endl;
    }
};

/* --------------------------------------------------
4. Hierarchical Inheritance (Color -> Red, Yellow, Green)
-------------------------------------------------- */
class Color {
public:
    void fill() {
        cout << "Generic Color filled" << endl;
    }
};

class Red : public Color {
public:
    void display() {
        cout << "Red color" << endl;
    }
};

class Yellow : public Color {
public:
    void display() {
        cout << "Yellow color" << endl;
    }
};

class Green : public Color {
public:
    void display() {
        cout << "Green color" << endl;
    }
};

/* --------------------------------------------------
5. Hybrid Inheritance (fixed with Virtual Inheritance)
Animal -> Mammal & Bird -> Bat
-------------------------------------------------- */
class Bird : virtual public Animal {
public:
    void fly() {
        cout << "Bird flies" << endl;
    }
};

// Redefine Mammal with virtual to avoid ambiguity
class MammalVirtual : virtual public Animal {
public:
    void walk() {
        cout << "Mammal walks (virtual)" << endl;
    }
};

class Bat : public MammalVirtual, public Bird {
public:
    void identity() {
        cout << "Bat is both Mammal and Bird (Hybrid)" << endl;
    }
};

/* --------------------------------------------------
Main Function
-------------------------------------------------- */
int main() {
    cout << "--- Single Inheritance ---" << endl;
    Mammal m;
    m.eat();
    m.walk();

    cout << "\n--- Multilevel Inheritance ---" << endl;
    Dog d;
    d.eat();
    d.walk();
    d.bark();

    cout << "\n--- Multiple Inheritance ---" << endl;
    TeachingAssistant ta;
    ta.study();
    ta.teach();
    ta.assist();

    cout << "\n--- Hierarchical Inheritance ---" << endl;
    Red r; Yellow y; Green g;
    r.fill(); r.display();
    y.fill(); y.display();
    g.fill(); g.display();

    cout << "\n--- Hybrid Inheritance (Virtual Fix) ---" << endl;
    Bat b;
    b.eat();     // no ambiguity (one Animal copy)
    b.walk();
    b.fly();
    b.identity();

    return 0;
}