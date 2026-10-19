#include <iostream>
#include <string>

using namespace std;

class Vehicle {
protected:
    double speed;
    double capacity;
    string fuelType;
public:
    Vehicle(double s, double c, string f) : speed(s), capacity(c), fuelType(f) {}

    virtual void start() { cout << "Vehicle starting engine..." << endl; }
    virtual void stop() { cout << "Vehicle stopping engine..." << endl; }
    virtual void calculateEnergyConsumption() { cout << "Calculating vehicle energy usage..." << endl;}

    ~Vehicle() {}
};

class Car : public Vehicle {
public:
    Car(double s, double c, string f) : Vehicle(s, c, f) {}
    void calculateEnergyConsumption() {
        double liters = speed * 0.08;
        cout << "Car: Consumed " << liters << " Liters | Calculated from speed " << speed << endl;
    }
};

class Bus : public Vehicle {
public:
    Bus(double s, double c, string f) : Vehicle(s, c, f) {}
    void calculateEnergyConsumption() {
        double liters = (speed * 0.2) + (capacity * 0.1);
        cout << "Bus: Consumed " << liters << " Liters | Calculated from speed & capacity" << endl;
    }
};

class ElectricBike : public Vehicle {
public:
    ElectricBike(double s, double c, string f) : Vehicle(s, c, f) {}
    void calculateEnergyConsumption() {
        double kwh = speed * 0.05;
        cout << "E-Bike: Consumed " << kwh << " kWh | Calculated from speed: " << speed << endl;
    }
};

int main() {
    Vehicle* fleet[3];

    fleet[0] = new Car(100, 4, "Petrol");
    fleet[1] = new Bus(100, 4, "Petrol");
    fleet[2] = new ElectricBike(100, 4, "Petrol");

    for(int i = 0; i < 3; ++i) {
        fleet[i]->start();
        fleet[i]->calculateEnergyConsumption();
        fleet[i]->stop();
    }
    for(int i = 0; i < 3; ++i) {
        delete fleet[i];
    }
    return 0;
}