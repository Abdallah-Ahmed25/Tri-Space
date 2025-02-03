#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QLabel>
#include <QGraphicsBlurEffect>
#include <QResizeEvent>
#include <QCoreApplication>
#include <QApplication>
#include <QPushButton>
#include <QSoundEffect>
#include <QTimer>
#include <QDir>
#include <QInputDialog>
#include <QPixmap>
#include "client.h"
#include "gaming_management.h"
#include "customer.h"
#include <fstream>
#include "events.h"
bool p=0;
int page_index;

Client client[7];
Gaming_Management gaming[7];

Client client2[7];
Study study[7];

Client client3[7];
events eventt[7];

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow), background(new QLabel(this)) {
    ui->setupUi(this);
    this->showFullScreen();
    ui->spinmultip->hide();
//=======================================================================================
// ===============================Sound Effect Section===================================
//=======================================================================================

    soundEffect = new QSoundEffect(this);
    soundEffect->setSource(QUrl::fromLocalFile(":/musics/506054__mellau__button-click-1.wav"));
    soundEffect->setVolume(0.5);

//=======================================================================================
//===============================Hide GAME LABLE=========================================
//=======================================================================================

    ui->totalcost->hide();
    ui->DurationL->hide();
    ui->ID->hide();

    ui->totalcost_2->hide();
    ui->DurationL_2->hide();
    ui->ID_2->hide();

    ui->totalcost_3->hide();
    ui->DurationL_3->hide();
    ui->ID_3->hide();

    ui->totalcost_4->hide();
    ui->DurationL_4->hide();
    ui->ID_4->hide();

    ui->totalcost_5->hide();
    ui->DurationL_5->hide();
    ui->ID_5->hide();

    ui->totalcost_6->hide();
    ui->DurationL_6->hide();
    ui->ID_6->hide();
//======================================================================================
    ui->get_total->hide();
    ui->get_total_2->hide();
    ui->get_total_3->hide();
    ui->get_total_4->hide();
    ui->get_total_5->hide();
    ui->get_total_6->hide();

    ui->get_id->hide();
    ui->get_id_2->hide();
    ui->get_id_3->hide();
    ui->get_id_4->hide();
    ui->get_id_5->hide();
    ui->get_id_6->hide();

    ui->get_dur->hide();
    ui->get_dur_2->hide();
    ui->get_dur_3->hide();
    ui->get_dur_4->hide();
    ui->get_dur_5->hide();
    ui->get_dur_6->hide();
//======================================================================================
    ui->btnedit->hide();
    ui->btnedit_2->hide();
    ui->btnedit_3->hide();
    ui->btnedit_4->hide();
    ui->btnedit_5->hide();
    ui->btnedit_6->hide();
//======================================================================================
//===============================Hide STUDY LABLE=======================================
//======================================================================================
    ui->spinBox_group->hide();

    ui->totalcost_S->hide();
    ui->DurationL_S->hide();
    ui->ID_S->hide();

    ui->totalcost_S_2->hide();
    ui->DurationL_S_2->hide();
    ui->ID_S_2->hide();

    ui->totalcost_S_3->hide();
    ui->DurationL_S_3->hide();
    ui->ID_S_3->hide();

    ui->totalcost_S_4->hide();
    ui->DurationL_S_4->hide();
    ui->ID_S_4->hide();

    ui->totalcost_S_5->hide();
    ui->DurationL_S_5->hide();
    ui->ID_S_5->hide();

    ui->totalcost_S_6->hide();
    ui->DurationL_S_6->hide();
    ui->ID_S_6->hide();
//=======================================================================================
    ui->get_total_S->hide();
    ui->get_total_S_2->hide();
    ui->get_total_S_3->hide();
    ui->get_total_S_4->hide();
    ui->get_total_S_5->hide();
    ui->get_total_S_6->hide();

    ui->get_id_S->hide();
    ui->get_id_S_2->hide();
    ui->get_id_S_3->hide();
    ui->get_id_S_4->hide();
    ui->get_id_S_5->hide();
    ui->get_id_S_6->hide();

    ui->get_dur_S->hide();
    ui->get_dur_S_2->hide();
    ui->get_dur_S_3->hide();
    ui->get_dur_S_4->hide();
    ui->get_dur_S_5->hide();
    ui->get_dur_S_6->hide();

//======================================================================================

    ui->btnedit_S->hide();
    ui->btnedit_S_2->hide();
    ui->btnedit_S_3->hide();
    ui->btnedit_S_4->hide();
    ui->btnedit_S_5->hide();
    ui->btnedit_S_6->hide();
//======================================================================================
//===============================Hide EVENTS LABLE======================================
//======================================================================================

    ui->totalcost_E->hide();
    ui->DurationL_E->hide();
    ui->ID_E->hide();

    ui->totalcost_E_2->hide();
    ui->DurationL_E_2->hide();
    ui->ID_E_2->hide();

    ui->totalcost_E_3->hide();
    ui->DurationL_E_3->hide();
    ui->ID_E_3->hide();

    ui->totalcost_E_4->hide();
    ui->DurationL_E_4->hide();
    ui->ID_E_4->hide();

    ui->totalcost_E_5->hide();
    ui->DurationL_E_5->hide();
    ui->ID_E_5->hide();

    ui->totalcost_E_6->hide();
    ui->DurationL_E_6->hide();
    ui->ID_E_6->hide();
//======================================================================================
    ui->get_total_E->hide();
    ui->get_total_E_2->hide();
    ui->get_total_E_3->hide();
    ui->get_total_E_4->hide();
    ui->get_total_E_5->hide();
    ui->get_total_E_6->hide();

    ui->get_id_E->hide();
    ui->get_id_E_2->hide();
    ui->get_id_E_3->hide();
    ui->get_id_E_4->hide();
    ui->get_id_E_5->hide();
    ui->get_id_E_6->hide();

    ui->get_dur_E->hide();
    ui->get_dur_E_2->hide();
    ui->get_dur_E_3->hide();
    ui->get_dur_E_4->hide();
    ui->get_dur_E_5->hide();
    ui->get_dur_E_6->hide();

//======================================================================================
    ui->btnedit_E->hide();
    ui->btnedit_E_2->hide();
    ui->btnedit_E_3->hide();
    ui->btnedit_E_4->hide();
    ui->btnedit_E_5->hide();
    ui->btnedit_E_6->hide();
//======================================================================================
// background section==========>>
    background->setPixmap(QPixmap(":/images/newbg.jpg"));
    background->setScaledContents(true);
    background->setGeometry(this->rect());
    background->lower();

    QGraphicsBlurEffect *blurEffect = new QGraphicsBlurEffect();
    blurEffect->setBlurRadius(10);
    background->setGraphicsEffect(blurEffect);

}

