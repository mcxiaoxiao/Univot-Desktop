#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QSqlDatabase>
#include <QMainWindow>
#include <QtSql/QSqlDatabase>
#include<QNetworkAccessManager>
#include<QHostInfo>
#include<QNetworkReply>
#include<QNetworkRequest>
#include<QJsonDocument>
#include<QJsonObject>
#include<QJsonParseError>
#include <QSqlQuery>
#include <QDateTime>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

signals:
    void go();
    void ipready();
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void check();
public slots:
    void dealMsg(QNetworkReply*);
private slots:
    void on_lineEdit_editingFinished();

private:
    Ui::MainWindow *ui;
    QNetworkAccessManager* Net;
};

#endif // MAINWINDOW_H
