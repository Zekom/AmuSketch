#include <QtGui>
#include "amuview.h"
#include "amuwindow.h"
#include "ui_amuwindow.h"

AmuWindow::AmuWindow(QWidget *parent) :
    QMainWindow(parent), Ui::AmuWindow()
{
    setAttribute(Qt::WA_DeleteOnClose);

    setupUi(this);
    createActions();

    view = new AmuView(this);
    setCentralWidget(view);

    readSettings();

}

void AmuWindow::closeEvent(QCloseEvent *event)
{
    if(saveToClose())
        writeSettings();
    else
        event->ignore();

}

void AmuWindow::createActions()
{
    connect(actionAboutQt, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
    connect(actionExit, SIGNAL(triggered()), qApp, SLOT(closeAllWindows()));
    connect(actionClose, SIGNAL(triggered()), this, SLOT(close()));
}

void AmuWindow::readSettings()
{
    QSettings settings("Compiztab Pe.", "AmuSketch");

    restoreGeometry(settings.value("geometry").toByteArray());
}

void AmuWindow::writeSettings()
{
    QSettings settings("Compiztab Pe.", "AmuSketch");

    settings.setValue("geometry", saveGeometry());
}

void AmuWindow::openRecentProject()
{

}

void AmuWindow::updateStatusBar()
{

}

void AmuWindow::windowModified()
{

}

bool AmuWindow::saveToClose()
{
    if (isWindowModified()) {
        int r = QMessageBox::warning(this, tr("Save changes"),
                                     tr("You have some changes.\n"
                                        "Do you want to save it?"),
                                     QMessageBox::Save | QMessageBox::Discard
                                     | QMessageBox::Cancel);
        if (r == QMessageBox::Save)
            return on_actionSave_triggered();

        else if (r == QMessageBox::Cancel)
            return false;
    }
    return true;
}

void AmuWindow::on_actionNew_triggered()
{
    AmuWindow *windo = new AmuWindow;
    windo->show();
}

bool AmuWindow::on_actionSave_triggered()
{
    return false;
}
