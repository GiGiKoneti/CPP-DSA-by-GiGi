/*
  This file contains solutions and explanations for a series of multiple-choice questions on Object-Oriented Programming (OOP) in C++.

 

 Question 1:
 1. Which of the following is not a feature of OOP in C++?
 a) Encapsulation
 b) Inheritance
 c) Polymorphism
 d) Compilation
 Explanation: Encapsulation, inheritance, and polymorphism are the core pillars of OOP[cite: 3, 4, 5]. Compilation is a step in the software development process, not a feature of OOP itself[cite: 6].
 Correct Answer: d) Compilation 
 ---------------------------------------------------------------------------------------------------------------------

 Question 2:
 2. What is encapsulation?
 a) Bundling data and methods that operate on the data into a single unit
 b) The ability to create a new class from an existing class
 c) The ability to redefine methods in derived classes
 d) None of the above
 Explanation: Encapsulation is the practice of combining data and the methods that operate on that data into a single unit, which is often a class[cite: 8]. It helps in data hiding and security.
 Correct Answer: a) Bundling data and methods that operate on the data into a single unit 
 ---------------------------------------------------------------------------------------------------------------------

 Question 3:
 3. Which of the following access specifiers is not available in C++?
 a) Public
 b) Private
 c) Protected
 d) Friendly
 Explanation: C++ has three main access specifiers: public, private, and protected[cite: 13, 14, 15]. 'Friendly' is not a standard access specifier in C++[cite: 16]. [cite_start]The concept of a 'friend' function or class is related but is not an access specifier itself[cite: 95, 96, 97].
 Correct Answer: d) Friendly 
 ---------------------------------------------------------------------------------------------------------------------

 Question 4:
 4. Which keyword is used to define a base class in C++?
 a) base
 b) super
 c) class
 d) parent
 Explanation: The `class` keyword is used to define both base and derived classes in C++[cite: 20]. The keyword `super` is used in other languages like Java to refer to the parent class.
 Correct Answer: c) class [cite: 229]
 ---------------------------------------------------------------------------------------------------------------------

 Question 5:
 5. Which type of inheritance is not supported directly by C++?
 a) Single inheritance
 b) Multiple inheritance
 c) Multilevel inheritance
 d) Hybrid inheritance
 Explanation: While C++ supports single, multiple, and multilevel inheritance, hybrid inheritance is a combination of two or more types of inheritance. It is not a distinct type directly supported but is rather a design pattern implemented by combining other types[cite: 25, 26, 27].
 Correct Answer: d) Hybrid inheritance 
 ---------------------------------------------------------------------------------------------------------------------

 Question 6:
 6. What is polymorphism in C++?
 a) The ability of a function or operator to behave in different ways
 b) The process of hiding data
 c) The ability to create a new class from an existing class
 d) None of the above
 Explanation: Polymorphism, meaning "many forms," allows a single interface to be used for a general class of actions. In C++, this is achieved through function overloading, operator overloading, and function overriding[cite: 30].
 Correct Answer: a) The ability of a function or operator to behave in different ways [cite: 231]
 ---------------------------------------------------------------------------------------------------------------------

 Question 7:
 7. What is a virtual function in C++?
 a) A function defined in a base class that can be overridden in a derived class
 b) A function that exists in memory but is not used
 c) A function that is called during object creation
 d) None of the above
 Explanation: A virtual function is a member function in a base class that you expect to be overridden in derived classes[cite: 35]. The concept is fundamental to achieving runtime polymorphism[cite: 90, 92].
 Correct Answer: a) A function defined in a base class that can be overridden in a derived class [cite: 232]
 ---------------------------------------------------------------------------------------------------------------------

 Question 8:
 8. What is the output of the following code?
 class Base {
 public:
 void show() { cout << "Base" << endl; }
 class Derived : public Base {
 public:
 void show() { cout << "Derived" << endl; }
 int main() {
 Base* b;
 Derived d;
 b = &d;
 b->show();
 return 0;
 }
 a) Base
 b) Derived
 c) Compilation error
 d) Runtime error
 Explanation: In this code, the `show()` function in the `Base` class is not declared as `virtual`[cite: 42]. Therefore, when `b->show()` is called, the function is resolved at compile-time based on the **pointer's** type (`Base*`), not the object's type (`Derived`). This is an example of static or compile-time polymorphism. The output will be "Base"[cite: 49, 50, 51, 52].
 Correct Answer: a) Base [cite: 233]
 ---------------------------------------------------------------------------------------------------------------------

 Question 9:
 9. What is the purpose of a constructor in C++?
 a) To deallocate memory
 b) To initialize objects
 c) To create a new class
 d) None of the above
 Explanation: A constructor is a special member function that is automatically called when an object of a class is created. Its primary purpose is to initialize the data members of the new object[cite: 62].
 Correct Answer: b) To initialize objects [cite: 234]
 ---------------------------------------------------------------------------------------------------------------------

 Question 10:
 10. Which of the following statements about destructors is true?
 a) A class can have multiple destructors
 b) Destructors are called manually by the programmer
 c) Destructors are used to release resources
 d) Destructors can be overloaded
 Explanation: A class can have only one destructor[cite: 66]. Destructors are called automatically when an object goes out of scope or is explicitly deleted[cite: 67]. Their main purpose is to clean up resources, such as freeing dynamically allocated memory, before the object is destroyed[cite: 68]. They cannot be overloaded[cite: 69].
 Correct Answer: c) Destructors are used to release resources [cite: 235]
 ---------------------------------------------------------------------------------------------------------------------

 Question 11:
 11. What is the output of the following code?
 class A {
 public:
 A() { cout << "A"; }
 ~A() { cout << "~A"; }
 };
 int main() {
 A obj;
 return 0;
 }
 a) A
 b) ~A
 c) A~A
 d) Compilation error
 Explanation: When `A obj;` is executed, the constructor `A()` is called, printing "A"[cite: 74, 77]. When the program exits, the destructor `~A()` is called for the `obj` object, printing "~A"[cite: 75, 78]. The combined output is "A~A"[cite: 236].
 Correct Answer: c) A~A [cite: 236]
 ---------------------------------------------------------------------------------------------------------------------

 Question 12:
 12. Which of the following is not a type of constructor in C++?
 a) Default constructor
 b) Parameterized constructor
 c) Copy constructor
 d) Virtual constructor
 Explanation: C++ supports default, parameterized, and copy constructors[cite: 86, 87, 88]. There is no concept of a "virtual constructor"[cite: 89].
 Correct Answer: d) Virtual constructor [cite: 237]
 ---------------------------------------------------------------------------------------------------------------------

 Question 13:
 13. How is dynamic polymorphism achieved in C++?
 a) Using overloaded functions
 b) Using function overriding
 c) Using function templates
 d) Using default arguments
 Explanation: Dynamic polymorphism, also known as runtime polymorphism, is primarily achieved in C++ through function overriding with the use of virtual functions[cite: 92].
 Correct Answer: b) Using function overriding [cite: 238]
 ---------------------------------------------------------------------------------------------------------------------

 Question 14:
 14. Which of the following can be declared as a friend in C++?
 a) Function
 b) Class
 c) Another object
 d) Both a and b
 Explanation: In C++, both a function and another class can be declared as a `friend` to a class[cite: 96, 97]. A friend function or class can access the private and protected members of the class that declared it as a friend.
 Correct Answer: d) Both a and b [cite: 239]
 ---------------------------------------------------------------------------------------------------------------------

 Question 15:
 15. What is the output of the following code?
 Class Base {
 public:
 virtual void print() { cout << "Base"; }
 };
 class Derived : public Base {
 public:
 void print() { cout << "Derived"; }
 };
 int main() {
 Base* b = new Derived();
 b->print();
 delete b;
 return 0;
 }
 a) Base
 b) Derived
 c) Compilation error
 d) Runtime error
 Explanation: In this example, `print()` is a `virtual` function in the `Base` class[cite: 103]. This enables dynamic polymorphism. The pointer `b` of type `Base*` points to an object of type `Derived`[cite: 108]. When `b->print()` is called, the function call is resolved at runtime based on the actual object type (`Derived`), not the pointer type. The output will be "Derived"[cite: 109].
 Correct Answer: b) Derived [cite: 240]
 ---------------------------------------------------------------------------------------------------------------------

 Question 16:
 16. Which of the following is true about pure virtual functions?
 a) They have no implementation in the base class
 b) They must be implemented in the derived class
 c) They are declared using the syntax = 0
 d) All of the above
 Explanation: A pure virtual function is a virtual function that is declared in a base class with no implementation[cite: 118]. It is declared using `= 0` at the end of its declaration[cite: 120]. Any concrete derived class must provide an implementation for it[cite: 119].
 Correct Answer: d) All of the above [cite: 241]
 ---------------------------------------------------------------------------------------------------------------------

 Question 17:
 17. What is an abstract class in C++?
 a) A class that cannot be instantiated
 b) A class with at least one pure virtual function
 c) A class with all its functions pure virtual
 d) Both a and b
 Explanation: An abstract class is a class that contains at least one pure virtual function[cite: 127]. Because it has a pure virtual function, it cannot be instantiated directly[cite: 126]. You can only create objects of its concrete derived classes.
 Correct Answer: d) Both a and b [cite: 242]
 ---------------------------------------------------------------------------------------------------------------------

 Question 18:
 18. What is the use of the this pointer in C++?
 a) To access the static members of the class
 b) To differentiate between local and global variables
 c) To access the object's members within the class methods
 d) None of the above
 Explanation: The `this` pointer is a constant pointer that holds the memory address of the current object. It's automatically passed as a hidden argument to non-static member functions and is used to access the members of the object on which the function is called[cite: 133].
 Correct Answer: c) To access the object's members within the class methods [cite: 243]
 ---------------------------------------------------------------------------------------------------------------------

 Question 19:
 19. What is the default access specifier for members of a class in C++?
 a) Public
 b) Private
 c) Protected
 d) None
 Explanation: By default, if no access specifier is specified for the members of a class, they are `private`[cite: 137].
 Correct Answer: b) Private [cite: 243]
 ---------------------------------------------------------------------------------------------------------------------

 Question 20:
 20. Which of the following is correct about operator overloading in C++?
 a) It allows defining new operators
 b) It allows using operators with user-defined data types
 c) It changes the syntax of the language
 d) None of the above
 Explanation: Operator overloading allows you to redefine the way an operator works for user-defined data types, like classes[cite: 142]. It does not allow you to create new operators or change the fundamental syntax of C++[cite: 141, 143].
 Correct Answer: b) It allows using operators with user-defined data types [cite: 244]
 ---------------------------------------------------------------------------------------------------------------------

 Question 21:
 21. What is the correct way to define a copy constructor?
 class A {
 public:
 ...
 };
 a) A(const A obj) { ... }
 b) A(A& obj) { ... }
 c) A(A obj) { ... }
 d) A(const A &obj) { ... }
 Explanation: The correct signature for a copy constructor is `ClassName(const ClassName &obj)`. Using a `const` reference prevents the constructor from modifying the original object and avoids an infinite recursion of copy constructors[cite: 148, 154].
 Correct Answer: d) A(const A &obj) { /.../ } [cite: 245]
 ---------------------------------------------------------------------------------------------------------------------

 Question 22:
 22. Which of the following is a correct way to declare an array of objects in C++?
 a) ClassName obj[5];
 b) ClassName obj = new ClassName[5];
 c) ClassName obj{5};
 d) ClassName obj{};
 Explanation: The most common and correct way to declare a static array of objects is `ClassName obj[size];`[cite: 156]. Option 'b' uses dynamic memory allocation, and while correct for creating an array of objects on the heap, 'a' is a more direct and fundamental declaration. The other options are incorrect syntax for an array.
 Correct Answer: a) ClassName obj[5]; [cite: 246]
 ---------------------------------------------------------------------------------------------------------------------

 Question 23:
 23. Which of the following is true about inheritance in C++?
 a) Derived class inherits private members of the base class
 b) Derived class can access protected members of the base class
 c) Derived class cannot override base class methods
 d) None of the above
 Explanation: A derived class does inherit the private members of the base class, but it cannot access them directly[cite: 161]. However, it can access `protected` members of the base class[cite: 162]. Derived classes can indeed override base class methods, especially with virtual functions[cite: 163].
 Correct Answer: b) Derived class can access protected members of the base class [cite: 247]
 ---------------------------------------------------------------------------------------------------------------------

 Question 24:
 24. What does the protected access specifier mean?
 a) Members are accessible only within the same class
 b) Members are accessible within the same class and derived classes
 c) Members are accessible within the same class and friend classes
 d) Members are accessible from anywhere in the program
 Explanation: A `protected` member of a class is accessible to member functions of that class, as well as to member functions of any classes derived from it[cite: 167].
 Correct Answer: b) Members are accessible within the same class and derived classes [cite: 248]
 ---------------------------------------------------------------------------------------------------------------------

 Question 25:
 25. What is a virtual destructor in C++?
 a) A destructor that does nothing
 b) A destructor that can be called manually
 c) A destructor that ensures derived class destructors are called
 d) A destructor that can be overridden
 Explanation: Declaring a destructor as `virtual` in the base class is crucial when dealing with a class hierarchy[cite: 170]. It ensures that when an object of a derived class is deleted through a base class pointer, the correct destructor (the one from the derived class) is called first, followed by the base class destructor[cite: 173]. This prevents memory leaks.
 Correct Answer: c) A destructor that ensures derived class destructors are called [cite: 249]
 ---------------------------------------------------------------------------------------------------------------------

 Question 26:
 26. What is the output of the following code?
 class Base {
 public:
 Base() { cout << "Base"; }
 };
 class Derived : public Base {
 public:
 Derived() { cout << "Derived"; }
 };
 int main() {
 Derived obj;
 return 0;
 }
 a) Base
 b) Derived
 c) BaseDerived
 d) DerivedBase
 Explanation: When an object of a derived class is created, the base class constructor is executed first, followed by the derived class constructor[cite: 193]. Therefore, `Base()` prints "Base" and then `Derived()` prints "Derived". The output is "BaseDerived"[cite: 178, 181, 183].
 Correct Answer: c) BaseDerived [cite: 250]
 ---------------------------------------------------------------------------------------------------------------------

 Question 27:
 27. Which of the following is true about constructors and inheritance?
 a) Base class constructor is called after derived class constructor
 b) Derived class constructor is called after base class constructor
 c) Constructors are not called in inheritance
 d) Constructors are called in any order
 Explanation: When an object of a derived class is instantiated, the compiler ensures that the base class's constructor is called first to properly initialize the base class portion of the object. Only after that, the derived class's constructor is called[cite: 193].
 Correct Answer: b) Derived class constructor is called after base class constructor [cite: 251]
 ---------------------------------------------------------------------------------------------------------------------

 Question 28:
 28. How is operator overloading done in C++?
 a) Using the operator keyword
 b) Using function overloading
 c) Using the overload keyword
 d) Using inheritance
 Explanation: Operator overloading in C++ is achieved by defining a function with the keyword `operator` followed by the operator symbol you want to overload[cite: 197].
 Correct Answer: a) Using the operator keyword [cite: 252]
 ---------------------------------------------------------------------------------------------------------------------

 Question 29:
 29. What does the delete operator do in C++?
 a) Deletes an object from memory
 b) Deletes a class
 c) Deletes a function
 d) Deletes an attribute
 Explanation: The `delete` operator is used to deallocate memory that was previously allocated with the `new` operator[cite: 202]. It deletes a dynamically created object and calls its destructor.
 Correct Answer: a) Deletes an object from memory [cite: 253]
 ---------------------------------------------------------------------------------------------------------------------

 Question 30:
 30. What is the output of the following code?
 class A {
 public:
 virtual void show() { cout << "A"; }
 };
 class B : public A {
 public:
 void show() { cout << "B"; }
 };
 int main() {
 A* a = new B();
 a->show();
 return 0;
 }
 a) A
 b) B
 c) AB
 d) Compilation error
 Explanation: Similar to question 15, the `show()` function is `virtual` in the base class `A`[cite: 209]. This allows for dynamic dispatch. A pointer of type `A*` is pointing to an object of type `B`[cite: 214]. When `a->show()` is called, the correct function is determined at runtime, and the `show()` function from the `Derived` class `B` is executed[cite: 215]. [cite_start]The output is "B"[cite: 220].
 Correct Answer: b) B [cite: 254]
 ---------------------------------------------------------------------------------------------------------------------
 */