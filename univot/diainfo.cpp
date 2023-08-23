//.cpp

#include "diainfo.h"
#include "ui_diainfo.h"
#include<QMessageBox>
#include<QNetworkAccessManager>
#include<QHostInfo>
#include<QNetworkReply>
#include<QNetworkRequest>
#include<QJsonDocument>
#include<QJsonObject>
#include<QJsonParseError>
#include<QDebug>
extern QString uniid,uniname,xcode,ycode,city,ip;
const static QString AK_STR="RQ0w2vZvAPRFuyG7ZQIbKMLHMcXr6Gr2";


Diainfo::Diainfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Diainfo),
    m_pNet(new QNetworkAccessManager(this))
{

    ui->setupUi(this);
    this->setWindowFlags(windowFlags()^Qt::WindowContextHelpButtonHint);
    this->setWindowTitle(QStringLiteral("UniVot info"));
    ui->plainTextEdit->setEnabled(false);
    ui->lineEdit->setText(ip);
    QString text;
    text=   QString("您的uniid为 %1，您的username为 %2")
            .arg(uniid)
            .arg(uniname);
    ui->label_14->setText(text);
}

Diainfo::~ Diainfo()
{
    delete ui;
}

void Diainfo::on_queryButton_clicked()
{
    const QString txt=ui->lineEdit->text();
    if(txt==""){
        QMessageBox::warning(this,QStringLiteral("提示"),QStringLiteral("请输入IP地址或域名！"));
        return;
    }
    ui->plainTextEdit->clear();
    QHostInfo::lookupHost(txt,this,SLOT(onHostLookedUp(QHostInfo)));
}

void Diainfo::onHostLookedUp(const QHostInfo &host)
{
    if(host.error()!=QHostInfo::NoError){
        QMessageBox::information(this,QStringLiteral("提示"),host.errorString());
        return;
    }
    QList<QHostAddress> adds = host.addresses();
    if(adds.size()){
        const QHostAddress& addr = adds.first();
        queryLocationOfIP(addr.toString());
        qDebug()<<addr.toString();
        ui->progress->setValue(30);


    }
}

void Diainfo::queryLocationOfIP(const QString &strIp)
{
    const QString& strUrl=QString("http://api.map.baidu.com/location/ip?ak=%1&ip=%2&coor=bd09ll").
            arg(AK_STR).arg(strIp);

    QNetworkRequest request;
    request.setHeader(QNetworkRequest::ContentTypeHeader,"application/json");
    request.setUrl(QUrl(strUrl));

    QNetworkReply* reply =m_pNet->get(request);
    connect(reply,SIGNAL(finished()),this,SLOT(replyFinished()));
    ui->progress->setValue(50);

}

void Diainfo::replyFinished()
{
    QNetworkReply* reply=qobject_cast<QNetworkReply *>(sender());

    if(reply->error()!=QNetworkReply::NoError){
        QMessageBox::information(this,QStringLiteral("提示"),QStringLiteral("请求出错:%1").arg(reply->errorString()));
    }
    const QByteArray& bytes=reply->readAll();
    const QVariantMap& varMap=parseLocationData(bytes);
    ui->progress->setValue(80);
    showLocation(varMap);

    reply->deleteLater();
}

QVariantMap Diainfo::parseLocationData(const QByteArray &data)
{
    QJsonParseError error;
    QJsonDocument doc=QJsonDocument::fromJson(data,&error);
    ui->progress->setValue(90);
    if(error.error!=QJsonParseError::NoError){
        QMessageBox::information(this,QStringLiteral("提示"),QStringLiteral("JSON:数据结构有问题！"));
        return QVariantMap();
    }
    QJsonObject obj=doc.object();
    int status=obj.value("status").toInt();
    if(status!=0){
        QMessageBox::information(this,QStringLiteral("提示"),QStringLiteral("状态码：%1").arg(status));
        return QVariantMap();
    }
    QJsonObject contentObj=obj.value("content").toObject();
    qDebug()<<contentObj.value("address").toString();
    return contentObj.toVariantMap();
}

void Diainfo::showLocation(const QVariantMap &varMap)
{
    const QString& addrStr=varMap.value("address").toString();
    const QVariantMap& ptMap=varMap.value("point").toMap() ;
    const QString& longitudeStr=ptMap.value("x").toString();
    const QString& latitudeStr=ptMap.value("y").toString();
    const QString& txt=QStringLiteral("城市：%1 \n经度：%2   纬度：%3").arg(addrStr).arg(longitudeStr).arg(latitudeStr);
    ui->plainTextEdit->setPlainText(txt);
    city=addrStr;
    xcode=longitudeStr;
    ycode=latitudeStr;
    ui->progress->setValue(100);
    qDebug()<<xcode;
    qDebug()<<ycode;
}

void Diainfo::on_plainTextEdit_blockCountChanged(int newBlockCount)
{

}

void Diainfo::on_pushButton_3_released()
{
    emit this->relogin();
    this->close();
}

void Diainfo::on_queryButton_released()
{
    ui->progress->setValue(0);
}
void Diainfo::autoip()
{
QHostInfo::lookupHost(ip,this,SLOT(onHostLookedUp(QHostInfo)));
}

void Diainfo::on_pushButton_2_released()
{
    this->close();
}

void Diainfo::on_pushButton_released()
{
    this->ok();
    this->close();
}
