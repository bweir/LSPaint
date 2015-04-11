#pragma once

#include <QMainWindow>
#include <QString>

#include "ui_mainwindow.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    Ui::MainWindow ui;
    QString filename;
    QString palette;
public:
    MainWindow(QWidget * parent = 0);

public slots:
    void open();
    void save();
    void saveAs();
    void newFile();
    void emptyFile();
    void saveFile(const QString & filename);
    void openFile(const QString & filename);
    void closeFile();
    void setColorPalette(const QString & name);
};

