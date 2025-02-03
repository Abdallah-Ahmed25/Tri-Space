#include "gaming_management.h"
#include <QStringList>

Gaming_Management::Gaming_Management() {}

//==========================================================
// Setters ==>
//==========================================================
// <== Games Selection set functions ==>
void Gaming_Management::setGameTitle(QString title) {
    GameTitle = title;
}

void Gaming_Management::setType_of_game(QString type) {
    Type_of_game = type;
}

void Gaming_Management::setPlatform(QString PF) {
    Platform = PF;
}

// <== Games Settings set functions ==>
void Gaming_Management::setSingle_Or_Multi(QString SoM) {
    Single_Or_Multi = SoM;
}

void Gaming_Management::setOnline_or_Offline(QString OoF) {
    Online_or_Offline = OoF;
}

void Gaming_Management::setDifficultyLevel(int Difflevel) {
    DifficultyLevel = Difflevel;
}

void Gaming_Management::setLightingLevel(int lightlevel) {
    LightingLevel = lightlevel;
}

//==========================================================
// Getters ==>
//==========================================================
// <== Games Selection get functions ==>
QString Gaming_Management::getGameTitle() {
    return GameTitle;
}

QString Gaming_Management::getType_of_game() {
    return Type_of_game;
}

QString Gaming_Management::getPlatform() {
    return Platform;
}

// <== Games Settings set functions ==>
QString Gaming_Management::getSingle_Or_Multi() {
    return Single_Or_Multi;
}

QString Gaming_Management::getOnline_or_Offline() {
    return Online_or_Offline;
}

int Gaming_Management::getDifficultyLevel() {
    return DifficultyLevel;
}

int Gaming_Management::getLightingLevel() {
    return LightingLevel;
}










