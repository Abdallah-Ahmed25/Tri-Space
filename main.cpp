#include "mainwindow.h"
#include <QApplication>
#include <QGuiApplication>
#include <QScreen>
#include <QMediaPlayer>
#include <QAudioOutput>

QSize getScreenResolution() {
    QScreen *screen = QGuiApplication::primaryScreen();
    if (screen) {
        return screen->size();
    }
    return QSize(1920, 1080); // Default fallback resolution
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QSize screenSize = getScreenResolution();

    w.show();

    return a.exec();
}
