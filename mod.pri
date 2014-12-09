#Used to include this project as a mod
DEPENDPATH  += $$PWD/src
INCLUDEPATH += $$PWD/src

# Input
HEADERS += gpio_RaspberryPi.h
HEADERS += DebugDefines.h

HEADERS += SysfsGPIO.h
SOURCES += SysfsGPIO.cpp
