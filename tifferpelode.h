#ifndef TIFFERPELODE_H
#define TIFFERPELODE_H

#include <QMainWindow>

//#ifdef Q_MOC_RUN

#include <ros/ros.h>
#include <ros/package.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <std_msgs/String.h>
//#include <tf/transform_listener.h>
#include <tf/transform_datatypes.h>
//#include <tf2_ros/transform_listener.h>
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/PoseStamped.h>
#include <actionlib_msgs/GoalID.h>
//#include <actionlib/client/simple_action_client.h>
#include <nav_msgs/Odometry.h>
#include <nav_msgs/Path.h>
#include <std_srvs/Empty.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <std_msgs/Bool.h>

//#endif

namespace Ui {
class TifferPelode;
}

class TifferPelode : public QMainWindow
{
    Q_OBJECT

public:
    explicit TifferPelode(QWidget *parent = 0);
    ~TifferPelode();

private:
    Ui::TifferPelode *ui;

    ros::NodeHandle nh_;
    ros::Publisher chatter_pub_;

    void pub_message();
};

#endif // TIFFERPELODE_H
