######################################################################
# Automatically generated by qmake (3.0) Mon Jul 18 20:08:51 2016
######################################################################

TEMPLATE = app
TARGET = Akai
INCLUDEPATH += .
RC_ICONS += icons/akai.svg

# Input
HEADERS += addfrienddialog.h \
           acceptcalldialog.h \
           creategroupdialog.h \
           messagelist.h \
           logindialog.h \
           mainwindow.h \
           messagehistory.h \
           messageinput.h \
           network.h \
           audio.h
SOURCES += addfrienddialog.cpp \
           acceptcalldialog.cpp \
           creategroupdialog.cpp \
           messagelist.cpp \
           logindialog.cpp \
           main.cpp \
           mainwindow.cpp \
           messagehistory.cpp \
           messageinput.cpp \
           network.cpp \
           audio.cpp
QMAKE_CXXFLAGS += -g
LIBS += -lQt5Widgets -lQt5Network -lQt5Multimedia
OBJECTS_DIR=objects
MOC_DIR=objects

unix:application.path = ~/.local/share/akai
unix:application.files = Akai

INSTALLS += application
