#include "index.h"
#include "ui_index.h"
#include "dialog.h"
#include "upload.h"
#include "diainfo.h"
#include "math.h"
#include <QApplication>
#include <string>
#include <QMessageBox>
#include<bits/stdc++.h>
#include <QDebug>
#include "upload.h"
#include <QStyledItemDelegate>
#include <QPainter>
#include <QLabel>
#include <QStandardItemModel>
#include  <QItemSelectionModel>
#include <QStringListModel>
#include <QList>
#include "vote.h"
#include <iostream>
#include<iomanip>
#include <stdlib.h>
#include <cstring>
#include <cfloat>
QString finallc,finalint;
int finallcid;
QStringList list6;
QMap<int,int>vidlist1,vidlist2;
extern QString uniname,int1,int2,int3,uniid,profilenum,urlnow,xcode,ycode;
extern int vidnow;

rec1 content;
rec2 location;
#define PRESCION 0.0001
using namespace std;
//零点定理and二分法开平方
template<typename T>
T sqrt2(T c)
{
    if(c==0.0)return 0;
    T a = 0,b = c+0.25;
    T m;
    while(1)
    {
        //取区间[a,b]的中点
        m = (a+b)/2;
        //控制精度退出
        if(b - m < PRESCION||m - a <PRESCION)
            break;
        //选择区间
        if((m*m - c)*(b*b - c)<0)
            a = m;
        else
            b = m;
    }
    return m;
}


struct selected{int vid;int vi1;int vi2;double similarity;int gra;QString name;}pre[1000];
bool cmp(selected a,selected b)
    {
        if(a.similarity!=b.similarity)
            return a.similarity>b.similarity;
            return a.gra>=b.gra;
    }

void rec1::creat(QString a,QString b,QString c)
{

    int i1=a.toInt();
    int i2=b.toInt();
    int i3=c.toInt();
    qDebug()<<"内容推荐计算开始"<<i1<<" "<<i2<<" "<<i3;
    QSqlQuery query;
    QString select = QString("select * from watch where mode = 0 OR mode=1 ;");
    query.exec(select);
    int i=0;//i计算符合条件条目数量
    while(query.next())
    {
        int vid=query.value(3).toInt();
        int vi1=query.value(25).toInt();
        int vi2=query.value(26).toInt();
        int gra=query.value(28).toInt();
        if(vi1==i1||vi1==i2||vi1==i3||vi2==i1||vi2==i2||vi2==i3){
        pre[i].vid=vid;
        pre[i].gra=gra;
        pre[i].vi1=vi1;
        pre[i].name=query.value(0).toString();
        pre[i++].vi2=vi2;
        qDebug()<<"vid:"<<vid<<"重合条目+1，其兴趣排位"<<vi1<<vi2<<"推荐分为"<<gra;
        }

    }
    qDebug()<<"有重合条目数量为"<<i;
    //相似度计算
    i-=1;
    for(int j=i;j>=0;j--){
        double a,b,c;
        if(pre[j].vi1==i1&&pre[j].vi2==i2){a=2.0;b=1.0;c=0;}else
        if(pre[j].vi2==i1&&pre[j].vi1==i2){a=1.0;b=2.0;c=0;}else
        if(pre[j].vi1==i3&&pre[j].vi2==i1){a=1.0;b=0;c=2.0;}else
        if(pre[j].vi2==i1&&pre[j].vi1==i3){a=2.0;b=0;c=1.0;}else
        if(pre[j].vi1==i3&&pre[j].vi2==i2){a=0;b=1.0;c=2.0;}else
        if(pre[j].vi2==i3&&pre[j].vi1==i2){a=0;b=2.0;c=1.0;}else {
            if(pre[j].vi1==i1){a=2.0;b=0;c=0;}
            if(pre[j].vi1==i2){a=0;b=2.0;c=0;}
            if(pre[j].vi1==i2){a=0;b=0;c=2.0;}
            if(pre[j].vi2==i1){a=1.0;b=0;c=0;}
            if(pre[j].vi2==i2){a=0;b=1.0;c=0;}
            if(pre[j].vi2==i2){a=0;b=0;c=1.0;}
}


        pre[j].similarity=1/(1.0+sqrt((a-2.0)*(a-2.0)+(b-1.0)*(b-1.0)+(c-0.5)*(c-0.5)));
    }
    for(int j=i;j>=0;j--){
        qDebug()<<"vid为"<<pre[j].vid<<"的条目与用户的兴趣相似度为"<<pre[j].similarity<<"其兴趣为"<<pre[j].vi1<<pre[j].vi2;
    }

    sort(pre,pre+i+1,cmp);
    vidnow=pre[0].vid;
    qDebug()<<"基于内容的推荐最终选择了"<<vidnow;
    urlnow=QString("http://localhost/gwnb/chart.php?vid=%1")
            .arg(vidnow);
    finalint=pre[0].name;

}
void rec2::creat(QString x,QString y)
{
    double xc=x.toDouble();
    double yc=y.toDouble();
    qDebug()<<"位置推荐计算开始"<<xc<<" "<<yc;
    QSqlQuery query;
    QString select = QString("select * from watch where mode = 0 ;");
    QString temp;
    query.exec(select);
    int vid=0;
    double distance=1000;
    while(query.next())
    {
           int tvid=query.value(3).toInt();
           double tdistance=pow((xc-query.value(23).toDouble()),2)+pow((yc-query.value(24).toDouble()),2);
           if(tdistance<distance)
           {
               temp=query.value(0).toString();
               distance=tdistance;
               vid=tvid;
               qDebug()<<vid<<"号的距离为"<<distance;

           }
     }
     finallc = QString("距离%1 %2")
             .arg(sqrt2(distance))
             .arg(temp);
     finallcid=vid;
     qDebug()<<finallc;

}



