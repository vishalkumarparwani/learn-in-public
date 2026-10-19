#include <iostream>
#include <string>
using namespace std;

int main()
{
    int numberOfUnits;
    const double constValue = 15.0;
    double totalBill;

    while (true)
    {
        cout << "Enter Number Of Units: ";
        cin >> numberOfUnits;

        try
        {
            if(!cin) {
                cin.clear();
                string garbage;
                cin>>garbage;
                throw "Invalid Input";
            }
            if (numberOfUnits < 0)
                throw "Invalid Number Of Units";
            if ((numberOfUnits * constValue) > 100000)
            {
                throw "Invalid Total Bill";
            }
            break;
        }
        catch (const char *msg)
        {
            cout << "EXCEPTION: " << msg << endl;
        }
    }
    totalBill = numberOfUnits * constValue;

    cout << "\nUnits Consumed : " << numberOfUnits;
    cout << "\nCost per Unit: " << constValue;
    cout << "\nTotal Bill: " << totalBill << endl;

    return 0;
}