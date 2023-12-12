#include <QtWidgets/QApplication>
#include "RegisterWindow.h"
#include <QApplication>
#include <cpr/cpr.h>
#include <crow.h>
#include "LoginWindow.h"

#include <QApplication>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginWindow loginWindow;
    loginWindow.show();
    return a.exec();

}
