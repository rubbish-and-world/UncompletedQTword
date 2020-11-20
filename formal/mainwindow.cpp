#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <Qt>
#include "loginwindow.h"
#include <QMediaPlayer>
#include <iostream>
#include <QMessageBox>
#include <QListWidget>
#include <QAbstractItemView>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    this->setWindowFlag(Qt::FramelessWindowHint);   //set frameless, show full screen
    this->setCursor(Qt::CrossCursor);               //set cursor to cross

    //hide after-login functions
    this->ui->markbtn->hide();
    this->ui->marksbtn->hide();
    this->ui->stack->hide();
    this->ui->welcome->setAlignment(Qt::AlignCenter);

    quitgame = new QMediaPlayer;
    this->quitgame->setMedia(QUrl("qrc:/sounds/resource/mp3/quitgame.mp3"));


    loginwindow = new Loginwindow;

}


MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_exitbtn_clicked()
{
    //back to toplevel
    //write changes to variable
    //save to database
    quitgame->play();
    QMessageBox::StandardButton reply = QMessageBox::question(NULL , "EXIT" , "Do you really want to exit ?" ,
                                                              QMessageBox::Yes|QMessageBox::No);
    if(reply == QMessageBox::Yes){
        QApplication::quit();
    }
}




void MainWindow::on_loginbtn_clicked()
{
    loginwindow->show();



}

void MainWindow::enablebuttons(bool logined){
    if(logined){
        this->ui->markbtn->show();
        this->ui->marksbtn->show();
        this->ui->stack->show();
    }
}

void MainWindow::on_decks_itemClicked(QListWidgetItem *item)
{
        item->setText("fuck");
        auto index = ui->decks->selectionModel()->selectedIndexes().back().row();   //the index of the clicked item
        std::cout << index;
        ui->stack->setCurrentIndex(1);

}

void MainWindow::on_wordlists_itemClicked(QListWidgetItem *item)
{
    item->setText("fuck");
    auto index = ui->decks->selectionModel()->selectedIndexes().back().row();   //the index of the clicked item
    std::cout << index;
    ui->stack->setCurrentIndex(2);
}



void MainWindow::on_cards_cellDoubleClicked(int row, int column)
{
    auto clickedcell = ui->cards->itemAt(row , column);
    ui->cards->editItem(clickedcell);
    int card_index = row - 1 ;
    std::cout << row << column << card_index ;


}
