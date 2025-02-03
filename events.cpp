#include "events.h"

events::events() {}

void events::setDoor(QString _door){
    door=_door;
}

void events::setType(QString type){
    PartyType=type;
}

void events::setPhotographer(bool photo){
    Photographer=photo;
}

void events::setLighting(QString light ){
    Lighting = light;
}

void events::setNumberOfInvited(int invited){
    InvitedPeople = invited;
}

void events::setDrinks (QString drink){
    DrinksType=drink;
}

void events::setFood (QString food){
    FoodType=food;
}

void events::setMusic (QString music){
    MusicType=music;
}

void events::setwifi(bool wifi){
    Wifi=wifi;
}

void events::setvisual(QString visual){
    Visual = visual;
}

void events::setnotebooks(bool note){
    Notebooks=note;
}

void events::setpens(bool pen){
    Pens=pen;
}

void events::setmarkers(bool marker){
    Markers=marker;
}

void events::setprinting(bool print){
    Printing=print;
}


QString events::getDoor(){return door;}
QString events::getType(){return PartyType;}
bool events::getPhotographer(){return Photographer;}
QString events::getLighting(){return Lighting;}
QString events::getDrinks (){return DrinksType;}
QString events::getFood () {return FoodType;}
QString events::getMusic (){return MusicType;}
bool events::getwifi(){return Wifi;}
QString events::getvisual(){return Visual;}
bool events::getnotebooks(){return Notebooks;}
bool events::getpens(){return Pens;}
bool events::getmarkers(){return Markers;}
bool events::getprinting(){return Printing;}
int events::getNumberOfInvited(){return InvitedPeople;}
