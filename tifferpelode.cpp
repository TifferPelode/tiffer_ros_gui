#include "tifferpelode.h"
#include "ui_tifferpelode.h"

TifferPelode::TifferPelode(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TifferPelode)
{
    ui->setupUi(this);

    chatter_pub_ = nh_.advertise<std_msgs::String>("chatter", 1000);
    //pub_message();
}

TifferPelode::~TifferPelode()
{
    delete ui;
}

void TifferPelode::pub_message()
{
    ros::Rate loop_rate(1);

    int cnt = 0;

    while(ros::ok()){
        std_msgs::String msg;

        std::stringstream ss;
        ss << "hello world " << cnt;
        msg.data = ss.str();

        ROS_INFO("%s", msg.data.c_str());

        chatter_pub_.publish(msg);

        ros::spinOnce();

        loop_rate.sleep();
        ++cnt;
    }
}