void MainWindow::resizeEvent(QResizeEvent *event) {
    if (background) {
        background->setGeometry(this->rect());
    }
    QMainWindow::resizeEvent(event);
}

MainWindow::~MainWindow() {
    delete ui;
}

//=============================Main Buttons==========================================

void MainWindow::on_btnlogin_clicked()
{
    soundEffect->play();
    QString Valid_userName[5] = {"Abdallah", "Amr", "Ibrahim", "DRHADEER", "Renad"};
    QString Valid_password[5] = {"Abdallah12", "Amr34", "Ibrahim56", "DRHADEER12", "Renad910"};

    QString User_userName = ui->textusername->text();
    QString User_password = ui->textpassword->text();

    bool registersuccess = false;
    for (int i = 0; i < 5; i++) {
        if (User_userName == Valid_userName[i] && User_password == Valid_password[i]) {
            QMessageBox::information(this, "Registered!", "Welcome " + User_userName);
            registersuccess = true;

            ui->stackedWidget->setCurrentIndex(OPTION_PAGE);

            break;
        }
    }

    if (!registersuccess) {
        QMessageBox::information(this, "Registration Failed", "Invalid Username Or Password"  "\n"
                                                              "Sorry Try Again");
    }
}

void MainWindow::on_btnexit_clicked()
{
    soundEffect->play();
    QMessageBox::StandardButton reply = QMessageBox::question(
        this, "Exit Application", "Are you sure you want to exit?",
        QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        QCoreApplication::quit();
    }
}

void MainWindow::on_btngames_clicked() {
    soundEffect->play();
    ui->stackedWidget->setCurrentIndex(GAME_PAGE);
}

void MainWindow::on_btnback_toMain_clicked() {
    soundEffect->play();
    ui->stackedWidget->setCurrentIndex(OPTION_PAGE);
}

void MainWindow::on_btnback_toMain_2_clicked() {
    soundEffect->play();
    ui->stackedWidget->setCurrentIndex(OPTION_PAGE);
}

void MainWindow::on_btnBack_toGR_clicked() {
    soundEffect->play();
    ui->stackedWidget->setCurrentIndex(GAME_PAGE);
}

void MainWindow::on_btnstudy_clicked() {
    soundEffect->play();
    ui->stackedWidget->setCurrentIndex(STUDY_PAGE);
}

void MainWindow::on_btnBack_toSR_clicked() {
    soundEffect->play();
    ui->stackedWidget->setCurrentIndex(STUDY_PAGE);
}

//=======================================================================================
void MainWindow::on_btnadd_clicked() {
    soundEffect->play();
    page_index = 1;
    ui->stackedWidget->setCurrentIndex(GAME2_PAGE);
}

void MainWindow::on_btnadd_2_clicked() {
    soundEffect->play();
    page_index = 2;
    ui->stackedWidget->setCurrentIndex(GAME2_PAGE);
}

void MainWindow::on_btnadd_3_clicked() {
    soundEffect->play();
    page_index = 3;
    ui->stackedWidget->setCurrentIndex(GAME2_PAGE);
}

void MainWindow::on_btnadd_4_clicked(){
    soundEffect->play();
    page_index = 4;
    ui->stackedWidget->setCurrentIndex(GAME2_PAGE);
}

void MainWindow::on_btnadd_5_clicked() {
    soundEffect->play();
    page_index = 5;
    ui->stackedWidget->setCurrentIndex(GAME2_PAGE);
}

void MainWindow::on_btnadd_6_clicked() {
    soundEffect->play();
    page_index = 6;
    ui->stackedWidget->setCurrentIndex(GAME2_PAGE);
}

//=======================================


void MainWindow::on_btnadd_S_clicked() {
    soundEffect->play();
    page_index = 1;
    ui->stackedWidget->setCurrentIndex(STUDY2_PAGE);
}

void MainWindow::on_btnadd_S_2_clicked() {
    soundEffect->play();
    page_index = 2;
    ui->stackedWidget->setCurrentIndex(STUDY2_PAGE);
}

void MainWindow::on_btnadd_S_3_clicked() {
    soundEffect->play();
    page_index = 3;
    ui->stackedWidget->setCurrentIndex(STUDY2_PAGE);
}

void MainWindow::on_btnadd_S_4_clicked() {
    soundEffect->play();
    page_index = 4;
    ui->stackedWidget->setCurrentIndex(STUDY2_PAGE);
}

void MainWindow::on_btnadd_S_5_clicked() {
    soundEffect->play();
    page_index = 5;
    ui->stackedWidget->setCurrentIndex(STUDY2_PAGE);
}

void MainWindow::on_btnadd_S_6_clicked() {
    soundEffect->play();
    page_index = 6;
    ui->stackedWidget->setCurrentIndex(STUDY2_PAGE);
}

//==================================================
void MainWindow::on_btnadd_E_clicked() {
    soundEffect->play();
    page_index = 1;
    ui->stackedWidget->setCurrentIndex(EVENT2_PAGE);
}

void MainWindow::on_btnadd_E_2_clicked() {
    soundEffect->play();
    page_index = 2;
    ui->stackedWidget->setCurrentIndex(EVENT2_PAGE);
}

void MainWindow::on_btnadd_E_3_clicked() {
    soundEffect->play();
    page_index = 3;
    ui->stackedWidget->setCurrentIndex(EVENT2_PAGE);
}

void MainWindow::on_btnadd_E_4_clicked() {
    soundEffect->play();
    page_index = 4;
    ui->stackedWidget->setCurrentIndex(EVENT2_PAGE);
}

void MainWindow::on_btnadd_E_5_clicked() {
    soundEffect->play();
    page_index = 5;
    ui->stackedWidget->setCurrentIndex(EVENT2_PAGE);
}

void MainWindow::on_btnadd_E_6_clicked() {
    soundEffect->play();
    page_index = 6;
    ui->stackedWidget->setCurrentIndex(EVENT2_PAGE);
}
//========================================================
void MainWindow::on_btnedit_clicked() {
    soundEffect->play();
    page_index = 1;
    ui->stackedWidget->setCurrentIndex(GAME2_PAGE);
}

void MainWindow::on_btnedit_2_clicked() {
    soundEffect->play();
    page_index = 2;
    ui->stackedWidget->setCurrentIndex(GAME2_PAGE);
}

void MainWindow::on_btnedit_3_clicked() {
    soundEffect->play();
    page_index = 3;
    ui->stackedWidget->setCurrentIndex(GAME2_PAGE);
}

