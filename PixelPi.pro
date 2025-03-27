QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    brush.cpp \
    controller.cpp \
    fileDialog.cpp \
    main.cpp \
    paintWidget.cpp \
    palette.cpp \
    pixel.cpp \
    pixelpi.cpp \
    sprite.cpp \
    spritesheet.cpp \
    timeline.cpp

HEADERS += \
    brush.h \
    controller.h \
    fileDialog.h \
    paintWidget.h \
    palette.h \
    pixel.h \
    pixelpi.h \
    sprite.h \
    spritesheet.h \
    timeline.h

FORMS += \
    fileDialog.ui \
    pixelpi.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    spritetoolmodel.qmodel
