#include "tifferpelode.h"
#include "ui_tifferpelode.h"

TifferPelode::TifferPelode(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TifferPelode)
{
    ui->setupUi(this);

    obj1 = new Mul_thread();
    obj2 = new Mul_thread();
    obj3 = new Update_param();

    thread1_ = new QThread();
    thread2_ = new QThread();
    thread3_ = new QThread();

    obj1->moveToThread(thread1_);
    obj2->moveToThread(thread2_);
    obj3->moveToThread(thread3_);

    connect(ui->pb1, SIGNAL(clicked()), obj1, SLOT(first()));//, Qt::QueuedConnection);
    connect(ui->pb2, SIGNAL(clicked()), obj2, SLOT(second()));//, Qt::QueuedConnection);
    connect(ui->pb3, SIGNAL(clicked()), obj3, SLOT(do_update()));//, Qt::QueuedConnection);
    connect(ui->getLocation, SIGNAL(clicked()), this, SLOT());
    connect(obj3, SIGNAL(update_param_signal(double, double)), this, SLOT(update_param_slot(double, double)));

    thread1_->start();
    thread2_->start();
    thread3_->start();

    //ui->frame_2->hide();

//    QPixmap pixmap = QPixmap(":/bg/bg2.jpg");
//    QPalette pa(this->palette());
//    pa.setBrush(QPalette::Background, QBrush(pixmap));
//    setPalette(pa);
    setWindowOpacity(0.75);
    setAutoFillBackground(true);

}

TifferPelode::~TifferPelode()
{
    delete ui;

    thread1_->exit(0);
    thread2_->exit(0);
    thread3_->exit(0);
    thread1_->wait();
    thread2_->wait();
    thread3_->wait();
    thread1_->deleteLater();
    thread2_->deleteLater();
    thread3_->deleteLater();
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

void TifferPelode::update_param_slot(double linear, double angle)
{
    ui->angle_speed_label->setText(QString::number(angle, 10, 4));
    ui->linear_speed_label->setText(QString::number(linear, 10, 4));
    ui->battery_progressBar->setValue(80);
}
