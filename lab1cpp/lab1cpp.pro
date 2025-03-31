TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        action.cpp \
        circle.cpp \
        figure.cpp \
        interface.cpp \
        io.cpp \
        main.cpp \
        rectangle.cpp \
        triangle.cpp \
        validation.cpp

HEADERS += \
    action.h \
    circle.h \
    figure.h \
    figureexception.h \
    interface.h \
    io.h \
    rectangle.h \
    triangle.h
