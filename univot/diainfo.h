#ifndef DIAINFO_H
#define DIAINFO_H
#include <QDialog>

class QHostInfo;
class QNetworkAccessManager;

namespace Ui {
class Diainfo;
}

class Diainfo : public QDialog
{
    Q_OBJECT

public:
    explicit Diainfo(QWidget *parent = 0);
    ~Diainfo();
signals:
    void relogin();
    void ok();
public slots:
    void on_queryButton_clicked();
    void onHostLookedUp(const QHostInfo &host);
    void queryLocationOfIP(const QString& strIp);
    void replyFinished();
    void on_plainTextEdit_blockCountChanged(int newBlockCount);
    void autoip();
    void on_pushButton_3_released();
    void on_queryButton_released();

private slots:
    void on_pushButton_2_released();
    void on_pushButton_released();

private:
    QVariantMap parseLocationData(const QByteArray& data);
    void showLocation(const QVariantMap& varMap);

private:
    Ui::Diainfo *ui;
    QNetworkAccessManager* m_pNet;
};

#endif // DIALOG_H
