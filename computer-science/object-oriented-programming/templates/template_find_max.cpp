#include <iostream>
#include <string>

using namespace std;

template<typename T>
T findMax(T arr[], int size) {
    T max = arr[0];
    for(int i = 1; i < size; ++i) {
            if(arr[i] > max){
                max = arr[i];
            }
        } 
    return max;
}
int main() {
    int intArray[] = {10, 20, 5, 30, 25};
    int size = sizeof(intArray) / sizeof(intArray[0]);
    cout << "Maximum Number: " << findMax(intArray, size);

    cout << "\n------------------------------------------\n";

    string strArray[] = {"Apple", "Mango", "Banana", "Peach"};
    size = sizeof(strArray) / sizeof(strArray[0]);
    cout << "Maximum String: " << findMax(strArray, size);

    return 0;
}