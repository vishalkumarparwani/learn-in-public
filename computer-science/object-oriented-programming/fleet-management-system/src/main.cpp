#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

class Driver;
class Passenger;
class Ride;
class FleetManager;


template <typename T, int maxSize>
class FixedPointerList {
private:
    T item[maxSize];
    int count; 
public:    
    FixedPointerList() : count(0) {}

    void add(T newItem) {
        if(count >= maxSize) { throw "Error: List is full! Cannot add more items."; }
        item[count++] = newItem;
    }

    int getSize() const { return count; }
    
    T operator [](int index) {
        if(index < 0 || index >= count) { throw "Error: Index out of bounds"; }

        return item[index];
    }
};

//====================
class Vehicle {
//====================
private:
    string vehicle_id, vehicle_type, vehicle_model, next_service_date, status;
    double mileage, fuel_level;
    static int nextID;

    friend void forceMaintenanceReset(Vehicle* v);

public:
    Vehicle(const string& type = "Car", const string& model = "", const string& date = "None", const string& stat = "Available", double m = 0.0, double f = 100.0) 
            : vehicle_id("V" + to_string(nextID++)), vehicle_type(type), vehicle_model(model), next_service_date(date), status(stat), mileage(m), fuel_level(f) {}
    
    virtual ~Vehicle() {}

    virtual double calculateFare(double dist) const = 0;

    string getID() const { return vehicle_id; }
    string getType() const { return vehicle_type; }
    string getModel() const { return vehicle_model; }
    string getStatus() const { return status; }
    string getNextServiceDate() const { return next_service_date; }
    double getMileage() const { return mileage; }
    double getFuelLevel() const { return fuel_level; }

    void addMileage(double km) { mileage += km; } 
    void reFuel(double amount) { fuel_level += amount; }
    void setNextService(const string& date) { next_service_date = date; }
    void setStatus(const string& stat) { status = stat; }
    
    void consumeFuel(double amount) {
        if(fuel_level >= amount) {
            fuel_level -= amount;
        } else {
            fuel_level = 0.0;
            cout << "Warning: Vehicle " << vehicle_id << " ran out of fuel!\n";
        }
    }
    
    friend ostream& operator<<(ostream& os, const Vehicle& v) {
        os << "VehicleID: " << v.vehicle_id << ", Type: " << v.vehicle_type << ", Model: " << v.vehicle_model
           << ", Status: " << v.status << ", Mileage: " << v.mileage << " KM, Fuel: " << v.fuel_level << " L"
           << ", Next Service: " << v.next_service_date;
        return os;
    }
};
int Vehicle :: nextID = 100;

void forceMaintenanceReset(Vehicle* v) {
    if(v == nullptr) { return; }
    cout << "\n!!! FRIEND FUNCTION ACTIVATED: Forcing Maintenance Reset on " << v->getID() << " !!!\n";

    v->mileage = 0.0;
    v->fuel_level = 100.0;
    v->status = "Available";
    v->next_service_date = "N/A (Reset)";
    cout << "Vehicle " << v->getID() << " wiped clean. Mileage reset to 0\n";
}


class Bike : public Vehicle {
public:
    Bike(const string& model, double m = 0.0, double f = 50.0) : Vehicle("Bike", model, "None", "Available", m, f) {}
    
    double calculateFare(double dist) const { return dist * 10.0; }
};
class Car : public Vehicle {
public:
    Car(const string& model, double m = 0.0, double f = 100.0) : Vehicle("Car", model, "None", "Available", m, f) {}
    
    double calculateFare(double dist) const { return dist * 25.0; }
};
class Rickshaw : public Vehicle {
public:
    Rickshaw(const string& model, double m = 0.0, double f = 70.0) : Vehicle("Rickshaw", model, "None", "Available", m, f) {}
    
    double calculateFare(double dist) const { return dist * 20.0; }
};
class Premium : public Vehicle {
public:
    Premium(const string& model, double m = 0.0, double f = 120.0) : Vehicle("Premium", model, "None", "Available", m, f) {}
    
    double calculateFare(double dist) const { return dist * 40.0; }
};

//====================
class Driver {
//====================
private:
    string driver_id, driver_name, driver_license, online_status;
    int driver_age;
    double driver_rating, shift_hours;
    static int nextID;
    Vehicle *current_vehicle;
public:
    Driver(const string& name = "", int age = 18, string license = "", double rating = 0.0, Vehicle* v = nullptr) : driver_id("D" + to_string(nextID++)), 
            driver_name(name), driver_age(age), driver_license(license), driver_rating(rating), online_status("Offline"), shift_hours(0.0), current_vehicle(v) {

        if(age < 18 || age >= 65) {
            throw "Error: Driver age must be between 18 and 65";
        }
    }

