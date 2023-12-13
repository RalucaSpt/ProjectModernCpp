#include "LoginWindow.h"

#include<QMessageBox>

LoginWindow::LoginWindow(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	//m_loginButton = ui.loginButton;
	//m_registerButton = ui.registreButton;
	////m_startButton = ui.startButton;

	//connect(m_registerButton, &QPushButton::clicked, this, &LoginWindow::onRegisterClicked);
	//connect(m_loginButton, &QPushButton::clicked, this, &LoginWindow::onRegisterClicked);

	//m_registerWindow = nullptr;
	ui.stackedWidget->setCurrentIndex(0);
	connect(ui.loginButton, &QPushButton::clicked, this, &LoginWindow::changeToLoginPage);
	connect(ui.registreButton, &QPushButton::clicked, this, &LoginWindow::changeToRegistrePage);
	connect(ui.exitButton, &QPushButton::clicked, this, &LoginWindow::exitGameWidget);

	// Connecteazã celelalte butoane la slot-urile corespunzãtoare pentru schimbarea paginilor.


}
void LoginWindow::joinGame()
{
	//ClientQT* gameWindow = new ClientQT();
	//gameWindow->show();
	//if (m_registerWindow->GetUsername().size() != 0)
	//{
	//	std::string name = m_registerWindow->GetUsername();
	//	auto response = cpr::Post(cpr::Url{ "http://localhost:18080/CreateGame" },
	//		cpr::Body(name));
	//}
	//this->close();
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

void LoginWindow::changeToRegistrePage()
{
	ui.stackedWidget->setCurrentIndex(2);
	connect(ui.backButtonRegister, &QPushButton::clicked, this, &LoginWindow::changeToMainPage);
}

void LoginWindow::changeToLobbyPage()
{
	ui.stackedWidget->setCurrentIndex(3);
	connect(ui.backButtonLobby, &QPushButton::clicked, this, &LoginWindow::changeToMainPage);
	connect(ui.createGameButton, &QPushButton::clicked, this, &LoginWindow::changeToCreateGamePage);
	connect(ui.joinGameButton, &QPushButton::clicked, this, &LoginWindow::changeToJoinGamePage);

}

void LoginWindow::changeToCreateGamePage()
{
	ui.stackedWidget->setCurrentIndex(4);
}

void LoginWindow::changeToJoinGamePage()
{
	ui.stackedWidget->setCurrentIndex(5);
	connect(ui.joinGameButtonInsertCode, &QPushButton::clicked, this, &LoginWindow::changeToCreateGamePage);
}

void LoginWindow::exitGameWidget()
{
	this->close();
}

void LoginWindow::on_loginButton_2_clicked()
{
	QString username = ui.lineEditUsername->text();
	QString password = ui.lineEditPassword->text();

	////CONNECT TO SERVER
	if (username == "admin" && password == "admin")
	{
		connect(ui.loginButton_2, &QPushButton::clicked, this, &LoginWindow::changeToLobbyPage);
	}
	else
	{
		QMessageBox::warning(this, "Login", "Username and password is not correct. Parola si usernameul sunt admin");
	}
}

void LoginWindow::on_registerButton_2_clicked()
{
	QString username = ui.lineEditUsernameRegister->text();
	QString password = ui.lineEditPasswordRegister->text();

	//CONNECT TO SERVER
	if (username == "admin" && password == "admin")
	{
		connect(ui.registerButton_2, &QPushButton::clicked, this, &LoginWindow::changeToLobbyPage);
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
	//delete m_registerWindow; 
}