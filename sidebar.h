#pragma once

#include <QWidget>

#include "ui_sidebar.h"

class SideBar : public QWidget
{
private:
    Ui::SideBar ui;
public:
    SideBar(QWidget *parent = 0);
};

