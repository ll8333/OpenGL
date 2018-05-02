#-------------------------------------------------
#
# Project created by QtCreator 2018-05-01T17:51:48
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = draw4
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp

HEADERS  += widget.h

win32: LIBS += -L$$PWD/../../../../../glew/ -lglew32

INCLUDEPATH += $$PWD/../../../../../glew
DEPENDPATH += $$PWD/../../../../../glew
