QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
TARGET = QT_PSQLS
TEMPLATE = app
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    begin.cpp \
    instructions.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    begin.h \
    instructions.h \
    mainwindow.h

FORMS += \
    begin.ui \
    instructions.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resourses.qrc

DISTFILES += \
    ../../Users/Пользователь/Downloads/Frame 3 (6).png
