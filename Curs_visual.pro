#-------------------------------------------------
#
# Project created by QtCreator 2022-12-09T17:46:20
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Curs_visual
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
        recipebook.cpp \
    recipeeditor.cpp \
    recipeviewer.cpp \
    stepseditor.cpp \
    stepsviewer.cpp \
    droplabel.cpp \
    help.cpp

HEADERS += \
        recipebook.h \
    recipeeditor.h \
    recipeviewer.h \
    stepseditor.h \
    stepsviewer.h \
    droplabel.h \
    functions.h \
    help.h

FORMS += \
        recipebook.ui \
    recipeeditor.ui \
    recipeviewer.ui \
    stepseditor.ui \
    stepsviewer.ui \
    help.ui

RESOURCES += \
    src.qrc

DISTFILES += \
    style.qss
