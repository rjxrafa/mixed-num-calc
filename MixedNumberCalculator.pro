TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    fraction.cpp \
    fractionfriend.cpp \
    mixednumber.cpp \
    mixednumberfriend.cpp \
    parser.cpp

HEADERS += \
    fraction.h \
    mixednumber.h \
    parser.h

DISTFILES += \
    KnownBugs
