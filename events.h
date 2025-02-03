#ifndef EVENTS_H
#define EVENTS_H
#include <QString>

class events
{
public:
    events();
    //setters
    void setDoor(QString door);
    void setType(QString type);
    void setPhotographer(bool photo);
    void setLighting(QString light );
    void setNumberOfInvited(int invited);
    void setDrinks (QString drink);
    void setFood (QString food);
    void setMusic (QString music);
    void setwifi(bool wifi);
    void setvisual(QString visual);
    void setnotebooks(bool note);
    void setpens(bool pen);
    void setmarkers(bool marker);
    void setprinting(bool print);
    // getters
    QString getDoor();
    QString getType();
    bool getPhotographer();
    QString getLighting();
    QString getDrinks ();
    QString getFood ();
    QString getMusic ();
    int getNumberOfInvited();
    bool getwifi();
    QString getvisual();
    bool getnotebooks();
    bool getpens();
    bool getmarkers();
    bool getprinting();
private:
    QString door;
    QString PartyType;
    bool Photographer;
    QString Lighting;
    int InvitedPeople;
    QString DrinksType;
    QString FoodType;
    QString MusicType;
    QString Visual;
    bool Wifi;
    bool Notebooks;
    bool Pens;
    bool Markers;
    bool Printing;
};

#endif // EVENTS_H
