#pragma once

#include "ui_newfile.h"

class NewFile : public QDialog
{
    Q_OBJECT

private:
    Ui::NewFile ui;

public:
    NewFile(QWidget *parent = 0);
    int width();
    int height();

public slots:
    void toggleFrames(int state);
};