index::index(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::index)
{
    this->setWindowFlags(Qt::WindowCloseButtonHint|Qt::WindowMinimizeButtonHint|Qt::FramelessWindowHint);
    ui->setupUi(this);

    QString styleSheet = QString("QPushButton{border-image:url(%2); background-color:transparent;border: none; }"  //正常
                                 "QPushButton:hover{border-image:url(%1); background-color:transparent; }")
            .arg(":/resource/BUTTON.png")
            .arg(":/resource/Afterclap-1.png");
    ui->pushButton->setStyleSheet(styleSheet);
    srand((unsigned)time( NULL ));
    int r=rand()%6;
    qDebug()<<"随机图为："<<r;
    QString styleSheet1 = QString("border-image: url(:/resource/%1.jpg);")
            .arg(r);
    ui->label_18->setStyleSheet(styleSheet1);
    model=new QStringListModel(this);
    QStringList list;


}
void index::changename()
{

    content.creat(int1,int2,int3);
    location.creat(xcode,ycode);
    ui->textBrowser->setText(finallc);
    ui->textBrowser_2->setText(finalint);
    QString styleSheet=QString("QPushButton{border-image:url(:/resource/Afterclap-%2.png); background-color:transparent;border: none; }"  //正常
                               "QPushButton:hover{border-image:url(%1); background-color:transparent; }")
            .arg(":/resource/BUTTON.png")
            .arg(profilenum);
    ui->label_6->setText(uniname);
    ui->pushButton->setStyleSheet(styleSheet);


    QSqlQuery query;
    QString select = QString("select * from watch where creater = '%1';")
            .arg(uniname);
        query.exec(select);
        vidlist2.clear();
        list6.clear();
        int i=0;
        while(query.next())
        {
           int id = query.value(3).toInt();
           QString name = query.value(0).toString();
           qDebug() << id << name;
           QString insert = QString("vid-%1 %2")
                   .arg(id)
                   .arg(name);
           list6 <<insert;
           vidlist2.insert(i++,id);
           model->setStringList(list6);
           ui->listView_2->setModel(model);
           ui->listView_2->setEditTriggers(QAbstractItemView::AnyKeyPressed);
        }

        QSqlQuery query1;
        int maxgrade=0,maxvid;
        QString maxname;
        QString select1 = QString("select * from watch where mode = 0 OR mode = 1;");
            query1.exec(select1);
            while(query1.next())
            {
               int id = query1.value(3).toInt();
               int grade = query1.value(28).toInt();
               if(grade>maxgrade&&grade<100){
                   maxgrade=grade;
                   maxvid=id;
                   maxname=query1.value(0).toString();
                   qDebug() <<"最大推荐分推荐预选"<<id <<grade<< maxname;
               }
            }

        ui->label_19->setText(maxname);
        QString idlayout=QString::number(maxvid,10);
        QString finallayout = QString("The vid is now %1")
                .arg(idlayout);
        ui->label_20->setText(finallayout);


}
index::~index()
{
    delete ui;
}

