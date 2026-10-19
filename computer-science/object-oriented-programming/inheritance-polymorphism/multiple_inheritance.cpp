#include <iostream>
#include <string>
using namespace std;

class SystemCore {
private:
    string system_id;
public:
    SystemCore(string id = "") : system_id(id) {};
    
    virtual ~SystemCore() {
        cout << "System shutting down\n";
    }
    virtual void statusReport() {
        cout << "ID: " << system_id << " | System Online\n";
    }
};
class SensorModule : virtual public SystemCore {
private:
    float sensitivity;
public:
    SensorModule(string id = "", float sen = 0.0) : sensitivity(sen), SystemCore(id) {
        cout << "Sensors are set\n";
    }
    void statusReport() {
        cout << "Sensitivity: " << sensitivity << "%\n";
    }
};
class ControlModule : virtual public SystemCore {
private:
    int x, y, decision_control;
public:
    ControlModule(string id = "", int a = 0, int b = 0, int dc = 100) : SystemCore(id), x(a), y(b), decision_control(dc) {}
    void statusReport() {
        cout << "Current Position => X: " << x << ", Y: " << y << endl;
        cout << "Decision Control: " << decision_control << endl;
    }
};
class AutoBot : public SensorModule, public ControlModule {
private:
public:
    AutoBot(string id = "", float sen = 0.0, int a = 0, int b = 0, int dc = 100) : SystemCore(id), SensorModule(id, sen), ControlModule(id, a, b, dc) {
        cout << "AutoBot Ready!\n";
    }
    void statusReport() {
        cout << "\nAutoBot Report:\n";
        SystemCore::statusReport();
        SensorModule::statusReport();
        ControlModule::statusReport();
        cout << "----------------------\n";
    }
};

int main() {
    AutoBot bot1("Stack-Bot", 90.0, 12, 7, 6);
    bot1.statusReport();

    cout << "\nHeap Object:\n";

    SystemCore *s1 = new AutoBot("Heap-Bot", 45.5, 0, 0, 7);
    s1->statusReport();

    delete s1;
    return 0;
}