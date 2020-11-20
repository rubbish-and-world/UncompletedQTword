#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "loginwindow.h"
#include <QListWidget>
#include <QMediaPlayer>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_exitbtn_clicked();

    void on_loginbtn_clicked();

    void on_decks_itemClicked(QListWidgetItem *item);

    void on_wordlists_itemClicked(QListWidgetItem *item);

    void on_cards_cellDoubleClicked(int row, int column);

private:
    Ui::MainWindow *ui;


    /*      my members      */
public:
    Loginwindow * loginwindow;
    QMediaPlayer* quitgame;

    void  enablebuttons(bool logined);

       /*      my members      */

};
#endif // MAINWINDOW_H







