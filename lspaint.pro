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
    sidebar.cpp \
    dialogs/newfile.cpp \

HEADERS += \
    mainwindow.h \
    spriteeditor.h \
    spriteimage.h \
    sidebar.h \
    dialogs/newfile.h \

FORMS += \
    mainwindow.ui \
    spriteeditor.ui \
    sidebar.ui \
    dialogs/newfile.ui \