void MainWindow::on_btnedit_4_clicked() {
    soundEffect->play();
    page_index = 4;
    ui->stackedWidget->setCurrentIndex(GAME2_PAGE);
}

void MainWindow::on_btnedit_5_clicked() {
    soundEffect->play();
    page_index = 5;
    ui->stackedWidget->setCurrentIndex(GAME2_PAGE);
}

void MainWindow::on_btnedit_6_clicked() {
    soundEffect->play();
    page_index = 6;
    ui->stackedWidget->setCurrentIndex(GAME2_PAGE);
}
//===========================================================
void MainWindow::on_checkBoxmulti_stateChanged(int arg1) {
    if (arg1 == Qt::Checked) {
        ui->spinmultip->show();
    }
    else {
        ui->spinmultip->hide();
    }
}

void MainWindow::on_btnsave_clicked()
{
    soundEffect->play();

    client[page_index].setName(ui->txtname->text());
    client[page_index].setEmail(ui->txtemail->text());
    client[page_index].setNumber(ui->txtnumber->text());
    client[page_index].setHandle_Name(ui->txthandle->text());
    client[page_index].setID(ui->txtid->text().toInt());
    client[page_index].setAge(ui->spinage->text().toInt());
    gaming[page_index].setGameTitle(ui->combogametitle->currentText());
    gaming[page_index].setType_of_game(ui->combogametype->currentText());
    gaming[page_index].setPlatform(ui->combogamePF->currentText());
    client[page_index].setPayment_Method(ui->combopaymentm->currentText());


    if(ui->radioButton->isChecked()){
        gaming[page_index].setLightingLevel(1);
    }
    if(ui->radioButton_2->isChecked()){
        gaming[page_index].setLightingLevel(2);
    }
    if(ui->radioButton_3->isChecked()){
        gaming[page_index].setLightingLevel(3);
    }
    if(ui->radioButton_4->isChecked()){
        gaming[page_index].setLightingLevel(4);
    }
    if(ui->radioButton_5->isChecked()){
        gaming[page_index].setLightingLevel(5);
    }
    client[page_index].setDuration(ui->Editduration->text().toInt());
    client[page_index].setStartTime(ui->Editstart->time());


    std::ifstream idcheck("A:/Engineering/cpp_projects/college_projecs/proj/project_5 - Copy (3)/data/ids.txt");
    QString entered_id = ui->txtid->text();
    bool found_id = false;
    QVector<QString> vector_id;
    std::string temp_id;
    while (idcheck >> temp_id) {
        vector_id.push_back(QString::fromStdString(temp_id));
    }
    idcheck.close();
    for(int i = 0; i < (vector_id.size()); i++){
        if(vector_id[i] == entered_id) {found_id = true; break;}
    }
    if(!found_id) {QMessageBox::information(this, "Error!", "you entered a wrong id ");
        QString userInput = QInputDialog::getText(nullptr,"Creat ID","Enter New ID : ",QLineEdit::Normal,QString());
        std::ofstream out1("A:/Engineering/cpp_projects/college_projecs/proj/project_5 - Copy (3)/data/ids.txt", std::ios::app);
        out1<<"\n" << userInput.toStdString();
        out1.close();
    }

    client[page_index].setCost_per_hour("G");
    client[page_index].setTotalCost(client[page_index].getDuration());

    if (page_index == 1) {
        ui->btnadd->hide();
        ui->totalcost->show();
        ui->DurationL->show();
        ui->ID->show();
        ui->btnedit->show();

        ui->get_total->show();
        ui->get_dur->show();
        ui->get_id->show();

        ui->get_total->setText(QString::number(client[page_index].getTotalCost()));
        ui->get_dur->setText((client[page_index].getEndTime(client[page_index].getDuration(), client[page_index].getStartTime())).toString("hh:mm:AP"));
        ui->get_id->setText(QString::number(client[page_index].getID()));
        ui->client1->setText(client[page_index].getName());
    }
    else if (page_index == 2) {
        ui->btnadd_2->hide();
        ui->totalcost_2->show();
        ui->DurationL_2->show();
        ui->ID_2->show();
        ui->btnedit_2->show();

        ui->get_total_2->show();
        ui->get_dur_2->show();
        ui->get_id_2->show();

        ui->get_total_2->setText(QString::number(client[page_index].getTotalCost()));
        ui->get_dur_2->setText((client[page_index].getEndTime(client[page_index].getDuration(), client[page_index].getStartTime())).toString("hh:mm:AP"));
        ui->get_id_2->setText(QString::number(client[page_index].getID()));
        ui->client2->setText(client[page_index].getName());
    }
    else if (page_index == 3) {
        ui->btnadd_3->hide();
        ui->totalcost_3->show();
        ui->DurationL_3->show();
        ui->ID_3->show();
        ui->btnedit_3->show();

        ui->get_total_3->show();
        ui->get_dur_3->show();
        ui->get_id_3->show();

        ui->get_total_3->setText(QString::number(client[page_index].getTotalCost()));
        ui->get_dur_3->setText((client[page_index].getEndTime(client[page_index].getDuration(), client[page_index].getStartTime())).toString("hh:mm:AP"));
        ui->get_id_3->setText(QString::number(client[page_index].getID()));
        ui->client3->setText(client[page_index].getName());

    }
    else if (page_index == 4) {
        ui->btnadd_4->hide();
        ui->totalcost_4->show();
        ui->DurationL_4->show();
        ui->ID_4->show();
        ui->btnedit_4->show();

        ui->get_total_4->show();
        ui->get_dur_4->show();
        ui->get_id_4->show();

        ui->get_total_4->setText(QString::number(client[page_index].getTotalCost()));
        ui->get_dur_4->setText((client[page_index].getEndTime(client[page_index].getDuration(), client[page_index].getStartTime())).toString("hh:mm:AP"));
        ui->get_id_4->setText(QString::number(client[page_index].getID()));
        ui->client4->setText(client[page_index].getName());
    }
    else if (page_index == 5) {
        ui->btnadd_5->hide();
        ui->totalcost_5->show();
        ui->DurationL_5->show();
        ui->ID_5->show();
        ui->btnedit_5->show();

        ui->get_total_5->show();
        ui->get_dur_5->show();
        ui->get_id_5->show();

        ui->get_total_5->setText(QString::number(client[page_index].getTotalCost()));
        ui->get_dur_5->setText((client[page_index].getEndTime(client[page_index].getDuration(), client[page_index].getStartTime())).toString("hh:mm:AP"));
        ui->get_id_5->setText(QString::number(client[page_index].getID()));
        ui->client5->setText(client[page_index].getName());
    }
    else if (page_index == 6) {
        ui->btnadd_6->hide();
        ui->totalcost_6->show();
        ui->DurationL_6->show();
        ui->ID_6->show();
        ui->btnedit_6->show();

        ui->get_total_6->show();
        ui->get_dur_6->show();
        ui->get_id_6->show();

        ui->get_total_6->setText(QString::number(client[page_index].getTotalCost()));
        ui->get_dur_6->setText((client[page_index].getEndTime(client[page_index].getDuration(), client[page_index].getStartTime())).toString("hh:mm:AP"));
        ui->get_id_6->setText(QString::number(client[page_index].getID()));
        ui->client6->setText(client[page_index].getName());
    }
}

