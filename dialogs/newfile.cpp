#include "newfile.h"

NewFile::NewFile(QWidget * parent)
    : QDialog(parent)
{
    ui.setupUi(this);

    ui.widthEdit->setValue(64);
    ui.heightEdit->setValue(64);

    connect(ui.splitIntoFrames, SIGNAL(stateChanged(int)), this, SLOT(toggleFrames(int)));
}

void NewFile::toggleFrames(int state)
{
    ui.frameSizeBox->setEnabled(state);
}

int NewFile::width()
{
    return (int) ui.widthEdit->value();
}

int NewFile::height()
{
    return (int) ui.heightEdit->value();
}
