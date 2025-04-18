#include "login.h"
#include "ui_login.h"
#include "datamanager.h"

#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include <QThreadPool>

Login::Login(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);

    ui->stackedWidget->setCurrentIndex(0);

    connect(ui->homepushButton,&QPushButton::clicked,this,[=](){
        ui->stackedWidget->setCurrentIndex(0);
    });
    connect(ui->goresigterButton,&QPushButton::clicked,this,[=](){
        ui->stackedWidget->setCurrentIndex(1);
    });
    connect(ui->netsettingpushButton,&QPushButton::clicked,this,[=](){
        ui->stackedWidget->setCurrentIndex(2);
    });

    //数据校验
    QRegularExpression expage("^[a-zA-Z0-9_]{3,16}$");
    QRegularExpressionValidator *vali = new QRegularExpressionValidator(expage,this);
    ui->usernameLineEdit->setValidator(vali);
    ui->resigterusernamelineEdit->setValidator(vali);

    ui->passwordLineEdit->setValidator(vali);
    ui->resigterpasswordlineEidt->setValidator(vali);


    expage.setPattern("^1[3456789]\\d{9}$");
    QRegularExpressionValidator *valiphone = new QRegularExpressionValidator(expage,this);
    ui->resigterphomenumberlineEdit->setValidator(valiphone);

    //
    connect(ui->loginpushButton,&QPushButton::clicked,this,&Login::SlotUserLogin);
    connect(ui->resigterpushButton,&QPushButton::clicked,this,&Login::SlotUserRegister);
    connect(ui->netsavepushButton,&QPushButton::clicked,this,&Login::SlotNetok);

    QThreadPool::globalInstance()->setMaxThreadCount(8);


}

bool Login::verifyData(QLineEdit *lineedit)
{
    if(!lineedit->hasAcceptableInput())
    {
        lineedit->setStyleSheet("border: 2px solid red;");
        return false;
    }else
    {
        lineedit->setStyleSheet("none");
    }
    return true;
}


void Login::SlotUserLogin()
{
    bool flag = verifyData(ui->usernameLineEdit);
    flag &= verifyData(ui->passwordLineEdit);

    if(flag)
    {

    }
}

void Login::SlotUserRegister()
{
    bool flag = verifyData(ui->resigterusernamelineEdit);
    flag &= verifyData(ui->resigterpasswordlineEidt);
    flag &= verifyData(ui->resigterphomenumberlineEdit);

    if(flag)
    {

    }

}

void Login::SlotNetok()
{
    DataManager* instance = DataManager::GetInstance();
    instance->setUserIP(ui->ipaddrlineEdit->text().toUtf8());
    instance->setUserport(ui->portnumberlineEdit->text().toUtf8());
}

Login::~Login()
{
    delete ui;
}
