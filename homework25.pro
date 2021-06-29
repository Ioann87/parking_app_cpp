TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        functions.cpp \
        main.cpp \
        parking.cpp \
        person.cpp

HEADERS += \
    functions.h \
    parking.h \
    person.h

DISTFILES += \
    female \
    male \
    neutrum
