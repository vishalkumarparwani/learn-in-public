#include <iostream>
#include <string>

using namespace std;

template<typename T>
class SmartArray {
    T* arr;
    int size;
public:
    SmartArray(int s) {
        size = s;
        arr = new T[size];
    }

    ~SmartArray() {
        delete[] arr;
    }
    void input() {
        for(int i = 0; i < size; ++i) {
            cin >> arr[i];
        }
    }
    T& operator [](int index) {
        if(index < 0 || index >= size) {
            throw "OutOfBoundsException";
        }
        return arr[index];
    }
};

int main() {
    int n;

    cout << "Enter size: ";
    cin >> n;

    if(n <= 0) {
        cout << "Invalid array size. Must be positive.\n";
    }

    SmartArray<int> intArray(n);
    cout << "Enter Array Elements:\n";
    intArray.input();

    cout << "Accessing index 2: ";
    try {
        cout << intArray[2] << endl;
    }
    catch(const char* msg) {
        cout << msg << " caught: Invalid index access attempted!\n";
    }
    cout << "Accessing index 5: ";
    try {
        cout << intArray[5] << endl;
    }
    catch(const char* msg) {
        cout << msg << " caught: Invalid index access attempted!\n";
    }
    cout << "\n----------------------------------------------\n\n";

    SmartArray<string> strArray(n);
    cout << "Enter string elements: ";
    strArray.input();
    
    cout << "Accessing index 2: ";
    try {
        cout << strArray[2] << endl;
    }
    catch(const char* msg) {
        cout << msg << " caught: Invalid index access attempted!\n";
    }
    cout << "Accessing index 5: ";
    try {
        cout << strArray[5] << endl;
    }
    catch(const char* msg) {
        cout << msg << " caught: Invalid index access attempted!\n";
    }

    return 0;
}