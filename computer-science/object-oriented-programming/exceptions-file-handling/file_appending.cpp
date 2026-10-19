#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ofstream file("backup_log.txt", ios::app);
    if(!file) {
        cout << "Error opening file!\n";
        return 1;
    }
    string msg;

    while(true) {
        cout << "Enter log message: ";
        getline(cin, msg);
    
        if(msg == "exit") { break; }

        file << msg << endl;

        long currentSize = file.tellp();

        cout << "Log saved. Current file size: " << currentSize << " bytes\n";
    }
    file.close();
    return 0;
}