//----------------------------------------------------------------------------------------------------------------->
//---------------------------------------------------STUDY--------------------------------------------------------->
//----------------------------------------------------------------------------------------------------------------->

void MainWindow::on_btnsave_2_clicked() {
    soundEffect->play();
    client2[page_index].setName(ui->txtnameS->text());
    client2[page_index].setEmail(ui->txtemailS->text());
    client2[page_index].setNumber(ui->txtnumberS->text());
    client2[page_index].setID(ui->txtidS->text().toInt());
    client2[page_index].setAge(ui->txtageS->text().toInt());
    client2[page_index].setPayment_Method(ui->combopaymentm_2->currentText());

    if (ui->btnIndividual->isChecked()){
        study[page_index].setStudyType(2,1);
    }
    else if(ui->btnGroup->isChecked()){
        study[page_index].setStudyType(1,ui->spinBox_group->text().toInt());
    }
    if(ui->BtnYES->isChecked()){
        study[page_index].setAirConditioning(1);
    }
    if(ui->BtnYES_2->isChecked()){
        study[page_index].setCharger(1);
    }
    if(ui->BtnYES_3->isChecked()){
        study[page_index].setLighting(1);
    }
    if(ui->BtnYES_4->isChecked()){
        study[page_index].setDrinks((1));
    }
    if(ui->BtnYES_5->isChecked()){
        study[page_index].setPrinting(1);
    }
    if(ui->BtnYES_6->isChecked()){
        study[page_index].setSnacks(1);
    }
    if(ui->BtnYES_7->isChecked()){
        study[page_index].setWifi(1);
    }
    if(ui->BtnNO->isChecked()){
        study[page_index].setAirConditioning(2);
    }
    if(ui->BtnNO_2->isChecked()){
        study[page_index].setCharger(2);
    }
    if(ui->BtnNO_3->isChecked()){
        study[page_index].setLighting(2);
    }
    if(ui->BtnNO_4->isChecked()){
        study[page_index].setDrinks((2));
    }
    if(ui->BtnNO_5->isChecked()){
        study[page_index].setPrinting(2);
    }
    if(ui->BtnNO_6->isChecked()){
        study[page_index].setSnacks(2);
    }
    if(ui->BtnNO_7->isChecked()){
        study[page_index].setWifi(2);
    }

    client2[page_index].setDuration(ui->Editduration_S->text().toInt());
    client2[page_index].setStartTime(ui->Editstart_S->time());

    std::ifstream idcheck("A:/Engineering/cpp_projects/college_projecs/proj/project_5 - Copy (3)/data/ids.txt");
    QString entered_id = ui->txtidS->text();
    bool found_id = false;
    QVector<QString> vector_id;
    std::string temp_id;
    while (idcheck >> temp_id) {
        vector_id.push_back(QString::fromStdString(temp_id));
    }
    idcheck.close();
    for(int i = 0; i < (vector_id.size()); i++){
        if(vector_id[i] == entered_id) {found_id = true; break;}
    }
    if(!found_id) {QMessageBox::information(this, "Error!", "you entered a wrong id ");
        QString userInput = QInputDialog::getText(nullptr,"Create ID ","Enter New ID : ",QLineEdit::Normal,QString());
        std::ofstream out1("A:/Engineering/cpp_projects/college_projecs/proj/project_5 - Copy (3)/data/ids.txt", std::ios::app);
        out1<<"\n" << userInput.toStdString();
        out1.close();
    }

    if (page_index == 1) {

        ui->btnadd_S->hide();
        ui->totalcost_S->show();
        ui->DurationL_S->show();
        ui->ID_S->show();
        ui->btnedit_S->show();

        ui->get_total_S->show();
        ui->get_dur_S->show();
        ui->get_id_S->show();

        ui->get_total_S->setText(QString::number(client2[page_index].getTotalCost()));
        ui->get_dur_S->setText((client2[page_index].getEndTime(client2[page_index].getDuration(), client2[page_index].getStartTime())).toString("hh:mm:AP"));
        ui->get_id_S->setText(QString::number(client2[page_index].getID()));
        ui->client1_2->setText(client2[page_index].getName());
    }
    else if (page_index == 2) {
        ui->btnadd_S_2->hide();
        ui->totalcost_S_2->show();
        ui->DurationL_S_2->show();
        ui->ID_S_2->show();
        ui->btnedit_S_2->show();

        ui->get_total_S_2->show();
        ui->get_dur_S_2->show();
        ui->get_id_S_2->show();

        ui->get_total_S_2->setText(QString::number(client2[page_index].getTotalCost()));
        ui->get_dur_S_2->setText((client2[page_index].getEndTime(client2[page_index].getDuration(), client2[page_index].getStartTime())).toString("hh:mm:AP"));
        ui->get_id_S_2->setText(QString::number(client2[page_index].getID()));
        ui->client2_2->setText(client2[page_index].getName());
    }
    else if (page_index == 3) {
        ui->btnadd_S_3->hide();
        ui->totalcost_S_3->show();
        ui->DurationL_S_3->show();
        ui->ID_S_3->show();
        ui->btnedit_S_3->show();

        ui->get_total_S_3->show();
        ui->get_dur_S_3->show();
        ui->get_id_S_3->show();

        ui->get_total_S_3->setText(QString::number(client2[page_index].getTotalCost()));
        ui->get_dur_S_3->setText((client2[page_index].getEndTime(client2[page_index].getDuration(), client2[page_index].getStartTime())).toString("hh:mm:AP"));
        ui->get_id_S_3->setText(QString::number(client2[page_index].getID()));
        ui->client3_2->setText(client2[page_index].getName());

    }
    else if (page_index == 4) {
        ui->btnadd_S_4->hide();
        ui->totalcost_S_4->show();
        ui->DurationL_S_4->show();
        ui->ID_S_4->show();
        ui->btnedit_S_4->show();

        ui->get_total_S_4->show();
        ui->get_dur_S_4->show();
        ui->get_id_S_4->show();

        ui->get_total_S_4->setText(QString::number(client2[page_index].getTotalCost()));
        ui->get_dur_S_4->setText((client2[page_index].getEndTime(client2[page_index].getDuration(), client2[page_index].getStartTime())).toString("hh:mm:AP"));
        ui->get_id_S_4->setText(QString::number(client2[page_index].getID()));
        ui->client4_2->setText(client2[page_index].getName());
    }
    else if (page_index == 5) {
        ui->btnadd_S_5->hide();
        ui->totalcost_S_5->show();
        ui->DurationL_S_5->show();
        ui->ID_S_5->show();
        ui->btnedit_S_5->show();

        ui->get_total_S_5->show();
        ui->get_dur_S_5->show();
        ui->get_id_S_5->show();

        ui->get_total_S_5->setText(QString::number(client2[page_index].getTotalCost()));
        ui->get_dur_S_5->setText((client2[page_index].getEndTime(client2[page_index].getDuration(), client2[page_index].getStartTime())).toString("hh:mm:AP"));
        ui->get_id_S_5->setText(QString::number(client2[page_index].getID()));
        ui->client5_2->setText(client2[page_index].getName());
    }
    else if (page_index == 6) {
        ui->btnadd_S_6->hide();
        ui->totalcost_S_6->show();
        ui->DurationL_S_6->show();
        ui->ID_S_6->show();
        ui->btnedit_S_6->show();

        ui->get_total_S_6->show();
        ui->get_dur_S_6->show();
        ui->get_id_S_6->show();

        ui->get_total_S_6->setText(QString::number(client2[page_index].getTotalCost()));
        ui->get_dur_S_6->setText((client2[page_index].getEndTime(client2[page_index].getDuration(), client2[page_index].getStartTime())).toString("hh:mm:AP"));
        ui->get_id_S_6->setText(QString::number(client2[page_index].getID()));
        ui->client6_2->setText(client2[page_index].getName());
        }
    }

