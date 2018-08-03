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
    void first();
    void second();
    void third();
};

class Do_something : public QObject {
    Q_OBJECT
public:
    Do_something() {}
    ~Do_something() {}

public slots:
    void do_one();

signals:
    void status();
};
#endif // THREAD_H
