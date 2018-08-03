#include "tifferpelode.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ros::init(argc, argv, "Tiffer_ROS_GUI");

    TifferPelode w;
    w.show();

    return a.exec();
}
