#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "index.h"
#include "ui_index.h"
#include "mypushbutton.h"
#include <QDebug>
#include<bits/stdc++.h>
#include <QMessageBox>
#include<QNetworkAccessManager>
#include<QHostInfo>
#include<QNetworkReply>
#include<QNetworkRequest>
#include<QJsonDocument>
#include<QJsonObject>
#include<QJsonParseError>
#include <QSqlQuery>
#include <QDateTime>
extern QString uniname,int1,int2,int3,xcode,ycode,city,uniid,profilenum,ip;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    Net(new QNetworkAccessManager(this))
{
    this->setWindowFlags(Qt::WindowCloseButtonHint|Qt::WindowMinimizeButtonHint|Qt::FramelessWindowHint);
    ui->setupUi(this);
    ui->lineEdit->setEchoMode(QLineEdit::Password);
    MyPushButton *myb= new MyPushButton();
    myb->setParent(this);
    myb->resize(127,127);
    myb->move(1300,710);
    connect(myb,&MyPushButton::released,this,&MainWindow::check);
    QNetworkAccessManager* m_manager = new QNetworkAccessManager;
    QNetworkRequest request; request.setUrl(QUrl(QString("http://api64.ipify.org/?format=json")));
    m_manager->get(request);
    connect(m_manager, SIGNAL(finished(QNetworkReply*)), this,SLOT(dealMsg(QNetworkReply*)));



}
void MainWindow::dealMsg(QNetworkReply * reply)
{
    QByteArray array = reply->readAll();
    QJsonParseError error;
    QJsonDocument data = QJsonDocument::fromJson(array, &error);
    if (!data.isNull()) {
        QJsonObject obj = data.object();
        if (obj.contains("ip")) {
            QJsonValue val = obj.value("ip");
            qDebug()<<val.toString()<<"是ip";
            ip=val.toString();
            emit this->ipready();

        }
        reply->deleteLater();
    }
}

void MainWindow::check()
{
    QString login, password;
    login = ui->lineEdit_2->text();
    password = ui->lineEdit->text();
    qDebug()<<login<<"\nand\n"<<password;
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");  //连接本地主机
    db.setPort(3306);
    db.setDatabaseName("univot");
    db.setUserName("root");
    bool ok = db.open();
    if (!ok){
        QMessageBox MyBox(QMessageBox::Question,"提示","连接失败",QMessageBox::Ok);
        MyBox.exec();
    }else {
        qDebug() <<"连接成功";

    }
    QSqlQuery sql(db);
    QString str_sql_select = QString("select * from user where name = '%1'AND pw='%2';")
            .arg(login)
            .arg(password);
    QString str_sql_select1 = QString("select * from user where name = '%1';")
            .arg(login);
    if(sql.exec(str_sql_select) == true)
    {
        qDebug()<<"查询成功";
        if(sql.next() == true)
        {
            QString a1= sql.value(0).toString();
            QString b1= sql.value(1).toString();
            QString c1= sql.value(2).toString();
            QString d1= sql.value(3).toString();
            QString e1= sql.value(4).toString();
            QString f1= sql.value(5).toString();
            QString g1= sql.value(6).toString();
            QString h1= sql.value(7).toString();
            qDebug()<<"有这个账号"<<a1<<"密码"<<b1<<"1"<<c1<<"2"<<d1<<"3"<<e1<<"cre"<<f1<<"id"<<g1<<"profile"<<h1<<endl;
            uniname=a1;
            int1=c1;
            int2=d1;
            int3=e1;
            uniid=g1;
            profilenum=h1;
            qDebug() << "go" << endl;
            emit this->go();
            this->hide();




        }else
        {   if(sql.exec(str_sql_select1) == true&&(sql.next() == true)){ui->label_9->setText("密码错误");}else{
                qDebug()<<"没有这个账号";
                QDateTime dateTime= QDateTime::currentDateTime();
                QString str = dateTime .toString("Mdhhmmss");
                QString str_sql_insert = QString("INSERT INTO `univot`.`user` (`name`, `pw`,`id`) VALUES ('%1', '%2','%3');")
                        .arg(login)
                        .arg(password)
                        .arg(str);

                if(sql.exec(str_sql_insert) == false)
                {
                    qDebug() << "创建新账号失败" << endl;

                }
                else
                {
                    qDebug() << "创建新账号成功" << endl;
                    qDebug() << "go" << endl;
                    uniname=login;
                    int1="0";
                    int2="0";
                    int3="0";
                    uniid=str;

                    emit this->go();
                    this->hide();

                }

            }


        }
    }
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_lineEdit_editingFinished()
{

}
