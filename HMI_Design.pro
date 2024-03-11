QT       += core gui



greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    climatemenudialog.cpp \
    main.cpp \
    mainwindow.cpp \
    surfacedialwidget.cpp

HEADERS += \
    ClickableLabel.h \
    climatemenudialog.h \
    mainwindow.h \
    surfacedialwidget.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ../../Arrow_down.png \
    ../../Arrow_up.png \
    ../../car (1).png \
    ../../car (1).png \
    ../../draw.png \
    ../../fan (2).png \
    ../../fan_large.png \
    ../../fan_small.png \
    ../../heat_max.png \
    ../../heat_rare.png \
    ../../home.png \
    ../../left-turn-arrow.png \
    ../../map.png \
    ../../next.png \
    ../../previous.png \
    ../../sportive-car.png \
    ../../thermometer.png

RESOURCES += \
    resources.qrc
