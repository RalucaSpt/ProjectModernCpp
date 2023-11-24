#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ClientQT.h"

class ClientQT : public QMainWindow
{
    Q_OBJECT

public:
    ClientQT(QWidget *parent = nullptr);
    ~ClientQT();

private:
    Ui::ClientQTClass ui;
};
