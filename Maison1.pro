QT       += core gui
QT       += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Hachage.cpp \
    affichages.cpp \
    inserer.cpp \
    main.cpp \
    mainwindow.cpp \
    rechercher.cpp \
    supprimer.cpp

HEADERS += \
    Hachage.h \
    affichages.h \
    connexion.h \
    inserer.h \
    mainwindow.h \
    rechercher.h \
    supprimer.h

FORMS += \
    affichages.ui \
    inserer.ui \
    mainwindow.ui \
    rechercher.ui \
    supprimer.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
