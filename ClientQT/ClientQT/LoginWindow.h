#pragma once

#include <QMainWindow>
#include "ui_LoginWindow.h"
#include "GameWindow.h"


#include <QPushButton>
#include <QInputDialog>
#include <qdir.h>
#include <cpr/cpr.h>
#include <qstackedwidget.h>
#include <random>

class LoginWindow : public QMainWindow
{
	Q_OBJECT

public:
	LoginWindow(QWidget* parent = nullptr);
	~LoginWindow() = default;

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
	void on_joinGameButton_clicked();
	void on_goToCreateGameButton_clicked();
	void exitGameWidget();
	void displayGameCode();


private:
	Ui::LoginWindowClass ui;
	std::string username = "eu";
	std::string password;
	std::string m_gameCode = "testCode";
};
