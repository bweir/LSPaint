#include "mainwindow.h"

#include <QDebug>
#include <QPixmap>
#include <QLabel>
#include <QImage>
#include <QFileInfo>
#include <QFileDialog>

#include "spriteeditor.h"

#include "dialogs/newfile.h"

MainWindow::MainWindow(QWidget * parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    openFile("dagr_2b.png");
    qDebug() << " STUFF";

    connect(ui.action_New, SIGNAL(triggered()), this, SLOT(newFile()));
    connect(ui.action_Open, SIGNAL(triggered()), this, SLOT(open()));
    connect(ui.action_Save, SIGNAL(triggered()), this, SLOT(save()));
    connect(ui.actionSave_as, SIGNAL(triggered()), this, SLOT(saveAs()));
}


void MainWindow::open()
{
//    QString dir = QDir(tabToolTip(currentIndex())).path();
    QString fn = QFileDialog::getOpenFileName(this,
                tr("Open File"), QDir::currentPath(), "PNG Files (*.png);;All Files (*)");

    if (!fn.isEmpty())
        openFile(fn);
}

void MainWindow::save()
{
    QString fn = filename;
    if (fn.isEmpty())
        saveAs();
    else
        saveFile(fn);
}

void MainWindow::saveAs()
{
    QString fn = filename;
    if (fn.isEmpty())
        fn = tr("Untitled.png");

    fn = QFileDialog::getSaveFileName(this,
            tr("Save File As..."), 
            QDir(fn).path(), 
            tr("PNG files (*.png)"));

    if (fn.isEmpty())
        return;

    saveFile(fn);
}

void MainWindow::emptyFile()
{
    closeFile();
    SpriteEditor *editor = new SpriteEditor(this);
    editor->setAttribute(Qt::WA_DeleteOnClose);
    int index = ui.editor->addTab(editor, QString());
    ui.editor->setCurrentIndex(index);
}

void MainWindow::newFile()
{

    NewFile newfile;
    if (!newfile.exec())
        return;

    emptyFile();

    QPixmap pixmap(newfile.width(), newfile.height());
    pixmap.fill();

    SpriteEditor * editor = (SpriteEditor *) ui.editor->currentWidget();
    editor->setPixmap(pixmap);

    int index = ui.editor->currentIndex();
    ui.editor->setTabIcon(index,QIcon(pixmap));
}


void MainWindow::saveFile(const QString & name)
{
    if (!ui.editor->count())
        return;

    SpriteEditor * editor = (SpriteEditor *) ui.editor->currentWidget();

    QImage img = editor->pixmap().toImage();
    img.setText("LameGFX:framesize:w",QString::number(323));
    img.setText("LameGFX:framesize:h",QString::number(111));
    img.save(name);
}

void MainWindow::openFile(const QString & name)
{
    if (!QFileInfo(name).exists())
    {
        qDebug() << "File does not exist";
        return;
    }

    filename = name;

    emptyFile();
    int index = ui.editor->currentIndex();
    SpriteEditor * editor = (SpriteEditor *) ui.editor->currentWidget();

    QImage img(filename);

    int framew = 0, frameh = 0;
    QString fw = img.text("LameGFX:framesize:w");
    QString fh = img.text("LameGFX:framesize:h");

    if (!fw.isEmpty())
        framew = fw.toInt();

    if (!fh.isEmpty())
        frameh = fh.toInt();

    editor->setFrameSize(QSize(framew, frameh));

    qDebug() << framew << frameh;

    QPixmap pixmap = QPixmap::fromImage(img);
    editor->setPixmap(pixmap);

    ui.editor->setTabIcon(index,QIcon(pixmap));
}

void MainWindow::closeFile()
{
    while (ui.editor->count() > 0)
    {
        SpriteEditor * editor = (SpriteEditor *) ui.editor->widget(0);
        editor->disconnect();
        editor->close();
        ui.editor->removeTab(0);
    }
}
