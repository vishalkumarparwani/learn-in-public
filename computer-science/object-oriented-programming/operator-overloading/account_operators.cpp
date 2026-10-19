#include <iostream>
#include <string>
using namespace std;

class Account {
    string accountNumber;
    string accountHolder;
    double balance;
public:
    Account(string an = "", string ah = "", double bal = 0.0) {
        accountNumber = an;
        accountHolder = ah;
        balance = bal;
    }
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }
    double getBalance() const {
        return balance;
    }
    Account operator + (const Account &other) {
        Account temp;
        temp.balance = balance + other.balance;
        return temp;
    }
    Account &operator -= (double amount) {
        if(amount > 0 && balance >= amount) {
            balance -= amount;
        }
        return *this;
    }
    bool operator > (const Account &other) {
        return balance > other.balance;
    }
    friend ostream &operator << (ostream &os, const Account &other) {
        os << "Account Number: " << other.accountNumber
           << "\nAccount Holder: " << other.accountHolder
           << "\nAccount Balance: " << other.balance;

        return os;
    }
};
int main() {
    Account acc1("101", "Ali", 5000);
    Account acc2("102", "Ahmed", 3000);

    Account total = acc1 + acc2; 
    cout << "Total Balance (After Addition): " << total.getBalance() << endl;

    cout << "\nAfter Transfer:" << endl;
    acc1 -= 2000.0;  
    acc2.deposit(2000.0);
    
    cout << "Ali New Balance: " << acc1.getBalance() << endl;
    cout << "Ahmed New Balance: " << acc2.getBalance() << endl;

    cout << "\nComparison:" << endl;
    if (acc1 > acc2) {
        cout << "Ali has more balance than Ahmed." << endl;
    } else {
        cout << "Ali has less balance than Ahmed." << endl;
    }

    cout << "\nFinal Account Details:" << endl;
    cout << acc1 << endl;
    cout << acc2 << endl;

    return 0;
}