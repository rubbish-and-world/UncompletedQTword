#include "mainwindow.h"
#include <QApplication>
#include <QMediaPlayer>
#include <QMediaPlaylist>

#include <QTimer>
void loadmusic(){
    QMediaPlaylist * playlist = new QMediaPlaylist();
    playlist->addMedia(QUrl("qrc:/sounds/resource/mp3/backgroundmusic.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);
    QMediaPlayer *music = new QMediaPlayer();
    music->setPlaylist(playlist);
    music->play();
}


int main(int argc, char *argv[])
{

//    QTimer::singleShot(2500,&splash, &QSplashScreen::close);
//    QTimer::singleShot(2500,&login, &QSplashScreen::show);
//    QObject::connect(&login, &frmLogin::adminSignal, [&w](bool isAdmin){
//        w.show();
//    });


    QApplication a(argc, argv);
    MainWindow w;
    w.showFullScreen();

    QObject::connect(w.loginwindow, &Loginwindow::logined, &w, &MainWindow::enablebuttons);

    loadmusic();




    return a.exec();
}
