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
	void joinGame();
	void changeToMainPage();
private:
	Ui::LoginWindowClass ui;

public slots:
	void changeToLoginPage();
	void changeToRegistrePage();
	void changeToLobbyPage();
	void changeToCreateGamePage();
	void changeToJoinGamePage();

	void exitGameWidget();

	void on_loginButton_2_clicked();
	void on_registerButton_2_clicked();
	void on_startGameButton_clicked();

private:
	std::string username,password;
	
};
