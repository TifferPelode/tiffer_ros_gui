#ifndef AAA_H
#define AAA_H
#include "tifferpelode.h"
#include "weChatMess_.hpp"

#include <lcm/lcm-cpp.hpp>

#include <QObject>
#include <QThread>
#include <QDebug>

class Handler
{
    public:
        ~Handler() {}

        void handleMessage(const lcm::ReceiveBuffer* rbuf,
                const std::string& chan,
                const Tiffer::weChatMess_* m)
        {
            printf("Received message on channel \"%s\":\n", chan.c_str());
            printf("msg :%s \n", m->msg.c_str());
        }
};

class Test_tiffer : public QObject {
    Q_OBJECT
public:
    Test_tiffer() {}
    ~Test_tiffer() {}

    bool flag = false;

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

        flag = false;

        for(int i = 0; i < 3; i++){
            qDebug() << "bbb";
            QThread::sleep(1);
        }
    }
    void third() {
        //qDebug() << QThread::currentThreadId();
        qDebug() << "third: ";

        lcm::LCM lcm;

        if(!lcm.good())
            qDebug() << "lcm not good!";

        Handler handlerObject;
        lcm.subscribe("Tiffer", &Handler::handleMessage, &handlerObject);

        flag = true;
        while(0 == lcm.handle() && flag != false);

        qDebug() << "third exit";
    }
};
#endif // AAA_H
