#include "spriteeditor.h"

SpriteEditor::SpriteEditor(QWidget * parent)
    : QWidget(parent)
{
    ui.setupUi(this);

}

void SpriteEditor::setPixmap(const QPixmap & pixmap)
{
    ui.image->updateImage(pixmap);
}

QPixmap SpriteEditor::pixmap()
{
    return ui.image->getImage();
}

void SpriteEditor::setFrameSize(const QSize & size)
{
    framesize = size;
}
