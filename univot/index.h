#ifndef INDEX_H
#define INDEX_H
#include <QObject>
#include <QStringListModel>
#include <QWidget>

namespace Ui {
class index;
}

class index : public QWidget
{
    Q_OBJECT

public:

    void changename();
    explicit index(QWidget *parent = nullptr);
    ~index();

private slots:
    void on_pushButton_released();


    void on_pushButton_2_released();

    void on_pushButton_2_clicked();

    void on_cretnew_clicked();

    void on_cretnew_released();

    void on_pushButton_2_pressed();

    void on_listView_doubleClicked(const QModelIndex &index);

    void on_pushButton_3_released();

    void on_listView_2_doubleClicked(const QModelIndex &index);

    void on_lineEdit_editingFinished();


    void on_pushButton_4_released();

    void on_pushButton_6_released();

    void on_pushButton_5_released();

public:
    Ui::index *ui;
    QStringListModel *model;
    QStringListModel *model1;
};

class rec1
{
public:
    virtual void creat(QString,QString,QString);
};
class rec2:public rec1
{
public:
    virtual void creat(QString,QString);
};

#endif // INDEX_H