    void setStatus(string s) { online_status = s; }

    string getID() const { return driver_id; }
    string getName() const { return driver_name; }
    string getStatus() const { return online_status; }
    double getRating() const { return driver_rating; }
    Vehicle* getCurrentVehicle() const { return current_vehicle; }

    void addRating(double newRating) { 
        if(newRating >= 1 && newRating <= 5) {
            if(driver_rating == 0) {
                driver_rating = newRating;
            }
            driver_rating = (driver_rating + newRating) / 2.0;
        }
        else {
            cout << "Invalid Rating for Driver " << driver_name << "!\n";
        }
    }

    void assignedVehicle(Vehicle* v) {
        current_vehicle = v;
        if (v) {
            cout << "Driver " << driver_name << " assigned vehicle " << v->getID() << endl;
        } else {
            cout << "Driver " << driver_name << " unassigned from vehicle" << endl;
        }
    }

    void login() {
        online_status = "Online";
        shift_hours = 0.0;
        cout << "Driver " << driver_name << " is now Online\n";
    }
    void logout() {
        online_status = "Offline";
        cout << "Driver " << driver_name << " is now Offline. Shift Hours: " << shift_hours << endl;
    }

    void startRide() {
        online_status = "OnRide";
        cout << "Driver " << driver_name << " started a ride\n";
    }
    void endRide(double shift_hours_during_ride) {
        online_status = "Online";
        shift_hours += shift_hours_during_ride;
        cout << "Driver " << driver_name << " completed a ride. Total shift hours: " << shift_hours << endl;

        if(shift_hours > 10.0) {
            cout << "FATIGUE ALERT: Driver " << driver_name << " has been driving for " << shift_hours << " hours. Consider a break!\n";
        }
    }

    friend ostream& operator<<(ostream& os, const Driver& d) {
        os << "Driver ID: " << d.driver_id << ", Name: " << d.driver_name << ", Age: " << d.driver_age
           << ", License: " << d.driver_license << ", Rating: " << d.driver_rating << ", Status: " << d.online_status
           << ", Shift Hours: " << d.shift_hours;
        if (d.current_vehicle) os << ", Vehicle: " << d.current_vehicle->getID();
        else os << ", No vehicle assigned";
        return os;
    }
};
int Driver :: nextID = 100;

//====================
class Passenger {
//====================
private:
    string passenger_id, passenger_name, phone_number;
    int passenger_age, trips_completed;
    static int nextID;
public:
    Passenger(const string& passengerName = "", string pNumber = "", int age = 18) 
            : passenger_id("P" + to_string(nextID++)), passenger_name(passengerName),
              phone_number(pNumber), passenger_age(age), trips_completed(0) {
        if(age < 12) {
            cout << "Passenger " << passenger_name << " too young to ride alone\n"; 
        } else if(age >= 12 && age < 17) {
            cout << "Minor Passenger " << passenger_name << ": Parental consent rquired\n";
        } else if(age > 65) {
            cout << "Notice: Passenger " << passenger_name << " over 65! Ensure extra care during the ride\n";
        }
    }

    string getID() { return passenger_id; }
    string getName() { return passenger_name; }
    int getTripsCompleted() { return trips_completed; }

    void addTrip() {
        trips_completed++;
    }

    friend ostream& operator<<(ostream& os, const Passenger& p) {
        os << "Passenger ID: " << p.passenger_id << ", Name: " << p.passenger_name << ", Age: " << p.passenger_age
           << ", Phone: " << p.phone_number << ", Trips Completed: " << p.trips_completed;
        return os;
    }
};
int Passenger :: nextID = 100;

//====================
class Ride {
//====================
private:
    string ride_id, status, ride_time, source_location, destination_location;
    double distance, fare;
    static int nextID;
    Vehicle *vehicle;
    Driver *driver;
    Passenger *passenger;
public:
    Ride(string src_loc = "Unknown", string dest_loc = "Unknown", double dist = 0.0, string time = "Now", Vehicle* v = nullptr, Driver* d = nullptr, Passenger* p = nullptr, string stat = "Booked") 
        : ride_id("R" + to_string(nextID++)), source_location(src_loc), destination_location(dest_loc), 
          distance(dist), status(stat), ride_time(time), vehicle(v), driver(d), passenger(p)
    {
        if(vehicle) { fare = vehicle->calculateFare(distance); }
    }

