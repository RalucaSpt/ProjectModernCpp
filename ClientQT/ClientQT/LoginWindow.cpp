#include "LoginWindow.h"
#include<QMessageBox>

LoginWindow::LoginWindow(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	changeToMainPage();
	connect(ui.goToLoginButton, &QPushButton::clicked, this, &LoginWindow::changeToLoginPage);
	connect(ui.goToRegisterButton, &QPushButton::clicked, this, &LoginWindow::changeToRegisterPage);
	connect(ui.exitButton, &QPushButton::clicked, this, &LoginWindow::exitGameWidget);
}

void LoginWindow::changeToMainPage()
{
	ui.stackedWidget->setCurrentIndex(0);
}

void LoginWindow::changeToLoginPage()
{
	ui.stackedWidget->setCurrentIndex(1);
	connect(ui.backButtonLogin, &QPushButton::clicked, this, &LoginWindow::changeToMainPage);
}

void LoginWindow::changeToRegisterPage()
{
	ui.stackedWidget->setCurrentIndex(2);
	connect(ui.backButtonRegister, &QPushButton::clicked, this, &LoginWindow::changeToMainPage);
}

void LoginWindow::changeToLobbyPage()
{
	ui.stackedWidget->setCurrentIndex(3);
	connect(ui.backButtonLobby, &QPushButton::clicked, this, &LoginWindow::changeToMainPage);
	connect(ui.goToCreateGameButton, &QPushButton::clicked, this, &LoginWindow::changeToCreateGamePage);
	connect(ui.goToJoinGameButton, &QPushButton::clicked, this, &LoginWindow::changeToJoinGamePage);
}

void LoginWindow::changeToCreateGamePage()
{
	ui.stackedWidget->setCurrentIndex(4);
}

void LoginWindow::changeToJoinGamePage()
{
	ui.stackedWidget->setCurrentIndex(5);
	connect(ui.joinGameButton, &QPushButton::clicked, this, &LoginWindow::changeToCreateGamePage);
}

void LoginWindow::exitGameWidget()
{
	this->close();
}

void LoginWindow::on_loginButton_clicked()
{
	QString username = ui.lineEditUsernameLogin->text();
	QString password = ui.lineEditPasswordLogin->text();

	////CONNECT TO SERVER
	if (username == "admin" && password == "admin")
	{
		changeToLobbyPage();
	}
	else
	{
		QMessageBox::warning(this, "Login", "Username and password is not correct. Parola si usernameul sunt admin");
	}
}

void LoginWindow::on_registerButton_clicked()
{
	QString username = ui.lineEditUsernameRegister->text();
	QString password = ui.lineEditPasswordRegister->text();

	//CONNECT TO SERVER
	if (username == "admin" && password == "admin")
	{
		changeToLobbyPage();
	}
	else
	{
		QMessageBox::warning(this, "Register", "Username and password is not correct. Parola si usernameul sunt admin");
	}
}

void LoginWindow::on_startGameButton_clicked()
{
	this->close();
	GameWindow* gameWindow = new GameWindow();
	gameWindow->show();
}

LoginWindow::~LoginWindow()
{

}