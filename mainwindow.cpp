#include "mainwindow.h"
#include "widgetparser.h"
#include "cnode.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    QString fileName =
                QFileDialog::getOpenFileName(this, tr("Open Widget File"),
                                             QDir::currentPath(),
                                             tr("XML Files ( *.xml)"));
    CNode node;
    node.readDocument(fileName);
}

MainWindow::~MainWindow()
{

}
