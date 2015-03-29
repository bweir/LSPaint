#pragma once

#include <QLabel>

class SpriteImage : public QLabel
{
public:
    SpriteImage(QWidget *parent = 0);
    void updateImage(const QPixmap & pixmap);
    QPixmap getImage();

private:
    void mouseMoveEvent(QMouseEvent *event);
    int zoom;
    QPixmap image;
};
