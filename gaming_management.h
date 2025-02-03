#ifndef GAMING_MANAGEMENT_H
#define GAMING_MANAGEMENT_H
#include <Qstring>

class Gaming_Management
{
public:
    Gaming_Management();
    //==========================================================
    // Setters ==>
    //==========================================================
    // <== Games Selection set functions ==>
    void setGameTitle(QString title);
    void setType_of_game(QString type);
    void setPlatform(QString PF);

    // <== Games Settings set functions ==>
    void setSingle_Or_Multi(QString SoM);
    void setOnline_or_Offline(QString OoF);
    void setDifficultyLevel(int Difflevel);
    void setLightingLevel(int lightlevel);

    //==========================================================
    // Getters ==>
    //==========================================================
    // <== Games Selection get functions ==>
    QString getGameTitle();
    QString getType_of_game();
    QString getPlatform();

    // <== Games Settings get functions ==>
    QString getSingle_Or_Multi();
    QString getOnline_or_Offline();
    int getDifficultyLevel();
    int getLightingLevel();
private:
    // <== Games Selection for client ==>

    QString GameTitle;
    QString Type_of_game;
    QString Platform;
    // <== Game Settings for client ==>

    QString Single_Or_Multi;
    QString Online_or_Offline;
    int DifficultyLevel;
    int LightingLevel;
};

#endif // GAMING_MANAGEMENT_H
