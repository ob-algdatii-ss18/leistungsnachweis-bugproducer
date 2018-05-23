#-------------------------------------------------
#
# Project created by QtCreator 2018-05-19T09:20:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Test2
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
    PlayGround.cpp \
    choosewindow.cpp \
    hidato4x4.cpp \
    hidato5x5.cpp \
    hidato6x6.cpp \



HEADERS += \
    PlayGround.h \
    choosewindow.h \
    hidato4x4.h \
    hidato5x5.h \
    hidato6x6.h \


FORMS += \
    choosewindow.ui \
    hidato4x4.ui \
    hidato5x5.ui \
    hidato6x6.ui \
