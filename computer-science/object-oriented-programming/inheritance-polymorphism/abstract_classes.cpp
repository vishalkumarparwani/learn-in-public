#include <iostream>
#include <string>
using namespace std;
class Notification {
protected:
    string recipient;
public:
    Notification(string n) : recipient(n) {}
    virtual ~Notification () {}
    virtual bool validate() {
        if(recipient == "") {
            cout << "Recipient's name is empty\n";
            return false;
        }
        return true;
    }
    virtual void send(const string& message) = 0;
    virtual string channelName() = 0;
};
class EmailNotification : public Notification {
    string subject;
    string Email;
public:
    EmailNotification(string recipient, string subject, string Email) : subject(subject), Email(Email), Notification(recipient) {}
    bool validate() {
        for(int i = 0; i < Email.length(); ++i) {
            if(Email[i] == '@') {
                return true;
            }
            else {
                continue;
            }
        }
        return false;
    }
    void send(const string& message){
        cout <<"To: " << recipient << " < " << Email << "\nSubject: " << subject << "\nMessage: " << message << endl;

    }
    string channelName() {
        return "EMAIL";
    }
};
class SMSNotification : public Notification {
    string phoneNumber;
public:
    SMSNotification(string number, string recipient) : phoneNumber(number), Notification(recipient) {}
    bool validate() {
        if(phoneNumber.length() < 7) {
            cout << "Number's Too Short\n";
            return false;
        }
        return true;
    }
    void send(const string& message){
        cout << "To: " << recipient << "\nPhone Number: " << phoneNumber << "\nMessage: " << message << endl;
    }
    string channelName() {
        return "SMS";
    }
};
class PushNotification : public Notification {
    string deviceToken;
public:
    PushNotification(string token, string recipient) : deviceToken(token), Notification(recipient) {}
    bool validate() {
        if(deviceToken.empty()) {
            cout << "Recipient's Device Token is empty\n";
            return false;
        }
        return true;
    }
    void send(const string& message){
        cout << "To: " << recipient << "\nDevice Token: " << deviceToken << "\nMessage: " << message << endl;
    }
    string channelName() {
        return "PUSH";
    }
};
int main() {
    Notification* notifications[4];

    notifications[0] = new EmailNotification("Jack", "Unable to attend class", "abc@gmail.com");
    notifications[1] = new EmailNotification("Jane", "Promotion", "abdgmail.com");
    notifications[2] = new SMSNotification("923345325296", "Ali");
    notifications[3] = new PushNotification("XYZ", "John");

    for(int i = 0; i < 4; ++i) {
        cout << "\n\n" << notifications[i]->channelName() << endl;
        if(notifications[i]->validate()) {
            notifications[i]->send("Your mail has been sent");
        }
        cout << endl;
    }

    for(int i = 0; i < 4; ++i) {
        delete notifications[i];
    }
    return 0;
}