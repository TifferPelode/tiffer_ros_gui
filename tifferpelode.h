#ifndef TIFFERPELODE_H
#define TIFFERPELODE_H

#include "Thread.h"
#include "location_manager.h"

#include <QAudioInput>
#include <QAudioRecorder>
#include <QFile>
#include <QAudioEncoderSettings>
#include <QMainWindow>
#include <QThread>
#include <QDebug>
#include <QPalette>

#include <ros/ros.h>
#include <ros/package.h>
#include <tf/transform_listener.h>
#include <tf/transform_datatypes.h>
#include <tf2_ros/transform_listener.h>
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/PoseStamped.h>
#include <actionlib_msgs/GoalID.h>
#include <actionlib/client/simple_action_client.h>
#include <nav_msgs/Odometry.h>
#include <nav_msgs/Path.h>
#include <std_srvs/Empty.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <std_msgs/Bool.h>

#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <std_msgs/String.h>

namespace Ui {
class TifferPelode;
class Mul_thread;
class LocationManager;
}

class TifferPelode : public QMainWindow
{
    Q_OBJECT

public:

    explicit TifferPelode(QWidget *parent = 0);
    ~TifferPelode();

    Mul_thread *obj1;
    Mul_thread *obj2;
    Update_param *obj3;

public slots:
    void finishedThing();

    void update_param_slot(double, double);

private:
    Ui::TifferPelode *ui;

    ros::NodeHandle nh_;
    ros::Publisher chatter_pub_;
    geometry_msgs::TransformStamped ts_;
    LocationManagerPtr location_manager_;

    QThread *thread1_;
    QThread *thread2_;
    QThread *thread3_;

    void getCurrentLocation(geometry_msgs::Pose &pose);
    void pub_message();

};

#endif // TIFFERPELODE_H
