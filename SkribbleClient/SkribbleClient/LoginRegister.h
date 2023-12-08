#pragma once

#include <QMainWindow>
#include "ui_LoginRegister.h"

#include <QPushButton>
//#include "ClientQT.h"
#include "RegisterWindow.h"
#include <QInputDialog>
#include <qdir.h>
#include <cpr/cpr.h>
class LoginRegister : public QMainWindow
{
	Q_OBJECT

public:
	LoginRegister(QWidget *parent = nullptr);
	~LoginRegister();

private slots:

	//void joinGame();
	void onRegisterClicked();
private:
	Ui::LoginRegisterClass ui;

	RegisterWindow* m_registerWindow;

	QPushButton* m_colorButton;
	QPushButton* m_loginButton;
	QPushButton* m_registerButton;

	//RegisterWindow* m_registerWindow;
};
