#include "ClientQT.h"
#include <QtWidgets/QApplication>

#include <cpr/cpr.h>
#include <crow.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ClientQT w;
    QPalette pal = w.palette();
    pal.setColor(QPalette::Window, Qt::red);
    w.setPalette(pal);
    w.resize(1300, 700);
    w.show();
    return a.exec();
}
