#pragma once

#include <QMainWindow>
#include "ui_LoginWindow.h"
#include <QPushButton>
#include "Client.h"
#include "RegisterWindow.h"
#include <QInputDialog>
#include <qdir.h>
#include <cpr/cpr.h>
#include <qstackedwidget.h>

class LoginWindow : public QMainWindow
{
	Q_OBJECT

public:
	LoginWindow(QWidget *parent = nullptr);
	~LoginWindow();
private slots:
	void joinGame();
	void onRegisterClicked();
private:
	Ui::LoginWindowClass ui;
	//QPushButton* m_colorButton;

	//QPushButton* m_loginButton;
	//QPushButton* m_registerButton;
	//QPushButton* m_startButton;
	//RegisterWindow* m_registerWindow;

public slots:
	void changeToLoginPage();
	void changeToRegistrePage();
	void changeToLobbyPage();
	void createGameWidget();
	void joinGameWidget();
	void exitGameWidget();
};