    string getID() { return ride_id; }
    string getStatus() { return status; }
    string getRideTime() { return ride_time; }
    string getSourceLocation() { return source_location; }
    string getDestinationLocation() { return destination_location; }
    double getDistance() { return distance; }
    double getFare() { return fare; }
    Vehicle* getVehicle() { return vehicle; }
    Driver* getDriver() { return driver; }
    Passenger* getPassenger() { return passenger; }

    void setStatus(string s) { status = s; }
    void setRideTime(string time) { ride_time = time; } 
    void setFare(double f) { fare = f; }
    void setVehicle(Vehicle* v) {
        vehicle = v;
        if(v) { fare = v->calculateFare(distance);
        }
        return;
    }
    void setDriver(Driver* d) { driver = d; }
    void setPassenger(Passenger* p) { passenger = p; }

    void startRide() {
        status = "InProgress";
        if(driver) { driver->startRide(); }
        if(vehicle) { vehicle->setStatus("OnRide"); }
        cout << "Ride " << ride_id << " from " << source_location << " to " << destination_location << " started\n";
    }

    void completed(double duration_hours = 0.5, double newRating = 4.5) {
        status = "Completed";
        if(driver) {
            driver->endRide(duration_hours);
            driver->addRating(newRating);
        }
        if(vehicle) {
            vehicle->setStatus("Available");
            vehicle->addMileage(distance);
            vehicle->consumeFuel(distance / 2.0);
        }
        if(passenger) {
            passenger->addTrip();
        }
        cout << "Ride " << ride_id << " completed. Fate: " << fare << endl;
    }

    friend ostream& operator<<(ostream& os, const Ride& r) {
        os << "Ride ID: " << r.ride_id << ", Status: " << r.status << ", Time: " << r.ride_time
           << ", From: " << r.source_location << ", To: " << r.destination_location
           << ", Distance: " << r.distance << " km, Fare: " << r.fare;
        if(r.vehicle) os << " | V: " << r.vehicle->getID();
        if(r.driver) os << " | D: " << r.driver->getName();
        return os;
    }
};
int Ride :: nextID = 100;

const int MAX_VEHICLES = 50;
const int MAX_DRIVERS = 50;
const int MAX_PASSENGERS = 50;
const int MAX_RIDES = 50;

//====================
class FleetManager {
//====================
private:
    
    FixedPointerList<Vehicle*, MAX_VEHICLES> vehicles;
    FixedPointerList<Driver*, MAX_DRIVERS> drivers;
    FixedPointerList<Passenger*, MAX_PASSENGERS> passengers;
    FixedPointerList<Ride*, MAX_RIDES> rides;

    double total_earnings;

    Passenger* findPassenger(string id) {
        for(int i = 0; i < passengers.getSize(); ++i) {
            if(passengers[i]->getID() == id) { return passengers[i]; }
        }
        return nullptr;
    }

public:
    FleetManager() : total_earnings(0) {}
    ~FleetManager() {
        cout << "\nCleening up the FleetManager memory...\n";
        for(int i = 0; i < vehicles.getSize(); ++i) { delete vehicles[i]; }
        for(int i = 0; i < drivers.getSize(); ++i) { delete drivers[i]; }
        for(int i = 0; i < passengers.getSize(); ++i) { delete passengers[i]; }
        for(int i = 0; i < rides.getSize(); ++i) { delete rides[i]; }
    }

    void addVehicle(Vehicle* v) {
        try {
            vehicles.add(v);
            cout << "Vehicle " << v->getID() << " added\n";
        }
        catch(const char* msg) {
            delete v;
            throw msg;
        }
    }

    void addDriver(Driver* d) {
        try {
            drivers.add(d);
            cout << "Driver " << d->getID() << " added\n";
        } catch(const char* msg) {
            delete d;
            throw msg;
        }
    }

    void addPassenger(Passenger* p) {
        try {
            passengers.add(p);
            cout << "Passenger " << p->getID() << " added\n";
        } catch(const char* msg) {
            delete p;
            throw msg;
        }
    }

    Driver* findDriver(string id) {
        for(int i = 0; i < drivers.getSize(); ++i) {
            if(drivers[i]->getID() == id) {
                return drivers[i];
            }
        }
        return nullptr;
    }

    Vehicle* findAvailableVehicle(string type) {
        for(int i = 0; i < vehicles.getSize(); ++i) {
            if(vehicles[i]->getType() == type && vehicles[i]->getStatus() == "Available") { return vehicles[i]; }
        }
        return nullptr;
    }

