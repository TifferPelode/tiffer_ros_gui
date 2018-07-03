#ifndef AAA_H
#define AAA_H
#include "tifferpelode.h"

#include <QObject>
#include <QThread>
#include <QDebug>

class Test_tiffer : public QObject {
    Q_OBJECT
public:
    Test_tiffer() {}
    ~Test_tiffer() {}



public slots:
    void first() {
        //qDebug() << QThread::currentThreadId();
        qDebug() << "first: ";
        for(int i = 0; i < 3; i++){
            qDebug() << "aaa";
            QThread::sleep(1);
        }
    }
    void second() {
        //qDebug() << QThread::currentThreadId();
        qDebug() << "second: ";
        for(int i = 0; i < 3; i++){
            qDebug() << "bbb";
            QThread::sleep(1);
        }
    }
    void third() {
        //qDebug() << QThread::currentThreadId();
        qDebug() << "third: ";

    }
};
#endif // AAA_H
