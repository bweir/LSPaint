#include "spriteeditor.h"

#include <QDebug>
#include <QMouseEvent>

SpriteImage::SpriteImage(QWidget * parent)
    : QLabel(parent)
{
    zoom = 4;
}

void SpriteImage::mouseMoveEvent(QMouseEvent *event)
{
    QPoint p = event->pos();
    int x = p.x();
    int y = p.y();
    if ((x >= 0 && x < width()) &&
            (y >= 0 && y < height()))
    {
        p = QPoint(x/zoom, y/zoom);
        qDebug() << p;
    }
}

void SpriteImage::updateImage(const QPixmap & pixmap)
{
    image = pixmap;
    int w = image.width()*4;
    int h = image.height()*4;
    setPixmap(image.scaled(w,h,Qt::KeepAspectRatio));
    setFixedSize(w,h);
}

QPixmap SpriteImage::getImage()
{
    return image;
}
