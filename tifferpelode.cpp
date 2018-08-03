#include "tifferpelode.h"
#include "ui_tifferpelode.h"

TifferPelode::TifferPelode(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TifferPelode)
{
    ui->setupUi(this);

    my = new Mul_thread();
    me = new Mul_thread();

    thread1 = new QThread();
    thread2 = new QThread();

    my->moveToThread(thread1);
    me->moveToThread(thread2);

    connect(ui->pb1, SIGNAL(clicked()), my, SLOT(first()));//, Qt::QueuedConnection);
    connect(ui->pb2, SIGNAL(clicked()), me, SLOT(second()));//, Qt::QueuedConnection);
    connect(ui->pb3, SIGNAL(clicked()), me, SLOT(third()));//, Qt::QueuedConnection);
    connect(ui->getCLocation, SIGNAL(clicked()), this, SLOT(getCurrentLocation(geometry_msgs::Pose &pose)));

    thread1->start();
    thread2->start();
    //connect(thread2, SIGNAL(started()), me, SLOT(third()));

}

TifferPelode::~TifferPelode()
{
    me->m_flag = false;
    delete ui;

    thread1->exit(0);
    thread2->exit(0);
    thread1->wait();
    thread2->wait();
    thread1->deleteLater();
    thread2->deleteLater();
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

void TifferPelode::finishedThing()
{
    qDebug() << "finished";
}

void TifferPelode::getCurrentLocation(geometry_msgs::Pose &pose)
{
    tf::TransformListener listener;
    tf::StampedTransform transform;

    try{
        listener.waitForTransform("/map", "/base_link", ros::Time::now(), ros::Duration(2));
        listener.lookupTransform("/map", "/base_link", ros::Time(0), transform);
    } catch (tf::TransformException ex){
        ROS_ERROR("%s", ex.what());
        ros::Duration(1.0).sleep();
        return ;
    }

    geometry_msgs::Transform tt;
    tf::transformTFToMsg(transform, tt);
    pose.position.x = tt.translation.x;
    pose.position.y = tt.translation.y;
    pose.position.z = tt.translation.z;
    pose.orientation.x = tt.rotation.x;
    pose.orientation.y = tt.rotation.y;
    pose.orientation.z = tt.rotation.z;
    pose.orientation.w = tt.rotation.w;

    tt = ts_.transform;

    qDebug() << tt.translation.x;
    qDebug() << tt.translation.y;
    qDebug() << tt.translation.z;
    qDebug() << tt.rotation.x;
    qDebug() << tt.rotation.y;
    qDebug() << tt.rotation.z;
    qDebug() << tt.rotation.w;
}