void MainWindow::on_btnGroup_clicked() {
    ui->spinBox_group->show();
}

void MainWindow::on_btnIndividual_clicked() {
    ui->spinBox_group->hide();
}

//----------------------------------------------------------------------------------------------------------------->
//--------------------------------------------------GENERAL-------------------------------------------------------->
//----------------------------------------------------------------------------------------------------------------->
void MainWindow::on_stackedWidget_currentChanged(int page) {
    switch (page) {
        case GAME2_PAGE:{
            ui->spinage->setValue(client[page_index].getAge());
            ui->txtname->setText(client[page_index].getName());
            ui->txtemail->setText(client[page_index].getEmail());
            ui->txtnumber->setText(client[page_index].getNumber());
            ui->txthandle->setText(client[page_index].getHandle_Name());
            ui->txtid->setText(QString::number(client[page_index].getID()));
            ui->Editstart->clear();
            ui->Editstart->setTime(client[page_index].getStartTime());
            ui->Editduration->clear();
            ui->Editduration->setValue(client[page_index].getDuration());
            ui->combopaymentm->setCurrentIndex(0);
            ui->combopaymentm->setCurrentText(client[page_index].getPayment_Method());

            ui->combogametitle->setCurrentIndex(0);
            ui->combogametitle->setCurrentText(gaming[page_index].getGameTitle());
            ui->combogametype->setCurrentIndex(0);
            ui->combogametype->setCurrentText(gaming[page_index].getType_of_game());
            ui->combogamePF->setCurrentIndex(0);
            ui->combogamePF->setCurrentText(gaming[page_index].getPlatform());
            ui->spindiffculty->setValue(gaming[page_index].getDifficultyLevel());

            ui->radioButton->setAutoExclusive(false);
            ui->radioButton_2->setAutoExclusive(false);
            ui->radioButton_3->setAutoExclusive(false);
            ui->radioButton_4->setAutoExclusive(false);
            ui->radioButton_5->setAutoExclusive(false);

            ui->radioButton->setChecked(false);
            ui->radioButton_2->setChecked(false);
            ui->radioButton_3->setChecked(false);
            ui->radioButton_4->setChecked(false);
            ui->radioButton_5->setChecked(false);

            ui->radioButton->setAutoExclusive(true);
            ui->radioButton_2->setAutoExclusive(true);
            ui->radioButton_3->setAutoExclusive(true);
            ui->radioButton_4->setAutoExclusive(true);
            ui->radioButton_5->setAutoExclusive(true);

            if (gaming[page_index].getLightingLevel() == 1) {
                ui->radioButton->setChecked(true);
            }
            else if (gaming[page_index].getLightingLevel() == 2) {
                ui->radioButton_2->setChecked(true);
            }
            else if (gaming[page_index].getLightingLevel() == 3) {
                ui->radioButton_3->setChecked(true);
            }
            else if (gaming[page_index].getLightingLevel() == 4) {
                ui->radioButton_4->setChecked(true);
            }
            else if (gaming[page_index].getLightingLevel() == 5) {
                ui->radioButton_5->setChecked(true);
            }

            break;
        }
        case STUDY2_PAGE:{
            ui->txtageS->setText(QString::number(client2[page_index].getAge()));
            ui->txtnameS->setText(client2[page_index].getName());
            ui->txtemailS->setText(client2[page_index].getEmail());
            ui->txtnumberS->setText(client2[page_index].getNumber());
            ui->txtidS->setText(QString::number(client2[page_index].getID()));
            ui->Editstart_S->clear();
            ui->Editstart_S->setTime(client2[page_index].getStartTime());
            ui->Editduration_S->clear();
            ui->Editduration_S->setValue(client2[page_index].getDuration());
            ui->combopaymentm_2->setCurrentIndex(0);
            ui->combopaymentm_2->setCurrentText(client2[page_index].getPayment_Method());

            ui->spinBox_group->hide();
            ui->btnGroup->setAutoExclusive(false);
            ui->btnIndividual->setAutoExclusive(false);

            ui->btnGroup->setChecked(false);
            ui->btnIndividual->setChecked(false);

            ui->btnGroup->setAutoExclusive(true);
            ui->btnIndividual->setAutoExclusive(true);

            if (study[page_index].getNumberOfPersons() == 1) {
                ui->btnIndividual->setChecked(true);
            }
            else if (study[page_index].getNumberOfPersons() > 1) {
                ui->btnGroup->setChecked(true);
                ui->spinBox_group->show();
                ui->spinBox_group->setValue(study[page_index].getNumberOfPersons());
            }

            ui->BtnYES->setAutoExclusive(false);
            ui->BtnNO->setAutoExclusive(false);

            ui->BtnYES->setChecked(false);
            ui->BtnNO->setChecked(false);

            ui->BtnYES->setAutoExclusive(true);
            ui->BtnNO->setAutoExclusive(true);
            if (study[page_index].getAirConditioning() == 1) {
                ui->BtnYES->setChecked(true);
            }
            else if (study[page_index].getAirConditioning() == 2) {
                ui->BtnNO->setChecked(true);
            }
            ui->BtnYES_2->setAutoExclusive(false);
            ui->BtnNO_2->setAutoExclusive(false);

            ui->BtnYES_2->setChecked(false);
            ui->BtnNO_2->setChecked(false);

            ui->BtnYES_2->setAutoExclusive(true);
            ui->BtnNO_2->setAutoExclusive(true);
            if (study[page_index].getCharger() == 1) {
                ui->BtnYES_2->setChecked(true);
            }
            else if (study[page_index].getCharger() == 2) {
                ui->BtnNO_2->setChecked(true);
            }
            ui->BtnYES_3->setAutoExclusive(false);
            ui->BtnNO_3->setAutoExclusive(false);

            ui->BtnYES_3->setChecked(false);
            ui->BtnNO_3->setChecked(false);

            ui->BtnYES_3->setAutoExclusive(true);
            ui->BtnNO_3->setAutoExclusive(true);
            if (study[page_index].getLighting() == 1) {
                ui->BtnYES_3->setChecked(true);
            }
            else if (study[page_index].getLighting() == 2) {
                ui->BtnNO_3->setChecked(true);
            }
            ui->BtnYES_4->setAutoExclusive(false);
            ui->BtnNO_4->setAutoExclusive(false);

            ui->BtnYES_4->setChecked(false);
            ui->BtnNO_4->setChecked(false);

            ui->BtnYES_4->setAutoExclusive(true);
            ui->BtnNO_4->setAutoExclusive(true);
            if (study[page_index].getDrinks() == 1) {
                ui->BtnYES_4->setChecked(true);
            }
            else if (study[page_index].getDrinks() == 2) {
                ui->BtnNO_4->setChecked(true);
            }
            ui->BtnYES_5->setAutoExclusive(false);
            ui->BtnNO_5->setAutoExclusive(false);

            ui->BtnYES_5->setChecked(false);
            ui->BtnNO_5->setChecked(false);

            ui->BtnYES_5->setAutoExclusive(true);
            ui->BtnNO_5->setAutoExclusive(true);
            if (study[page_index].getPrinting() == 1) {
                ui->BtnYES_5->setChecked(true);
            }
            else if (study[page_index].getPrinting() == 2) {
                ui->BtnNO_5->setChecked(true);
            }
            ui->BtnYES_6->setAutoExclusive(false);
            ui->BtnNO_6->setAutoExclusive(false);

            ui->BtnYES_6->setChecked(false);
            ui->BtnNO_6->setChecked(false);

            ui->BtnYES_6->setAutoExclusive(true);
            ui->BtnNO_6->setAutoExclusive(true);
            if (study[page_index].getSnacks() == 1) {
                ui->BtnYES_6->setChecked(true);
            }
            else if (study[page_index].getSnacks() == 2) {
                ui->BtnNO_6->setChecked(true);
            }
            ui->BtnYES_7->setAutoExclusive(false);
            ui->BtnNO_7->setAutoExclusive(false);

            ui->BtnYES_7->setChecked(false);
            ui->BtnNO_7->setChecked(false);

            ui->BtnYES_7->setAutoExclusive(true);
            ui->BtnNO_7->setAutoExclusive(true);
            if (study[page_index].getWifi() == 1) {
                ui->BtnYES_7->setChecked(true);
            }
            else if (study[page_index].getWifi() == 2) {
                ui->BtnNO_7->setChecked(true);
            }
            break;
        }
        case EVENT2_PAGE:{
            ui->txtage_E->setText(QString::number(client3[page_index].getAge()));
            ui->txtname_E->setText(client3[page_index].getName());
            ui->txtemail_E->setText(client3[page_index].getEmail());
            ui->txtnumber_E->setText(client3[page_index].getNumber());
            ui->txtid_E->setText(QString::number(client3[page_index].getID()));
            ui->Editstart_2->clear();
            ui->Editstart_2->setTime(client3[page_index].getStartTime());
            ui->Editduration_2->clear();
            ui->Editduration_2->setValue(client3[page_index].getDuration());
            ui->combopayment_E->setCurrentIndex(0);
            ui->combopayment_E->setCurrentText(client3[page_index].getPayment_Method());

            ui->comboparty->setCurrentIndex(0);
            ui->comboparty->setCurrentText(eventt[page_index].getType());
            ui->combodrinks->setCurrentIndex(0);
            ui->combodrinks->setCurrentText(eventt[page_index].getDrinks());
            ui->combodrinks_2->setCurrentIndex(0);
            ui->combodrinks_2->setCurrentText(eventt[page_index].getDrinks());
            ui->combomusic->setCurrentIndex(0);
            ui->combomusic->setCurrentText(eventt[page_index].getMusic());

            ui->combolighting->setCurrentIndex(0);
            ui->combolighting->setCurrentText(eventt[page_index].getLighting());
            ui->Editinvited->setValue(eventt[page_index].getNumberOfInvited());


            ui->indoor->setAutoExclusive(false);
            ui->outdoor->setAutoExclusive(false);
            ui->photo->setAutoExclusive(false);
            ui->smart_screen->setAutoExclusive(false);
            ui->projector->setAutoExclusive(false);
            ui->Wifi->setAutoExclusive(false);
            ui->Notebooks->setAutoExclusive(false);
            ui->markers->setAutoExclusive(false);
            ui->pens->setAutoExclusive(false);
            ui->printing->setAutoExclusive(false);
            ui->lunch->setAutoExclusive(false);
            ui->dessert->setAutoExclusive(false);


            ui->indoor->setChecked(false);
            ui->outdoor->setChecked(false);
            ui->photo->setChecked(false);
            ui->smart_screen->setChecked(false);
            ui->projector->setChecked(false);
            ui->Wifi->setChecked(false);
            ui->Notebooks->setChecked(false);
            ui->markers->setChecked(false);
            ui->pens->setChecked(false);
            ui->printing->setChecked(false);
            ui->lunch->setChecked(false);
            ui->dessert->setChecked(false);


            ui->indoor->setAutoExclusive(true);
            ui->outdoor->setAutoExclusive(true);
            ui->photo->setAutoExclusive(true);
            ui->smart_screen->setAutoExclusive(true);
            ui->projector->setAutoExclusive(true);


            if (eventt[page_index].getDoor() == "indoor") {
                ui->indoor->setChecked(true);
            }
            else if (eventt[page_index].getDoor() == "outdoor") {
                ui->outdoor->setChecked(true);
            }

            if (eventt[page_index].getPhotographer()) {
                ui->photo->setChecked(true);
            }

            if (eventt[page_index].getvisual() == "smart screen") {
                ui->smart_screen->setChecked(true);
            }
            else if (eventt[page_index].getvisual() == "projector") {
                ui->projector->setChecked(true);
            }

            if (eventt[page_index].getwifi()) {
                ui->Wifi->setChecked(true);
            }
            if (eventt[page_index].getnotebooks()) {
                ui->Notebooks->setChecked(true);
            }
            if (eventt[page_index].getmarkers()) {
                ui->markers->setChecked(true);
            }
            if (eventt[page_index].getpens()) {
                ui->pens->setChecked(true);
            }
            if (eventt[page_index].getprinting()) {
                ui->printing->setChecked(true);
            }

            if (eventt[page_index].getFood() == "both") {
                ui->lunch->setChecked(true);
                ui->dessert->setChecked(true);
            }
            else if (eventt[page_index].getFood() == "lunch") {
                ui->lunch->setChecked(true);
            }
            else if (eventt[page_index].getFood() == "dessert"){
                ui->dessert->setChecked(true);
            }

            break;
        }
        default:
            break;
    }
}

