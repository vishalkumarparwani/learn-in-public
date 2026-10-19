#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;

public:
    Person(string n) : name(n) {}

    virtual void info() const {
        cout << "Person's name: " << name << endl;
    }

    virtual ~Person() = default;
};

class Student : public Person {
private:
    int semester;

public:
    Student(string n, int s) : Person(n), semester(s) {}

    void info() const override {
        cout << "Student's name: " << name << endl;
        cout << "Current semester: " << semester << endl;
    }
};

int main() {
    Person p1("Alice");
    Student s1("Alex", 5);

    p1.info();
    cout << endl;
    s1.info();

    cout << "\nUsing a base class pointer:\n";
    Person* person = &s1;
    person->info();

    return 0;
}