void index::on_pushButton_released()
{
    Dialog www;
    www.setWindowFlags(Qt::WindowCloseButtonHint|Qt::WindowMinimizeButtonHint|Qt::FramelessWindowHint);
    QObject::connect(&www, &Dialog::newnum, this, &index::changename);
    www.exec();




}




void index::on_cretnew_released()
{
    upload *form=new upload;
    form->show();
    connect(form,&upload::finish,this,&index::changename);
}
void index::on_cretnew_clicked()
{

}

void index::on_pushButton_2_released()
{
    Diainfo wwww;
    wwww.show();
    connect(&wwww,&Diainfo::ok,this,&index::changename);
    connect(&wwww,&Diainfo::relogin,this,&QWidget::close);
    wwww.exec();
}

void index::on_pushButton_2_pressed()
{

}

void index::on_pushButton_2_clicked()
{

}

void index::on_listView_doubleClicked(const QModelIndex &index)
{

    qDebug()<<index.row();
    int choose=index.row();
    qDebug()<<vidlist1[choose];
    urlnow=QString("http://localhost/gwnb/chart.php?vid=%1")
            .arg(vidlist1[choose]);
    vidnow=vidlist1[choose];
    vote *test=new vote();
    test->show();

}

using namespace std;
bool isNumeric(string str)
{
    auto it = str.begin();
    while (it != str.end() &&isdigit(*it)) {
        it++;
    }
    return !str.empty() && it == str.end();
}

void index::on_pushButton_3_released()
{
    QString temp=ui->lineEdit->text(),aim;
    string search=temp.toStdString();
    if(isNumeric(search)){
        qDebug()<<"搜素id";
        aim="id";
    }else{
        qDebug()<<"搜素title";
        aim="title";
    }

    QSqlQuery query;
    QString select = QString("select * from watch where %2 = '%1';")
            .arg(temp)
            .arg(aim);
        query.exec(select);
        vidlist1.clear();
        int n=0;
        while(query.next())
        {
           int id = query.value(3).toInt();
           QString name = query.value(0).toString();
           qDebug() << id << name;
           QString insert = QString("vid-%1 %2")
                   .arg(id)
                   .arg(name);
           QStringList list1;
           vidlist1.insert(n++,id);
           list1 <<insert;
           model1=new QStringListModel(this);
           model1->setStringList(list1);
           ui->listView->setModel(model1);
           ui->listView->setEditTriggers(QAbstractItemView::AnyKeyPressed);
        }
}

void index::on_listView_2_doubleClicked(const QModelIndex &index)
{
    qDebug()<<index.row();
    int choose=index.row();
    qDebug()<<vidlist2[choose];
    urlnow=QString("http://localhost/gwnb/chart.php?vid=%1")
            .arg(vidlist2[choose]);
    vidnow=vidlist2[choose];
    vote *test=new vote();
    test->show();

}

void index::on_lineEdit_editingFinished()
{
    index::on_pushButton_3_released();
}

void index::on_pushButton_4_released()
{
    urlnow=QString("http://localhost/gwnb/chart.php?vid=%1")
            .arg(finallcid);
    vidnow=finallcid;
    vote *test=new vote();
    test->show();

}

void index::on_pushButton_6_released()
{
    changename();
}

void index::on_pushButton_5_released()
{
    vote *test=new vote();
    test->show();
}