void MainWindow::on_btnparty_clicked() {
    soundEffect->play();
    ui->stackedWidget_2->setCurrentIndex(0);
}

void MainWindow::on_btnmetting_clicked() {
    soundEffect->play();
    ui->stackedWidget_2->setCurrentIndex(1);
    p=1;
}

void MainWindow::on_btnBack_toEV_clicked() {
    soundEffect->play();
    ui->stackedWidget->setCurrentIndex(EVENT_PAGE);
}


void MainWindow::on_btnevents_clicked() {
    soundEffect->play();
    ui->stackedWidget->setCurrentIndex(EVENT_PAGE);
}

void MainWindow::on_btnback_toMain_3_clicked() {
    soundEffect->play();
    ui->stackedWidget->setCurrentIndex(OPTION_PAGE);
}
//----------------------------------------------------------------------------------------------------------------->
//---------------------------------------------------Event--------------------------------------------------------->
//----------------------------------------------------------------------------------------------------------------->


void MainWindow::on_btnsave_3_clicked()
{
    soundEffect->play();

    client3[page_index].setName(ui->txtname_E->text());
    client3[page_index].setEmail(ui->txtemail_E->text());
    client3[page_index].setNumber(ui->txtnumber_E->text());
    client3[page_index].setID(ui->txtid_E->text().toInt());
    client3[page_index].setAge(ui->txtage_E->text().toInt());
    client3[page_index].setPayment_Method(ui->combopayment_E->currentText());
    client3[page_index].setDuration(ui->Editduration_2->text().toInt());
    client3[page_index].setStartTime(ui->Editstart_2->time());
    client3[page_index].setCost_per_hour("E");
    client3[page_index].setTotalCost(client3[page_index].getDuration());

    eventt[page_index].setType(ui->comboparty->currentText());
    eventt[page_index].setDrinks(ui->combodrinks->currentText());
    eventt[page_index].setMusic(ui->combomusic->currentText());
    eventt[page_index].setNumberOfInvited(ui->Editinvited->text().toInt());
    eventt[page_index].setLighting(ui->combolighting->currentText());
    if(p)eventt[page_index].setDrinks(ui->combodrinks_2->currentText());
    p=0;
    if((ui->dessert->isChecked()) && (ui->lunch->isChecked()))
        eventt[page_index].setFood("both");
    else if(ui->dessert->isChecked())
        eventt[page_index].setFood("dessert");
    else if(ui->lunch->isChecked())
        eventt[page_index].setFood("lunch");

    if(ui->outdoor->isChecked())
        eventt[page_index].setDoor("outdoor");
    if(ui->indoor->isChecked()) {
        eventt[page_index].setDoor("indoor");
    }

    if(ui->photo->isChecked())
        eventt[page_index].setPhotographer(true);


    std::ifstream idcheck("A:/Engineering/cpp_projects/college_projecs/proj/project_5 - Copy (3)/data/ids.txt");
    QString entered_id = ui->txtid_E->text();
    bool found_id = false;
    QVector<QString> vector_id;
    std::string temp_id;
    while (idcheck >> temp_id) {
        vector_id.push_back(QString::fromStdString(temp_id));
    }
    idcheck.close();
    for(int i = 0; i < (vector_id.size()); i++){
        if(vector_id[i] == entered_id) {found_id = true; break;}
    }
    if(!found_id) {QMessageBox::information(this, "Error!", "you entered a wrong id ");
        QString userInput = QInputDialog::getText(nullptr,"Create ID","Enter New ID : ",QLineEdit::Normal,QString());
        std::ofstream out1("A:/Engineering/cpp_projects/college_projecs/proj/project_5 - Copy (3)/data/ids.txt", std::ios::app);
        out1<<"\n" << userInput.toStdString();
        out1.close();
    }

    if (page_index == 1) {
        ui->btnadd_E->hide();
        ui->totalcost_E->show();
        ui->DurationL_E->show();
        ui->ID_E->show();
        ui->btnedit_E->show();

        ui->get_total_E->show();
        ui->get_dur_E->show();
        ui->get_id_E->show();

        ui->get_total_E->setText(QString::number(client3[page_index].getTotalCost()));
        ui->get_dur_E->setText((client3[page_index].getEndTime(client3[page_index].getDuration(), client3[page_index].getStartTime())).toString("hh:mm:AP"));
        ui->get_id_E->setText(QString::number(client3[page_index].getID()));
        ui->client_E->setText(client3[page_index].getName());
    }
    else if (page_index == 2) {
        ui->btnadd_E_2->hide();
        ui->totalcost_E_2->show();
        ui->DurationL_E_2->show();
        ui->ID_E_2->show();
        ui->btnedit_E_2->show();

        ui->get_total_E_2->show();
        ui->get_dur_E_2->show();
        ui->get_id_E_2->show();

        ui->get_total_E_2->setText(QString::number(client3[page_index].getTotalCost()));
        ui->get_dur_E_2->setText((client3[page_index].getEndTime(client3[page_index].getDuration(), client3[page_index].getStartTime())).toString("hh:mm:AP"));
        ui->get_id_E_2->setText(QString::number(client3[page_index].getID()));
        ui->client_E_2->setText(client3[page_index].getName());
    }
    else if (page_index == 3) {
        ui->btnadd_E_3->hide();
        ui->totalcost_E_3->show();
        ui->DurationL_E_3->show();
        ui->ID_E_3->show();
        ui->btnedit_E_3->show();

        ui->get_total_E_3->show();
        ui->get_dur_E_3->show();
        ui->get_id_E_3->show();

        ui->get_total_E_3->setText(QString::number(client3[page_index].getTotalCost()));
        ui->get_dur_E_3->setText((client3[page_index].getEndTime(client3[page_index].getDuration(), client3[page_index].getStartTime())).toString("hh:mm:AP"));
        ui->get_id_E_3->setText(QString::number(client3[page_index].getID()));
        ui->client_E_3->setText(client3[page_index].getName());

    }
    else if (page_index == 4) {
        ui->btnadd_E_4->hide();
        ui->totalcost_E_4->show();
        ui->DurationL_E_4->show();
        ui->ID_E_4->show();
        ui->btnedit_E_4->show();

        ui->get_total_E_4->show();
        ui->get_dur_E_4->show();
        ui->get_id_E_4->show();

        ui->get_total_E_4->setText(QString::number(client3[page_index].getTotalCost()));
        ui->get_dur_E_4->setText((client3[page_index].getEndTime(client3[page_index].getDuration(), client3[page_index].getStartTime())).toString("hh:mm:AP"));
        ui->get_id_E_4->setText(QString::number(client3[page_index].getID()));
        ui->client_E_4->setText(client3[page_index].getName());
    }
    else if (page_index == 5) {
        ui->btnadd_E_5->hide();
        ui->totalcost_E_5->show();
        ui->DurationL_E_5->show();
        ui->ID_E_5->show();
        ui->btnedit_E_5->show();

        ui->get_total_E_5->show();
        ui->get_dur_E_5->show();
        ui->get_id_E_5->show();

        ui->get_total_E_5->setText(QString::number(client3[page_index].getTotalCost()));
        ui->get_dur_E_5->setText((client3[page_index].getEndTime(client3[page_index].getDuration(), client3[page_index].getStartTime())).toString("hh:mm:AP"));
        ui->get_id_E_5->setText(QString::number(client3[page_index].getID()));
        ui->client_E_5->setText(client3[page_index].getName());
    }
    else if (page_index == 6) {
        ui->btnadd_E_6->hide();
        ui->totalcost_E_6->show();
        ui->DurationL_E_6->show();
        ui->ID_E_6->show();
        ui->btnedit_E_6->show();

        ui->get_total_E_6->show();
        ui->get_dur_E_6->show();
        ui->get_id_E_6->show();

        ui->get_total_E_6->setText(QString::number(client3[page_index].getTotalCost()));
        ui->get_dur_E_6->setText((client3[page_index].getEndTime(client3[page_index].getDuration(), client3[page_index].getStartTime())).toString("hh:mm:AP"));
        ui->get_id_E_6->setText(QString::number(client3[page_index].getID()));
        ui->client_E_6->setText(client3[page_index].getName());
    }

    if(ui->Wifi->isChecked()) {
        eventt[page_index].setwifi(true);
    }
    else {
        eventt[page_index].setwifi(false);
    }

    if(ui->Notebooks->isChecked()) {
        eventt[page_index].setnotebooks(true);
    }
    else {
        eventt[page_index].setnotebooks(false);
    }

    if(ui->pens->isChecked()) {
        eventt[page_index].setpens(true);
    }
    else {
        eventt[page_index].setpens(false);
    }

    if(ui->markers->isChecked()) {
        eventt[page_index].setmarkers(true);
    }
    else {
        eventt[page_index].setmarkers(false);
    }

    if(ui->printing->isChecked()) {
        eventt[page_index].setprinting(true);
    }
    else {
        eventt[page_index].setprinting(false);
    }

    if(ui->smart_screen->isChecked()) {
        eventt[page_index].setvisual("smart screen");
    }
    else if(ui->projector->isChecked()) {
        eventt[page_index].setvisual("projector");
    }
}


