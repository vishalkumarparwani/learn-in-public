#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string name, message;

    cout << "Enter recipient's name: ";
    getline(cin, name);

    cout << "Enter your short message: ";
    getline(cin, message);

    ofstream file("greeting.txt");

    file << "Dear " << name << "\n";
    file << message << "\n";
    file << "Best Regards!";

    file.close();

    return 0;
}