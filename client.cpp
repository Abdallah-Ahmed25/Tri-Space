#include "client.h"
Client::Client() {}

//==========================================================
// Setters ==>
//==========================================================

// <== Client iformations set functions ==>
void Client::setName(QString name) {
    Name = name;
}

void Client::setAge(int age) {
    Age = age;
}

void Client::setEmail(QString email) {
    Email = email;
}

void Client::setNumber(QString num) {
    Number = num;
}

void Client::setHandle_Name(QString Hname) {
    Handle_Name = Hname;
}

static int nextID = 10000000;
bool HasID = false;
void Client::setID(int id) {
    if (id == -1) {
        ID = nextID++;
    }
    else {
        ID = id;
        HasID = true;
    }
}

// <== Session Details set functions ==>
void Client::setDuration(const int &duration) {
    Duration = duration;
}

void Client::setStartTime(const QTime &duration) {
    StartTime = duration;
}

// <== Payment Details set functions ==>
void Client::setCost_per_hour(QString cost) {
    if (HasID) {
        if (cost == "G")
            Cost_per_hour = 80;
        else if (cost == "S")
            Cost_per_hour = 50;
        else if (cost == "E")
            Cost_per_hour = 100;
    }
    else {
        if (cost == "G")
            Cost_per_hour = 80 * 1.25;
        else if (cost == "S")
            Cost_per_hour = 50 * 1.25;
        else if (cost == "E")
            Cost_per_hour = 100 * 1.25;
    }
}

void Client::setTotalCost(const int &time_duration) {
    TotalCost = (time_duration) * Cost_per_hour;
}

void Client::setPayment_Method(QString Pay_M) {
    Payment_Method = Pay_M;
}

//==========================================================
// Getters ==>
//==========================================================
// <== Client iformations get functions ==>
QString Client::getName() { return Name; }
int Client::getAge() { return Age; }
QString Client::getEmail() { return Email; }
QString Client::getNumber() { return Number; }
QString Client::getHandle_Name() { return Handle_Name; }
int Client::getID() { return ID; }

// <== Session Details get functions ==>
int Client::getDuration() { return Duration; }
QTime Client::getStartTime() { return StartTime; }

QTime Client::getEndTime(const int &time_duration, const QTime &start_time) {
    int totalHours = time_duration + start_time.hour();
    return QTime(totalHours % 24,start_time.minute());
}

// <== Payment Details get functions ==>
double Client::getCost_per_hour() { return Cost_per_hour; }
double Client::getTotalCost() { return TotalCost; }
QString Client::getPayment_Method() { return Payment_Method; }
