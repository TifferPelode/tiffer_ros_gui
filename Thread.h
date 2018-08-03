#ifndef THREAD_H
#define THREAD_H

#include <QObject>
#include <QThread>
#include <QDebug>

class Mul_thread : public QObject {
    Q_OBJECT
public:
    Mul_thread() {}
    ~Mul_thread() {}

    bool m_flag;

public slots:
    void first() {
        qDebug() << QThread::currentThreadId();
        qDebug() << "first: ";
        for(int i = 0; i < 3; i++){
            qDebug() << "aaa";
            QThread::sleep(1);
        }
    }
    void second() {
        qDebug() << QThread::currentThreadId();
        qDebug() << "second: ";

        for(int i = 0; i < 3; i++){
            qDebug() << "bbb";
            QThread::sleep(1);
        }
    }
    void third() {
        qDebug() << QThread::currentThreadId();
        qDebug() << "third: ";

        qDebug() << "third exit";
    }
};
#endif // THREAD_H
