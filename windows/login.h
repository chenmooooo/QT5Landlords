#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QLineEdit>

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private:
    bool verifyData(QLineEdit* lineedit);

private slots:
    void SlotUserLogin();
    void SlotUserRegister();
    void SlotNetok();

private:
    Ui::Login *ui;
};



#endif // LOGIN_H
