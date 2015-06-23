#-------------------------------------------------
#
# Project created by QtCreator 2015-06-07T14:40:03
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CRYPTO
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    caesar.cpp \
    descoder.cpp \
    desint.cpp \
    steganography.cpp \
    vigener.cpp

HEADERS  += mainwindow.h \
    caesar.h \
    descoder.h \
    desint.h \
    steganography.h \
    vigener.h

FORMS    += mainwindow.ui \
    caesar.ui \
    desint.ui \
    steganography.ui \
    vigener.ui