void MainWindow::on_btnedit_S_clicked() {
    soundEffect->play();
    page_index = 1;
    ui->stackedWidget->setCurrentIndex(STUDY2_PAGE);
}

void MainWindow::on_btnedit_S_2_clicked() {
    soundEffect->play();
    page_index = 2;
    ui->stackedWidget->setCurrentIndex(STUDY2_PAGE);
}

void MainWindow::on_btnedit_S_3_clicked() {
    soundEffect->play();
    page_index = 3;
    ui->stackedWidget->setCurrentIndex(STUDY2_PAGE);
}

void MainWindow::on_btnedit_S_4_clicked() {
    soundEffect->play();
    page_index = 4;
    ui->stackedWidget->setCurrentIndex(STUDY2_PAGE);
}

void MainWindow::on_btnedit_S_5_clicked() {
    soundEffect->play();
    page_index = 5;
    ui->stackedWidget->setCurrentIndex(STUDY2_PAGE);
}

void MainWindow::on_btnedit_S_6_clicked() {
    soundEffect->play();
    page_index = 6;
    ui->stackedWidget->setCurrentIndex(STUDY2_PAGE);
}


void MainWindow::on_btnedit_E_clicked() {
    soundEffect->play();
    page_index = 1;
    ui->stackedWidget->setCurrentIndex(EVENT2_PAGE);
}


void MainWindow::on_btnedit_E_2_clicked() {
    soundEffect->play();
    page_index = 2;
    ui->stackedWidget->setCurrentIndex(EVENT2_PAGE);
}


void MainWindow::on_btnedit_E_3_clicked() {
    soundEffect->play();
    page_index = 3;
    ui->stackedWidget->setCurrentIndex(EVENT2_PAGE);
}


void MainWindow::on_btnedit_E_4_clicked() {
    soundEffect->play();
    page_index = 4;
    ui->stackedWidget->setCurrentIndex(EVENT2_PAGE);
}


void MainWindow::on_btnedit_E_5_clicked() {
    soundEffect->play();
    page_index = 5;
    ui->stackedWidget->setCurrentIndex(EVENT2_PAGE);
}


void MainWindow::on_btnedit_E_6_clicked() {
    soundEffect->play();
    page_index = 6;
    ui->stackedWidget->setCurrentIndex(EVENT2_PAGE);
}

