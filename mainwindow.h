#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QSoundEffect>

#define LOGIN_PAGE  0
#define OPTION_PAGE 1
#define EVENT_PAGE  2
#define EVENT2_PAGE 3
#define STUDY_PAGE  4
#define STUDY2_PAGE 5
#define GAME_PAGE   6
#define GAME2_PAGE  7


QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnlogin_clicked();
    void on_btnexit_clicked();
    void on_btngames_clicked();
    void on_btnback_toMain_clicked();

    void on_btnback_toMain_2_clicked();

    void on_btnadd_clicked();


    void on_btnadd_2_clicked();

    void on_btnBack_toGR_clicked();

    void on_checkBoxmulti_stateChanged(int arg1);

    void on_btnsave_clicked();

    void on_btnadd_3_clicked();

    void on_btnadd_4_clicked();

    void on_btnadd_5_clicked();

    void on_btnadd_6_clicked();

    void on_btnstudy_clicked();

    void on_btnsave_2_clicked();

    void on_btnBack_toSR_clicked();


    void on_btnadd_S_clicked();

    void on_btnadd_S_2_clicked();

    void on_btnadd_S_3_clicked();

    void on_btnadd_S_4_clicked();

    void on_btnadd_S_5_clicked();

    void on_btnadd_S_6_clicked();



    void on_btnGroup_clicked();

    void on_btnIndividual_clicked();

    void on_stackedWidget_currentChanged(int arg1);

    void on_btnedit_clicked();

    void on_btnedit_2_clicked();

    void on_btnedit_3_clicked();

    void on_btnedit_4_clicked();

    void on_btnedit_5_clicked();

    void on_btnedit_6_clicked();

    void on_btnparty_clicked();

    void on_btnmetting_clicked();

    void on_btnBack_toEV_clicked();

    void on_btnadd_E_clicked();

    void on_btnadd_E_2_clicked();

    void on_btnadd_E_3_clicked();

    void on_btnadd_E_4_clicked();

    void on_btnadd_E_5_clicked();

    void on_btnadd_E_6_clicked();

    void on_btnevents_clicked();

    void on_btnback_toMain_3_clicked();


    void on_btnsave_3_clicked();

    void on_btnedit_S_clicked();

    void on_btnedit_S_2_clicked();

    void on_btnedit_S_3_clicked();

    void on_btnedit_S_4_clicked();

    void on_btnedit_S_5_clicked();

    void on_btnedit_S_6_clicked();

    void on_btnedit_E_clicked();

    void on_btnedit_E_2_clicked();

    void on_btnedit_E_3_clicked();

    void on_btnedit_E_4_clicked();

    void on_btnedit_E_5_clicked();

    void on_btnedit_E_6_clicked();

protected:
    void resizeEvent(QResizeEvent *event) override;

private:
    Ui::MainWindow *ui;
    QLabel *background;
    QSoundEffect *soundEffect;
};



#endif // MAINWINDOW_H
