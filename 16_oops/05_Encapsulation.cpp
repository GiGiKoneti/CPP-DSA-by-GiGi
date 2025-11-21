#include <iostream>
using namespace std;

/*
👉 Encapsulation Definition:
Encapsulation is the process of binding data (variables) and methods 
(functions) that operate on that data into a single unit (class), 
while restricting direct access to some of the class’s components.
It ensures data security and controlled access using access modifiers.
*/

class BankAccount {
private:
    // Private data -> hidden from outside world
    string accountHolder;
    double balance;

public:
    // Public methods -> provide controlled access
    void setAccountHolder(string name) {
        accountHolder = name;
    }

    void deposit(double amount) {
        if (amount > 0)
            balance += amount;
    }

    double getBalance() {
        return balance;
    }
};

int main() {
    BankAccount acc;

    // Accessing data via methods (not directly)
    acc.setAccountHolder("GiGi");
    acc.deposit(5000);

    cout << "Balance: " << acc.getBalance() << endl;

    return 0;
}

/*
👉 Explanation:
- Data (accountHolder, balance) is private -> cannot be accessed directly.
- Public methods (setAccountHolder, deposit, getBalance) provide controlled access.
- This "hiding data + controlled access" is called **Encapsulation**.
*/