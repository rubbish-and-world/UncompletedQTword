#include "loginwindow.h"
#include "ui_loginwindow.h"
#include <Qt>
#include <string>
#include <QMessageBox>

Loginwindow::Loginwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Loginwindow)
{
    ui->setupUi(this);
    this->setWindowFlag(Qt::FramelessWindowHint);   //set frameless, show full screen
    this->setCursor(Qt::CrossCursor);               //set cursor to cross

}


Loginwindow::~Loginwindow()
{
    delete ui;
}

std::string Loginwindow::get_account(){
    return this->ui->account->toPlainText().toUtf8().constData();
}

std::string Loginwindow::get_password(){
    return this->ui->password->toPlainText().toUtf8().constData();
}


void Loginwindow::on_cancelbtn_clicked()
{
    this->ui->account->setPlainText("");
    this->ui->password->setPlainText("");
    this->close();

}

void Loginwindow::on_submitbtn_clicked()
{

    std::string name = get_account();
    std::string pass = get_password();
    if (name == "van" && pass == "shit"){
        QMessageBox::about(NULL ,"Success","Enjoy your game !!!");
        test = "shit";
        emit logined(true);
        this->on_cancelbtn_clicked();
    }
    else{
        emit logined(false);
        QMessageBox::critical(NULL , "Error","Wrong password, please login again");
        this->ui->account->setPlainText("");
        this->ui->password->setPlainText("");
    }

}


