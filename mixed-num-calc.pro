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
    parser.cpp \
    parserfriend.cpp \
    token.cpp \
    tokenfriend.cpp \
    calculate.cpp \
    calculatefriend.cpp

DISTFILES += \
    README.md \
    .gitignore \
    knownBugs.md

HEADERS += \
    fraction.h \
    mixednumber.h \
    parser.h \
    token.h \
    calculate.h \
    error.h
