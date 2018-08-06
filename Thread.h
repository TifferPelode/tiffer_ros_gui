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

class Update_param : public QObject {
    Q_OBJECT
public:
    Update_param() {}
    ~Update_param() {}

    double linear_speed;
    double angle_speed;

public slots:
    void do_update();

signals:
    void update_param_signal(double, double);
};
#endif // THREAD_H
