#-------------------------------------------------
#
# Project created by QtCreator 2023-12-05T09:48:26
#
#-------------------------------------------------

QT       += core gui network
QT += gui  widgets

TARGET = chat_client
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        widget.cpp \
    chatlist.cpp \
    addfriend.cpp \
    privatechat.cpp \
    creategroup.cpp \
    addgroup.cpp \
    groupchat.cpp \
    sendfile.cpp

HEADERS  += widget.h \
    chatlist.h \
    addfriend.h \
    privatechat.h \
    creategroup.h \
    addgroup.h \
    groupchat.h \
    sendfile.h

FORMS    += widget.ui \
    chatlist.ui \
    addfriend.ui \
    privatechat.ui \
    creategroup.ui \
    addgroup.ui \
    groupchat.ui
