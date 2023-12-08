#include "SkribbleClient.h"
#include <QtWidgets/QApplication>
#include "LoginRegister.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
  /*  SkribbleClient w;
    w.show();*/
    LoginRegister client;
    client.show();
    return a.exec();
}
