#include "customer.h"
#include <QDebug>

Study::Study() {
    isGroup = 0;
    numberOfPersons = 0;
    lighting = 0;
    airConditioning = 0;
    wifi = 0;
    charger = 0;
    printing = 0;
    snacks = 0;
    drinks = 0;
}


// Setters ==>
void Study::setStudyType(int isGroup_, int number) {
    isGroup = isGroup_;
    if (isGroup) {
        numberOfPersons = number;
    }
    else {
        numberOfPersons = 1;
    }
}

void Study::setLighting(int lighting_) {
    lighting = lighting_;
}

void Study::setAirConditioning(int airCondition_) {
    airConditioning = airCondition_;
}

void Study::setWifi(int wifi_) {
    wifi = wifi_;
}

void Study::setCharger(int charger_) {
    charger = charger_;
}

void Study::setPrinting(int printing_) {
    printing = printing_;
}

void Study::setSnacks(int snacks_) {
    snacks = snacks_;
}

void Study::setDrinks(int drinks_) {
    drinks = drinks_;
}


// Getters ==>
int Study::getIsGroup() const {
    return isGroup;
}

int Study::getNumberOfPersons() const {
    return numberOfPersons;
}

int Study::getLighting() const {
    return lighting;
}

int Study::getAirConditioning() const {
    return airConditioning;
}

int Study::getWifi() const {
    return wifi;
}

int Study::getCharger() const {
    return charger;
}

int Study::getPrinting() const {
    return printing;
}

int Study::getSnacks() const {
    return snacks;
}

int Study::getDrinks() const {
    return drinks;
}

QString Study::getStudyDetails() const {
    QString details;
    details += "Study type: " + QString(isGroup ? "Group" : "Individual") + "\n";
    if (isGroup) {
        details += "Number of persons: " + QString::number(numberOfPersons) + "\n";
    }
    details += "Lighting preference: " + QString(lighting ? "Yes" : "No") + "\n";
    details += "Air conditioning preference: " + QString(airConditioning ? "Yes" : "No") + "\n";
    details += "Wi-Fi preference: " + QString(wifi ? "Yes" : "No") + "\n";
    details += "Charger preference: " + QString(charger ? "Yes" : "No") + "\n";
    details += "Printing preference: " + QString(printing ? "Yes" : "No") + "\n";
    details += "Snack preference: " + QString(snacks ? "Yes" : "No") + "\n";
    details += "Drinks preference: " + QString(drinks ? "Yes" : "No") + "\n";
    return details;
}

void Study::printStudyDetails() const {
    qDebug() << getStudyDetails();
}
