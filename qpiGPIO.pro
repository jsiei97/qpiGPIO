TEMPLATE = app
TARGET = 
DEPENDPATH  += . src
INCLUDEPATH += . src

# Input
HEADERS += src/gpio_RaspberryPi.h src/SysfsGPIO.h
SOURCES += src/main.cpp src/SysfsGPIO.cpp
