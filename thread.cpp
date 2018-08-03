#include "Thread.h"

void Mul_thread::first()
{
    qDebug() << QThread::currentThreadId();
    qDebug() << "first: ";
    for(int i = 0; i < 3; i++){
        qDebug() << "aaa";
        QThread::sleep(1);
    }
}

void Mul_thread::second()
{
    qDebug() << QThread::currentThreadId();
    qDebug() << "second: ";

    for(int i = 0; i < 3; i++){
        qDebug() << "bbb";
        QThread::sleep(1);
    }
}

void Mul_thread::third()
{
    qDebug() << QThread::currentThreadId();
    qDebug() << "third: ";

    qDebug() << "third exit";
}

void Do_something::do_one()
{
    qDebug() << QThread::currentThreadId();
    qDebug() << "do one";

    emit status();
}
