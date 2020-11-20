#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include <string>
namespace Ui {
class Loginwindow;
}

class Loginwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit Loginwindow(QWidget *parent = nullptr);

    /*      My members    */

    std::string get_account();
    std::string get_password();
    std::string test;

signals:
    void logined(bool);
    /*      My members    */
public:
    ~Loginwindow();

private slots:
    void on_cancelbtn_clicked();
    void on_submitbtn_clicked();

private:
    Ui::Loginwindow *ui;





};

#endif // LOGINWINDOW_H
