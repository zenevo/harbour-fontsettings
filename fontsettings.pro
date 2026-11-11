TARGET = harbour-fontsettings
CONFIG += sailfishapp c++11
QT += quick

SOURCES += src/main.cpp src/fontbackend.cpp
HEADERS += src/fontbackend.h

target.path = /usr/bin
INSTALLS += target