    void assignVehicleToDriver(string driverID, string vehicleType) {
        Driver* d = findDriver(driverID);
        Vehicle* v = findAvailableVehicle(vehicleType);

        if(v && d && d->getStatus() == "Online") {
            d->assignedVehicle(v);
            v->setStatus("Assigned");
            cout << "Assigned " << v->getID() << " to " << d->getName() << endl; 
        }
        else {
            throw "Assignment failed. Driver not online or no vehicle available";
        }
    }
    
    void createRide(string passengerID, string driverID, double distance, string source = "Unknown", string destination = "Unknown", string time = "Now") {

        Passenger* foundPassenger = findPassenger(passengerID);
        if (!foundPassenger) throw "Error: Passenger not found";

        Driver* foundDriver = findDriver(driverID);
        if (!foundDriver) throw "Error: Driver not found";

        Vehicle* assignedVehicle = foundDriver->getCurrentVehicle();
        if(!assignedVehicle) throw "Error: Driver is not assigned a vehicle";

        if (foundDriver->getStatus() != "Online") throw "Error: Driver is not online";

        Ride* newRide = new Ride(source, destination, distance, time, assignedVehicle, foundDriver, foundPassenger, "Booked");
        
        newRide->startRide();
        rides.add(newRide);

        assignedVehicle->setStatus("OnRide");
        foundDriver->setStatus("OnRide");

        cout << "Success: Ride " << newRide->getID() << " booked for " << foundPassenger->getName()
             << " with driver " << foundDriver->getName() << " in " << assignedVehicle->getType()
             << " from " << source << " to " << destination << endl;
    }

    void completeLatestRide(double hours, double rating) {
        if(rides.getSize() > 0) {
            Ride* r = rides[rides.getSize() - 1];
            if(r->getStatus() == "InProgress") {
                r->completed(hours, rating);                
                total_earnings += r->getFare();
                cout << "Total earnings updated to: $" << total_earnings << endl;
            }
            else {
                cout << "No in-progress rides found to complete. Latest ride status " << r->getStatus() << endl;
            }
        }
        else {
            cout << "No rides in the system to complete\n";
        }
    }
    Vehicle* findVehicleByID(string id) {
        for(int i = 0; i < vehicles.getSize(); ++i) {
            if(vehicles[i]->getID() == id) { return vehicles[i]; }
        }
        return nullptr;
    }

    void displayFleetStatus() {
        cout << "\n--- Fleet Status ---\n";

        for(int i = 0; i < vehicles.getSize(); ++i)
        cout << *vehicles[i] << endl; 

        cout << "\n--- Driver Status ---\n";
        for(int i = 0; i < drivers.getSize(); ++i) {
            cout << *drivers[i] << endl;
        }
        cout << "\n--- Passenger Status ---\n";
        for(int i = 0; i < passengers.getSize(); ++i) {
            cout << *passengers[i] << endl;
        }

        cout << "\n--- Ride Status ---\n";
        for(int i = 0; i < rides.getSize(); ++i) {
            cout << *rides[i] << endl;
        }
        cout << "--------------------\n";
    }

    Vehicle* getVehicleByIndex(int index) {
        if(index >= 0 && index < vehicles.getSize()) { return vehicles[index]; }
        return nullptr;
    }
};

void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

