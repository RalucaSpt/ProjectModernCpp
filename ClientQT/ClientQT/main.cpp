#include "ClientQT.h"
#include <QtWidgets/QApplication>

#include <cpr/cpr.h>
#include <crow.h>
#include "LoginWindow.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginWindow w;
    w.show();
    return a.exec();
}
