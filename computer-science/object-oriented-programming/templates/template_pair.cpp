#include <iostream>
#include <string>

using namespace std;

template <typename T1, typename T2>
class Pair
{
    T1 a;
    T2 b;

public:
    Pair(T1 x, T2 y) : a(x), b(y) {}
    void display()
    {
        cout << "Pair: (" << a << ", " << b << ")";
    }
};

int main()
{
    Pair<int, const char *> data1(5, "Hello");
    data1.display();

    cout << endl;

    Pair<double, int> data2(3.14, 42);
    data2.display();

    return 0;
}