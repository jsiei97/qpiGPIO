#Used to include this project as a mod
DEPENDPATH  += $$PWD/src
INCLUDEPATH += $$PWD/src

# Input
HEADERS += $$PWD/src/gpio_RaspberryPi.h
HEADERS += $$PWD/src/DebugDefines.h

HEADERS += $$PWD/src/SysfsGPIO.h
SOURCES += $$PWD/src/SysfsGPIO.cpp
