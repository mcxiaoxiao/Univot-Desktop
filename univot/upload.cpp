#include "upload.h"
#include "ui_upload.h"
#include<qdebug.h>
#include <QCoreApplication>
#include <QMessageBox>
#include <QSqlRecord>
extern QString uniid,uniname,xcode,ycode,city,ip;
upload::upload(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::upload)
{

    ui->setupUi(this);
    ui->comboBox_3->addItems({"心理","宠物","娱乐","生活","时尚","美食","文学","学术","科学","工程","数码","科技","互联网","法律","经济","新闻","管理","学校","政治"});
    if(city!="")
        ui->comboBox_2->addItem(QString("公开(%1)").arg(city));
    ui->comboBox_2->addItem("公开但不提供位置");
    ui->comboBox_2->addItem("私密");
}

upload::~upload()
{
    delete ui;
}

void upload::on_comboBox_currentIndexChanged(int index)
{
    switch(index)
    {
    case 1:
        ui->A3->setEnabled(true);
        ui->A3->setText("");
        ui->A6->setEnabled(false);
        ui->A6->setText("未启用");
        ui->A5->setEnabled(false);
        ui->A5->setText("未启用");
        ui->A4->setEnabled(false);
        ui->A4->setText("未启用");
        break;
    case 2:
        ui->A3->setEnabled(true);
        ui->A3->setText("");
        ui->A4->setEnabled(true);
        ui->A4->setText("");
        ui->A5->setEnabled(false);
        ui->A5->setText("未启用");
        ui->A6->setEnabled(false);
        ui->A6->setText("未启用");
        break;
    case 3:
        ui->A3->setEnabled(true);
        ui->A3->setText("");
        ui->A4->setEnabled(true);
        ui->A4->setText("");
        ui->A5->setEnabled(true);
        ui->A5->setText("");
        ui->A6->setEnabled(false);
        ui->A6->setText("未启用");
        break;
    case 4:
        ui->A3->setEnabled(true);
        ui->A3->setText("");
        ui->A4->setEnabled(true);
        ui->A4->setText("");
        ui->A5->setEnabled(true);
        ui->A5->setText("");
        ui->A6->setEnabled(true);
        ui->A6->setText("");
        break;
    case 0:
        ui->A6->setEnabled(false);
        ui->A6->setText("未启用");
        ui->A5->setEnabled(false);
        ui->A5->setText("未启用");
        ui->A4->setEnabled(false);
        ui->A4->setText("未启用");
        ui->A3->setEnabled(false);
        ui->A3->setText("未启用");
        break;
    }
}

void upload::on_pushButton_2_released()
{
    this->hide();
}


void upload::on_comboBox_3_currentTextChanged(const QString &arg1)
{

}

void upload::on_comboBox_3_currentIndexChanged(const QString &arg1)
{

}

void upload::on_comboBox_3_currentIndexChanged(int index)
{
    QString temp;
    qDebug()<<index;
    QMap<int,QString>interst;
    QMap<int, QString>::iterator i;
    interst.insert(1,"情感");
    interst.insert(2,"心理");
    interst.insert(3,"宠物");
    interst.insert(4,"娱乐");
    interst.insert(5,"生活");
    interst.insert(6,"时尚");
    interst.insert(7,"美食");
    interst.insert(8,"文学");
    interst.insert(9,"学术");
    interst.insert(10,"科学");
    interst.insert(11,"工程");
    interst.insert(12,"数码");
    interst.insert(13,"科技");
    interst.insert(14,"互联网");
    interst.insert(15,"法律");
    interst.insert(16,"经济");
    interst.insert(17,"新闻");
    interst.insert(18,"管理");
    interst.insert(19,"学校");
    interst.insert(20,"政治");
    i=interst.find(index);
    qDebug()<<i.value();
    i.value()="已选择";
    for(i = interst.begin(); i!= interst.end(); i++){
        qDebug()<<i.key();
        temp=i.value();
        ui->comboBox_4->addItem(temp);
    }

}

void upload::on_pushButton_2_clicked()
{

}

void upload::on_pushButton_2_clicked(bool checked)
{

}

void upload::on_pushButton_2_pressed()
{

}

void upload::on_pushButton_released()
{
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
    QString name=ui->lineEdit->text();
    QSqlQuery sql(db);
    QSqlQuery query2 = QSqlQuery(db);
    query2.exec("SELECT * FROM univot.watch");
    QSqlRecord rec = query2.record();
    qDebug() << "表的行数：" << query2.size();
    int vid=query2.size()+1;
    int amo=ui->comboBox->currentIndex();
    amo+=2;
    qDebug() << "newid：" << vid;
    QString con=ui->textEdit->toPlainText();
    QString o1=ui->A1->text();
    QString o2=ui->A2->text();
    QString o3=ui->A3->text();
    QString o4=ui->A4->text();
    QString o5=ui->A5->text();
    QString o6=ui->A6->text();
    int mode=ui->comboBox_2->currentIndex();
    int int1=ui->comboBox_3->currentIndex();
    int int2=ui->comboBox_4->currentIndex();
    QString str_sql = QString("INSERT INTO `univot`.`watch` (`title`, `content`, `id`, `creater`, `option_amount`, `option1`, `option2`, `option3`, `option4`, `option5`, `option6`, `city`, `xcoe`, `ycode`, `interst1`, `interst2`) VALUES ('%1', '%2', %3, '%4', '%5', '%6', '%7', '%8', '%9', '%10', '%11', '%12', %13, %14, %15, %16);")
            .arg(name)
            .arg(con)
            .arg(vid)
            .arg(uniname)
            .arg(amo)
            .arg(o1)
            .arg(o2)
            .arg(o3)
            .arg(o4)
            .arg(o5)
            .arg(o6)
            .arg(city)
            .arg(xcode)
            .arg(ycode)
            .arg(int1)
            .arg(int2)
            ;
    if(sql.exec(str_sql) == true)qDebug()<<"加入成功";
    QString mes=QString("您的新建投票vid=%1"
                        "mode=%2").arg(vid).arg(mode);
    emit this->finish();
    QMessageBox MyBox(QMessageBox::Information,"提交完成",mes,QMessageBox::Ok);
    MyBox.exec();


}
