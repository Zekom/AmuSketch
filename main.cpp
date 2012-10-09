#include <QtGui/QApplication>
#include "amuwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AmuWindow *w = new AmuWindow;
    w->show();
    
    return a.exec();
}
