#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    string name;
    int age;
    string joiningDate;
    double salary;

public:
    Employee(string n, int a, string date, double s)
        : name(n), age(a), joiningDate(date), salary(s) {}

    void displayEmployee() const {
        cout << "Name: " << name
             << "\nAge: " << age
             << "\nJoining Date: " << joiningDate
             << "\nSalary: " << salary << endl;
    }

    virtual void work() const {
        cout << name << " is working as an employee." << endl;
    }

    virtual ~Employee() = default;
};

class Developer : virtual public Employee {
protected:
    string language;

public:
    Developer(string n, int a, string date, double s, string lang)
        : Employee(n, a, date, s), language(lang) {}

    void writeCode() const {
        cout << name << " develops software using "
             << language << "." << endl;
    }

    void work() const override {
        writeCode();
    }
};

class Debugger : virtual public Employee {
protected:
    int bugsFixed;

public:
    Debugger(string n, int a, string date, double s, int bugs)
        : Employee(n, a, date, s), bugsFixed(bugs) {}

    void fixBugs() const {
        cout << name << " has fixed " << bugsFixed
             << " bugs." << endl;
    }

    void work() const override {
        fixBugs();
    }
};

class TeamLead : public Developer, public Debugger {
public:
    TeamLead(string n, int a, string date, double s,
             string lang, int bugs)
        : Employee(n, a, date, s),
          Developer(n, a, date, s, lang),
          Debugger(n, a, date, s, bugs) {}

    void displayAllData() const {
        displayEmployee();
        writeCode();
        fixBugs();
    }

    void work() const override {
        cout << name << " manages the team and reviews code."
             << endl;
    }
};

int main() {
    TeamLead t1("Alice", 27, "10-05-2018", 120000,
                "C++", 45);

    t1.displayAllData();

    Employee* employee = &t1;
    employee->work();

    return 0;
}