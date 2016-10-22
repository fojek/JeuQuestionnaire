#-------------------------------------------------
#
# Project created by QtCreator 2015-12-27T20:52:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CRC_Quest
TEMPLATE = app


SOURCES += main.cpp\
    jeuQuestionnaire_GPIO.cpp \
    crcQuest.cpp

HEADERS  += \
    global.h \
    crcQuest.h \
    ui_about.h

FORMS    += crc_quest.ui \
    about.ui

LIBS	 += -lwiringPi

RESOURCES += \
    images.qrc
