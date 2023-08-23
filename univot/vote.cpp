#include "vote.h"
#include "ui_vote.h"
#include <QAxWidget>
#include <QDebug>
#include <QSqlQuery>
extern QString uniname,int1,int2,int3,uniid,profilenum,urlnow,xcode,ycode;
extern int vidnow;
bool yon=false;
vote::vote(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::vote)
{
    qDebug()<<"目前打开的vid为"<<vidnow<<"即将上传,上传之前的个人兴趣为"<<int1<<int2<<int3;
    ui->setupUi(this);
    this->setWindowFlags(Qt::WindowCloseButtonHint);
    this->setWindowTitle(QStringLiteral("投票详情"));
    QString webStr = urlnow;
    this->ui->axWidget->setControl(QString::fromUtf8("{8856F961-340A-11D0-A96B-00C04FD705A2}"));//注册组件ID
    this->ui->axWidget->setProperty("DisplayAlerts",false);//不显示警告信息
    this->ui->axWidget->setProperty("DisplayScrollBars",true);//不显示滚动条
    this->ui->axWidget->dynamicCall("Navigate(const QString&)",webStr);//显示网页
    ui->axWidget->dynamicCall("Navigate(const QString&)",webStr);
    //获取习惯
    QSqlQuery query;
    QString the[2];
    QString select = QString("select * from watch where id = %1 ;").arg(vidnow);
    query.exec(select);
    while(query.next())
    {
         the[0]=query.value(25).toString();
         the[1]=query.value(26).toString();
    }
    qDebug()<<"当前页面兴趣为"<<the[0]<<"和"<<the[1];
    //浏览记录排序
    //情况：第一次浏览
    if(int1=="0"&&int2=="0"&&int3=="0")
    {
        int1=the[0];
        int2=the[1];
        int3="14";//可用于浅浅影响刚开始的推荐
    }
    if(the[0]=="0")
    //情况：若两项新兴趣与原先三兴趣重合则直接保送第一位,原先所有后退一位
    for (int i=1;i>=0;i--) {
        if(the[i]==int1){
            int1=the[i];
            int3=int2;
            int2=int1;
            yon=true;
            qDebug()<<"出现重合";
        }
    }
    //情况：其他情况
    if(!yon){
        int2=the[0];
        int3=the[1];
    }



    qDebug()<<"为用户"<<uniname<<"即将上传的新个人兴趣为"<<int1<<int2<<int3;
    QString changeint = QString("UPDATE `univot`.`user` SET `interst1`=%2, `interst2`=%3, `interst3`=%4 WHERE  `name`='%1' ;")
            .arg(uniname)
            .arg(int1)
            .arg(int2)
            .arg(int3);

    if(query.exec(changeint) == true)
    {
        qDebug()<<"上传成功";
    }


}

vote::~vote()
{
    delete ui;
}


