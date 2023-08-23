#include "mainwindow.h"
#include "index.h"
#include "diainfo.h"
#include "vote.h"
#include <QApplication>
#include <QMessageBox>
#include <QDebug>
QString urlnow,uniname,int1,int2,int3,uniid,profilenum,xcode,ycode,city="未获取",ip;
int vidnow;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    index ww;
    Diainfo ipconfig;
    ww.show();
    w.show();
    QObject::connect(&w, &MainWindow::go, &ww,&index::changename);
    QObject::connect(&w, &MainWindow::ipready, &ipconfig, &Diainfo::autoip);




    return a.exec();
}
