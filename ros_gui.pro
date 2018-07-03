#-------------------------------------------------
#
# Project created by QtCreator 2018-06-25T15:54:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ros_gui
TEMPLATE = app
CONFIG += c++11 console

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
DEFINES += BOOST_USE_LIB

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        tifferpelode.cpp

HEADERS += \
        tifferpelode.h \
    aaa.h

FORMS += \
        tifferpelode.ui

INCLUDEPATH += -I /opt/ros/kinetic/include
INCLUDEPATH += -I /usr/include/boost

DEPENDPATH +=  /opt/ros/kinetic/include

unix:!macx: LIBS += -L /opt/ros/kinetic/lib -lroscpp
unix:!macx: LIBS += -L /opt/ros/kinetic/lib -lroslib
unix:!macx: LIBS += -L /opt/ros/kinetic/lib -lactionlib
unix:!macx: LIBS += -L /opt/ros/kinetic/lib -ltf
unix:!macx: LIBS += -L /opt/ros/kinetic/lib -ltf2
unix:!macx: LIBS += -L /opt/ros/kinetic/lib -ltf2_ros
unix:!macx: LIBS += -L /opt/ros/kinetic/lib -lpthread
unix:!macx: LIBS += -L /opt/ros/kinetic/lib -lroscpp_serialization
unix:!macx: LIBS += -L /opt/ros/kinetic/lib -lrostime
unix:!macx: LIBS += -L /opt/ros/kinetic/lib -lrosconsole
unix:!macx: LIBS += -L /opt/ros/kinetic/lib -lrosconsole_log4cxx
unix:!macx: LIBS += -L /opt/ros/kinetic/lib -lrosconsole_backend_interface
unix:!macx: LIBS += -L /opt/ros/kinetic/lib -lxmlrpcpp

LIBS += -L /opt/ros/kinetic/lib -lcpp_common

LIBS += /usr/lib/x86_64-linux-gnu/libboost_thread.a
LIBS += /usr/lib/x86_64-linux-gnu/libboost_system.a
