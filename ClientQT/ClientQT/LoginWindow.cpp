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
	connect(ui.goToJoinGameButton, &QPushButton::clicked, this, &LoginWindow::changeToJoinGamePage);
	connect(ui.goToCreateGameButton, &QPushButton::clicked, this, &LoginWindow::changeToCreateGamePage);
}

void LoginWindow::changeToCreateGamePage()//de verificat de ce nu face conversia din std::string in QString
{
	ui.stackedWidget->setCurrentIndex(4);
	ui.hostNameLabel->setText("eu");
	displayGameCode();
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

void LoginWindow::displayGameCode()//de verificat de ce nu face conversia din std::string in QString
{
	ui.showCodeLabel->setText("2003");
}

void LoginWindow::on_loginButton_clicked()
{
	username = ui.lineEditUsernameLogin->text().toUtf8().constData();
	password = ui.lineEditPasswordLogin->text().toUtf8().constData();


	auto response = cpr::Put(cpr::Url{ "http://localhost:18080/Login" }, cpr::Parameters{ { "username", username},
							 { "password", password } });
	if (response.status_code == 200)

	{
		changeToLobbyPage();
	}
	else
		if (response.status_code == 300)
		{
			QMessageBox::warning(this, "Login", "Username or password is not correct.");
		}
}

void LoginWindow::on_registerButton_clicked()
{
	username = ui.lineEditUsernameRegister->text().toUtf8().constData();
	password = ui.lineEditPasswordRegister->text().toUtf8().constData();


	auto response = cpr::Put(cpr::Url{ "http://localhost:18080/Register" }, cpr::Parameters{ { "username", username},
							 { "password", password } });
	if (response.status_code == 300)
	{
		QMessageBox::warning(this, "Register", "Username already registered!");
	}
	else if (response.status_code == 200)
	{
		changeToLobbyPage();
	}
}

void LoginWindow::on_startGameButton_clicked()
{
	std::string testCode = "testCode";
	auto response = cpr::Put(cpr::Url("http://localhost:18080/CreateGame"), cpr::Parameters{ { "username", username},
							 { "gameCode", testCode } });
	if (response.status_code == 200)
	{
		this->close();

		GameWindow* gameWindow = new GameWindow();
		gameWindow->SetName(username);

		gameWindow->show();
	}
}
