#pragma once

#include <QWidget>
#include <QPixmap>

#include "ui_spriteeditor.h"

class SpriteEditor : public QWidget
{
private:
    Ui::SpriteEditor ui;
    QSize framesize;
public:
    SpriteEditor(QWidget *parent = 0);
    void setPixmap(const QPixmap & pixmap);
    QPixmap pixmap();
    void setFrameSize(const QSize & size);
};

