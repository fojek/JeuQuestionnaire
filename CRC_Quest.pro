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
        crc_quest.cpp \
    jeuQuestionnaire_GPIO.cpp

HEADERS  += crc_quest.h \
    global.h

FORMS    += crc_quest.ui

LIBS	 += -lwiringPi
