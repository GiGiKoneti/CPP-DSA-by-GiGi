/*
Practice Q:

Create a User class with properties:
- id (private)
- username (public)
- password (private)

Requirements:
1. id should be initialized in a parameterized constructor.
2. Provide a setter and getter for password.
*/

#include <iostream>
#include <string>
using namespace std;

class User {
private:
    int id;           // Private: cannot be accessed directly outside class
    string password;  // Private: hidden for security

public:
    string username;  // Public: accessible directly

    // Parameterized constructor to initialize id
    User(int id) {
        this->id = id;  // 'this' pointer used to refer to object's id
    }

    // Setter for password
    void setPassword(string password) {
        this->password = password;
    }

    // Getter for password
    string getPassword() {
        return password;
    }
};

int main() {
    // Creating object and initializing id via constructor
    User user1(101);

    // Public member can be accessed directly
    user1.username = "GiGi Molki";

    // Use setter to assign private password
    user1.setPassword("Molki@123");

    // Access public and private (via getter) values
    cout << "Username: " << user1.username << endl;
    cout << "Password: " << user1.getPassword() << endl;

    return 0;
}

/*
Key Concepts:
1. Private members (id, password) are hidden and secure.
2. Public member (username) can be accessed directly.
3. Parameterized constructor initializes id when object is created.
4. Setters and getters provide controlled access to private data.
5. 'this' pointer refers to the current object's members.
*/