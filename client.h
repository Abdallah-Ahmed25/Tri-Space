#ifndef CLIENT_H
#define CLIENT_H
#include <Qstring>
#include <QTime>

class Client
{
public:
    Client();
    //==========================================================
    // Setters ==>
    //==========================================================
    // <== Client iformations set functions ==>
    void setName(QString name);
    void setAge(int age);
    void setEmail(QString email);
    void setNumber(QString num);
    void setHandle_Name(QString Hname);
    void setID(int id = -1);

    // <== Session Details set functions ==>
    void setDuration(const int &duration);
    void setStartTime(const QTime &duration);
    void setBooking(int y, int mon, int d, int h, int m);

    // <== Payment Details set functions ==>
    void setCost_per_hour(QString cost);
    void setTotalCost(const int &time_duration);
    void setPayment_Method(QString Pay_M);
    //==========================================================
    // Getters ==>
    //==========================================================
    // <== Client iformations get functions ==>
    QString getName();
    int getAge();
    QString getEmail();
    QString getNumber();
    QString getHandle_Name();
    int getID();

    // <== Session Details get functions ==>
    int getDuration();
    QTime getStartTime();
    QTime getEndTime(const int &time_duration, const QTime &start_time);

    // <== Payment Details get functions ==>
    double getCost_per_hour();
    double getTotalCost();
    QString getPayment_Method();
private:
    // <== Client iformations ==>
    QString Name;
    int Age;
    QString Email;
    QString Number;
    QString Handle_Name;
    int ID;

    // <== Session Details ==>
    int Duration;
    QTime StartTime = QTime(0, 0);
    QTime EndTime;

    // <== Payment Details ==>
    double Cost_per_hour;
    double TotalCost;
    QString Payment_Method;
};

#endif // Client_H
