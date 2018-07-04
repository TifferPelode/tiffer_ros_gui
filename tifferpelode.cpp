#include "tifferpelode.h"
#include "ui_tifferpelode.h"

TifferPelode::TifferPelode(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TifferPelode)
{
    ui->setupUi(this);

    //chatter_pub_ = nh_.advertise<std_msgs::String>("chatter", 1000);
    //pub_message();



    Test_tiffer *my = new Test_tiffer();
    Test_tiffer *me = new Test_tiffer();

    connect(ui->pb1, SIGNAL(clicked()), my, SLOT(first()));//, Qt::QueuedConnection);
    connect(ui->pb2, SIGNAL(clicked()), me, SLOT(second()));//, Qt::QueuedConnection);
    //connect(ui->pb3, SIGNAL(clicked()), me, SLOT(third()));//, Qt::QueuedConnection);
    connect(ui->testButton, SIGNAL(clicked()), this, SLOT(testTf2()));
    connect(ui->getCLocation, SIGNAL(clicked()), this, SLOT(getCurrentLocation()));

    thread1 = new QThread();
    thread2 = new QThread();

    my->moveToThread(thread1);
    me->moveToThread(thread2);

    thread1->start();
    thread2->start();
    connect(thread2, SIGNAL(started()), me, SLOT(third()));


}

TifferPelode::~TifferPelode()
{
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

void TifferPelode::testTf2()
{
    geometry_msgs::Pose new_pose;
    //getLocation(new_pose);

//    qDebug() << new_pose.position.x;
//    qDebug() << new_pose.position.y;
//    qDebug() << new_pose.position.z;
//    qDebug() << new_pose.orientation.x;
//    qDebug() << new_pose.orientation.y;
//    qDebug() << new_pose.orientation.z;
//    qDebug() << new_pose.orientation.w;

    qDebug() << QThread::currentThreadId();
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

    tt = ts.transform;

    qDebug() << tt.translation.x;
    qDebug() << tt.translation.y;
    qDebug() << tt.translation.z;
    qDebug() << tt.rotation.x;
    qDebug() << tt.rotation.y;
    qDebug() << tt.rotation.z;
    qDebug() << tt.rotation.w;
}
