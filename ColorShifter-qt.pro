#-------------------------------------------------
#
# Project created by QtCreator 2014-07-09T16:43:11
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ColorShifter-qt
TEMPLATE = app


SOURCES += \
    mainwindow.cpp \
main.cpp\
    dllTools.cpp \
    Color.cpp \
    colorTools.cpp \
    interpolate.cpp \
    main2.cpp \


HEADERS  += \
    dllTools.h \
    mainwindow.h \
    colorTools.h \
    exitCodes.h

FORMS    += mainwindow.ui