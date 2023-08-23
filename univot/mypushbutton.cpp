#include "mypushbutton.h"
#include <QDebug>

MyPushButton::MyPushButton(QWidget *parent) : QPushButton(parent)
{
    QString styleSheet = QString("QPushButton{background:url(%1); background-color:transparent;border: none; }"  //正常
            "QPushButton:hover{background:url(%2); background-color:transparent; }"  //滑过
            "QPushButton:pressed{background:url(%3); background-color:transparent; }") //按下
            .arg(":/resource/BUTTON.png")
            .arg(":/resource/BUTTON1.png")
            .arg(":/resource/BUTTON2.png");
        this->setStyleSheet(styleSheet);
    qDebug()<<"构造";
}
MyPushButton::~MyPushButton()
{
    qDebug()<<"析构";
}
