TEMPLATE = app
TARGET = lspaint
INCLUDEPATH += .

QT += gui widgets

# Input
SOURCES += \
    main.cpp \
    mainwindow.cpp \
    spriteeditor.cpp \
    spriteimage.cpp \
    dialogs/newfile.cpp \

HEADERS += \
    mainwindow.h \
    spriteeditor.h \
    spriteimage.h \
    dialogs/newfile.h \
    color.h \

FORMS += \
    mainwindow.ui \
    spriteeditor.ui \
    dialogs/newfile.ui \
