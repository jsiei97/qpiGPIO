TEMPLATE = app
TARGET = 
DEPENDPATH  += src
INCLUDEPATH += src

# Input
SOURCES += src/main.cpp 

# The code that is "shared"
include($$PWD/mod.pri)