int main() { 
    FleetManager fm;
    int choice;
    
    setColor(11);
    cout << "============================================" << endl;
    cout << "        RIDE MANAGEMENT SYSTEM v1.0         " << endl;
    cout << "============================================" << endl;
    cout << "   [ DEVELOPED BY ]" << endl;
    cout << "   > Vishal Kumar (24K-0625)" << endl;
    cout << "   > Ali Raza     (24K-1040)" << endl;
    cout << "   > Zia          (24K-0817)" << endl;
    cout << "============================================" << endl << endl;

    cout << "=== SYSTEM INITIALIZATION ===\n";
    setColor(14);

    do {
        cout << "\n1. Add Vehicle\n";
        cout << "2. Add Driver\n";
        cout << "3. Add Passenger\n";
        cout << "4. Driver Login/Logout\n";
        cout << "5. Assign Vehicle to Driver\n";
        cout << "6. Book & Start Ride\n";
        cout << "7. Complete Latest Ride\n";
        cout << "8. Force Maintenance (Friend Function)\n";
        cout << "9. Display All Status\n";
        cout << "0. Exit\n";
        cout << "Enter Choice: ";
        
        if (!(cin >> choice)) { 
            cout << "Invalid input. Please enter a number.\n";
            cin.clear(); 
            char c;
            while(cin.get(c) && c != '\n'); 
            continue;
        }

        switch(choice) {
            case 1: {
                int typeOpt;
                string model;
                cout << "Select Type: 1.Bike, 2.Car, 3.Rickshaw, 4.Premium: ";
                cin >> typeOpt;
                cin.ignore(); 
                cout << "Enter Model Name: ";
                getline(cin, model);

                Vehicle* v = nullptr;
                if (typeOpt == 1) v = new Bike(model);
                else if (typeOpt == 2) v = new Car(model);
                else if (typeOpt == 3) v = new Rickshaw(model);
                else if (typeOpt == 4) v = new Premium(model);
                else cout << "Invalid Vehicle Type.\n";

                if (v) fm.addVehicle(v);
                break;
            }
            case 2: {
                string name, license;
                int age;
                cout << "Enter Driver Name: ";
                cin.ignore(); 
                getline(cin, name);
                cout << "Enter Age: ";
                cin >> age;
                cout << "Enter License No: ";
                cin.ignore(); 
                getline(cin, license);
                
                try {
                    Driver* d = new Driver(name, age, license, 5.0); 
                    fm.addDriver(d);
                } catch(const char* msg) {
                    cout << "Registration Failed: " << msg << endl;
                }
                break;
            }
            case 3: {
                string name, phone;
                int age;
                cout << "Enter Passenger Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter Phone: ";
                cin >> phone;
                cout << "Enter Age: ";
                cin >> age;

                Passenger* p = new Passenger(name, phone, age);
                fm.addPassenger(p);
                break;
            }
            case 4: {
                string id;
                int action;
                cout << "Enter Driver ID (e.g., D100): ";
                cin >> id;
                Driver* d = fm.findDriver(id);
                if (d) {
                    cout << "1. Login\n2. Logout\nChoice: ";
                    cin >> action;
                    if (action == 1) d->login();
                    else if (action == 2) d->logout();
                    else cout << "Invalid action.\n";
                } else {
                    cout << "Driver not found.\n";
                }
                break;
            }
            case 5: {
                string dID;
                int typeOpt;
                string typeStr;
                cout << "Enter Driver ID: ";
                cin >> dID;
                cout << "Select Vehicle Type to assign: 1.Bike, 2.Car, 3.Rickshaw, 4.Premium: ";
                cin >> typeOpt;
                
                if (typeOpt == 1) typeStr = "Bike";
                else if (typeOpt == 2) typeStr = "Car";
                else if (typeOpt == 3) typeStr = "Rickshaw";
                else if (typeOpt == 4) typeStr = "Premium";
                else { cout << "Invalid type.\n"; break; }

                try {
                    fm.assignVehicleToDriver(dID, typeStr);
                } catch (const char* msg) {
                    cout << "Error: " << msg << endl;
                }
                break;
            }
            case 6: {
                string pID, dID, src, dest;
                double dist;
                cout << "Enter Passenger ID: "; cin >> pID;
                cout << "Enter Driver ID: "; cin >> dID;
                cout << "Enter Source: "; cin.ignore(); getline(cin, src);
                cout << "Enter Destination: "; getline(cin, dest);
                cout << "Enter Distance (km): "; cin >> dist;
                
                try {
                    fm.createRide(pID, dID, dist, src, dest, "Now");
                } catch(const char* msg) {
                    cout << "Booking Failed: " << msg << endl;
                }
                break;
            }
            case 7: {
                double hours, rating;
                cout << "Enter Ride Duration (hours): "; cin >> hours;
                cout << "Enter Rating for Driver (1-5): "; cin >> rating;
                fm.completeLatestRide(hours, rating);
                break;
            }
            case 8: {
                string vID;
                cout << "Enter Vehicle ID to Force Maintenance (e.g., V100): ";
                cin >> vID;
                Vehicle* v = fm.findVehicleByID(vID); 

                if(v) {
                    forceMaintenanceReset(v);
                } else {
                    cout << "Vehicle not found.\n";
                }
                break;
            }
            case 9:
                fm.displayFleetStatus();
                break;
            case 0:
                cout << "Exiting system...\n";
                break;
            default:
                cout << "Invalid Choice. Try again.\n";
        }

    } while(choice != 0);

    cout << "\n=== Program Ending... FleetManager will cleanup ===\n";
    return 0;
}