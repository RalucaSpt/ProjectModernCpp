#include "ClientQT.h"
#include <QtWidgets/QApplication>

#include <cpr/cpr.h>
#include <crow.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    auto response = cpr::Get(cpr::Url{ "http://localhost:18080" });
    // qDebug() << response.text;

    ClientQT w;
    w.show();
    return a.exec();
}
