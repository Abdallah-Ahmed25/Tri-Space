#ifndef STUDY_H
#define STUDY_H

#include <QString>

class Study {
public:
    Study();


    // Setters ==>
    void setStudyType(int isGroup_, int number);
    void setLighting(int lighting_);
    void setAirConditioning(int airCondition_);
    void setWifi(int wifi_);
    void setCharger(int charger_);
    void setPrinting(int printing_);
    void setSnacks(int snacks_);
    void setDrinks(int drinks_);


    // Getters ==>
    int getIsGroup() const;
    int getNumberOfPersons() const;
    int getLighting() const;
    int getAirConditioning() const;
    int getWifi() const;
    int getCharger() const;
    int getPrinting() const;
    int getSnacks() const;
    int getDrinks() const;

    QString getStudyDetails() const;
    void printStudyDetails() const;

private:
    int isGroup;
    int numberOfPersons;
    int lighting;
    int airConditioning;
    int wifi;
    int charger;
    int printing;
    int snacks;
    int drinks;
};

#endif// STUDY_H
