#pragma once

#include <QMainWindow>
#include "ui_LoginWindow.h"
#include "RegisterWindow.h"
#include "GameWindow.h"


#include <QPushButton>
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
	void changeToMainPage();
	void changeToLoginPage();
	void changeToRegisterPage();
	void changeToLobbyPage();
	void changeToCreateGamePage();
	void changeToJoinGamePage();
	void on_loginButton_clicked();
	void on_registerButton_clicked();
	void on_startGameButton_clicked();
	void exitGameWidget();

private:
	Ui::LoginWindowClass ui;
};
