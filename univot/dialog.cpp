#include "dialog.h"
#include "ui_dialog.h"
#include <QtSql/QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QDebug>
#include<bits/stdc++.h>
void creat(int);
extern QString uniname,int1,int2,int3,uniid,profilenum;
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{

    ui->setupUi(this);


    QString text;
    text=   QString("    uniid:%1       username:%2")
            .arg(uniid)
            .arg(uniname);
    ui->label_2->setText(text);
    QString styleSheet = QString("QPushButton{border-image:url(%2); background-color:transparent;border: none; }"
                                 "QPushButton:hover{border-image:url(%1); background-color:transparent;}")
            .arg(":/resource/BUTTON.png")
            .arg(":/resource/Afterclap-1.png");
    ui->pushButton->setStyleSheet(styleSheet);
    QString styleSheet1 = QString("QPushButton{border-image:url(%2); background-color:transparent;border: none; }"
                                  "QPushButton:hover{border-image:url(%1); background-color:transparent;}")
            .arg(":/resource/BUTTON.png")
            .arg(":/resource/Afterclap-2.png");
    ui->pushButton_2->setStyleSheet(styleSheet1);
    QString styleSheet2 = QString("QPushButton{border-image:url(%2); background-color:transparent;border: none; }"
                                  "QPushButton:hover{border-image:url(%1); background-color:transparent;}")
            .arg(":/resource/BUTTON.png")
            .arg(":/resource/Afterclap-3.png");
    ui->pushButton_3->setStyleSheet(styleSheet2);
    QString styleSheet3 = QString("QPushButton{border-image:url(%2); background-color:transparent;border: none; }"
                                  "QPushButton:hover{border-image:url(%1); background-color:transparent;}")
            .arg(":/resource/BUTTON.png")
            .arg(":/resource/Afterclap-4.png");
    ui->pushButton_4->setStyleSheet(styleSheet3);
    QString styleSheet4 = QString("QPushButton{border-image:url(%2); background-color:transparent;border: none; }"
                                  "QPushButton:hover{border-image:url(%1); background-color:transparent;}")
            .arg(":/resource/BUTTON.png")
            .arg(":/resource/Afterclap-5.png");
    ui->pushButton_5->setStyleSheet(styleSheet4);
    QString styleSheet5 = QString("QPushButton{border-image:url(%2); background-color:transparent;border: none; }"
                                  "QPushButton:hover{border-image:url(%1); background-color:transparent;}")
            .arg(":/resource/BUTTON.png")
            .arg(":/resource/Afterclap-6.png");
    ui->pushButton_6->setStyleSheet(styleSheet5);
    QString styleSheet6 = QString("QPushButton{border-image:url(%2); background-color:transparent;border: none; }"
                                  "QPushButton:hover{border-image:url(%1); background-color:transparent;}")
            .arg(":/resource/BUTTON.png")
            .arg(":/resource/Afterclap-7.png");
    ui->pushButton_7->setStyleSheet(styleSheet6);
    QString styleSheet7 = QString("QPushButton{border-image:url(%2); background-color:transparent;border: none; }"
                                  "QPushButton:hover{border-image:url(%1); background-color:transparent;}")
            .arg(":/resource/BUTTON.png")
            .arg(":/resource/Afterclap-8.png");
    ui->pushButton_8->setStyleSheet(styleSheet7);
    QString styleSheet8 = QString("QPushButton{border-image:url(%2); background-color:transparent;border: none; }"
                                  "QPushButton:hover{border-image:url(%1); background-color:transparent;}")
            .arg(":/resource/BUTTON.png")
            .arg(":/resource/Afterclap-9.png");
    ui->pushButton_9->setStyleSheet(styleSheet8);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_released()
{
    creat(1);
    this->close();
    emit this->newnum();
}

void Dialog::on_pushButton_2_released()
{
    creat(2);
    this->close();
    emit this->newnum();
}


void Dialog::on_pushButton_3_released()
{
    creat(3);
    this->close();
    emit this->newnum();
}


void Dialog::on_pushButton_4_released()
{
    creat(4);
    this->close();
    emit this->newnum();
}


void Dialog::on_pushButton_5_released()
{
    creat(5);
    this->close();
    emit this->newnum();
}


void Dialog::on_pushButton_6_released()
{
    creat(6);
    this->close();
    emit this->newnum();
}


void Dialog::on_pushButton_7_released()
{
    creat(7);
    this->close();
    emit this->newnum();
}


void Dialog::on_pushButton_8_released()
{
    creat(8);
    this->close();
    emit this->newnum();
}


void Dialog::on_pushButton_9_released()
{
    creat(9);
    this->close();
    emit this->newnum();
}

void creat(int c)
{

    QSqlDatabase dbb = QSqlDatabase::addDatabase("QMYSQL");
    dbb.setHostName("127.0.0.1");
    dbb.setPort(3306);
    dbb.setDatabaseName("univot");
    dbb.setUserName("root");
    bool ok = dbb.open();
    if (!ok){
        QMessageBox MyBox(QMessageBox::Question,"提示","连接失败",QMessageBox::Ok);
        MyBox.exec();
    }
    QSqlQuery sql(dbb);
    QString changeprofile = QString("UPDATE `user` SET `profile`=%2 WHERE  `name`='%1' AND `id`='%3' LIMIT 1;")
            .arg(uniname)
            .arg(c)
            .arg(uniid);
    profilenum=QString::number(c);

    if(sql.exec(changeprofile) == true)
    {
        qDebug()<<"修改成功";}


}

