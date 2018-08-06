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

void Update_param::do_update()
{
    linear_speed = 12.3451;
    angle_speed = 67.8901;
    qDebug() << "update param signal is called";
    emit update_param_signal(linear_speed, angle_speed);
}
