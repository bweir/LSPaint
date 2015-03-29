#include <QWidget>
#include <QDebug>
#include <QApplication>
#include <QPaintEvent>

#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow w;
    w.show();

    return app.exec();
}
