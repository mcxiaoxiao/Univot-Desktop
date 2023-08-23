#ifndef VOTE_H
#define VOTE_H
#include<bits/stdc++.h>
#include <QWidget>
class QNetworkReply;
class QNetworkAccessManager;

namespace Ui {
class vote;
}

class vote : public QWidget
{
    Q_OBJECT

public:
    explicit vote(QWidget *parent = nullptr);
    ~vote();

private:
    Ui::vote *ui;


private slots:

};

#endif // VOTE_H
