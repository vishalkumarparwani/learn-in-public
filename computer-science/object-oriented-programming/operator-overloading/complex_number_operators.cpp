#include<iostream>
using namespace std;

class complex {
    int real, img;
public:
    complex(int r = 0, int i = 0) {
        real = r;
        img = i;
    }
    void display() {
        cout << "Real: " << real << endl << "Image: " << img << endl;
    }

    complex operator + (complex c) {
        complex temp;
        temp.real = real + c.real;
        temp.img = img + c.img;
        return temp;
    }

    void operator ++ (int) {
        real++;
        img++;
    }
    void operator ++ () {
        real++;
        img++;
    }
};

int main() {
    complex c1;
    complex c2(5, 2);
    complex c3(3, 4);

    // c1++;
    // ++c1;
    // c1 = 1+1;
    c1 = c2+c3;
    c1.display();

    return 0;
}