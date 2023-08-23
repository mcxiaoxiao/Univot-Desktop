#ifndef UPLOAD_H
#define UPLOAD_H
#include <QtSql/QSqlDatabase>
#include <QSqlQuery>
#include <QWidget>

namespace Ui {
class upload;
}

class upload : public QWidget
{
    Q_OBJECT

public:
    explicit upload(QWidget *parent = nullptr);
    ~upload();

signals:
    void finish();

private slots:
    void on_comboBox_currentIndexChanged(int index);

    void on_pushButton_2_released();

    void on_comboBox_3_currentIndexChanged(const QString &arg1);

    void on_comboBox_3_currentTextChanged(const QString &arg1);

    void on_comboBox_3_currentIndexChanged(int index);

    void on_pushButton_2_clicked();

    void on_pushButton_2_clicked(bool checked);

    void on_pushButton_2_pressed();

    void on_pushButton_released();

private:
    Ui::upload *ui;
};

#endif // UPLOAD_H
