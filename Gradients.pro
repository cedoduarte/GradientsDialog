QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

SOURCES += \
    colorcombobox.cpp \
    colordelegate.cpp \
    gradientdata.cpp \
    gradientdialog.cpp \
    gradientmodel.cpp \
    gradientscene.cpp \
    main.cpp \
    stopdelegate.cpp

HEADERS += \
    colorcombobox.h \
    colordelegate.h \
    gradientdata.h \
    gradientdialog.h \
    gradientmodel.h \
    gradientscene.h \
    stopdelegate.h

FORMS += \
    gradientdialog.ui

RESOURCES += \
    res.qrc
