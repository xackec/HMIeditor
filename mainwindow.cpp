#include "mainwindow.h"
#include "widgetparser.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    QString fileName =
                QFileDialog::getOpenFileName(this, tr("Open Widget File"),
                                             QDir::currentPath(),
                                             tr("XML Files ( *.xml)"));
    if(fileName.isEmpty())
        return;
    WidgetParser handler;
    QXmlInputSource   source(&file);
    QXmlSimpleReader  reader;
}

MainWindow::~MainWindow()
{

}
