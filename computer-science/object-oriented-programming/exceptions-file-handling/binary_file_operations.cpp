#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Robot
{
    double temperature;
    char battery_health[50];
    int joint_stress_level;
    char error_logs[100];
};

template <typename T>
class DataPacket
{
public:
    void save(string filename, T data)
    {
        ofstream file(filename, ios::out | ios::binary | ios::app);
        if (!file)
        {
            throw "ErrorOpeningFile";
        }
        file.write((char *)&data, sizeof(T));
        file.close();
    }

    T load(string filename, int index)
    {
        ifstream file(filename, ios::in | ios::binary);
        if (!file)
        {
            throw "ErrorOpeningFile";
        }
        T data;
        file.clear();
        file.seekg(index * sizeof(T));
        file.read((char *)&data, sizeof(T));
        file.close();
        return data;
    }
};

int main()
{
    DataPacket<Robot> packet1;
    string file = "data.bin";

    Robot r1;
    r1.temperature = 37.8;

    string health = "Good";
    for (int i = 0; i < health.length(); ++i)
    {
        r1.battery_health[i] = health[i];
    }
    r1.battery_health[4] = '\0';

    r1.joint_stress_level = 5;
    r1.error_logs[0] = '\0';

    packet1.save(file, r1);

    Robot loaded = packet1.load(file, 0);

    cout << "Loaded temperature: " << loaded.temperature << endl;
    cout << "Loaded battery health: " << loaded.battery_health << endl;
    cout << "Loaded joint stress level: " << loaded.joint_stress_level << endl;
    cout << "Loaded error logs: " << loaded.error_logs << endl;

    return 0;
}