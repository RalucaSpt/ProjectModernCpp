#include "LoginWindow.h"

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

void LoginWindow::onRegisterClicked()
{

}

void LoginWindow::changeToLoginPage()
{
	ui.stackedWidget->setCurrentIndex(1);
	connect(ui.loginButton_2, &QPushButton::clicked, this, &LoginWindow::changeToLobbyPage);
}

void LoginWindow::changeToRegistrePage()
{
	ui.stackedWidget->setCurrentIndex(2);
	connect(ui.registreButton_2, &QPushButton::clicked, this, &LoginWindow::changeToLobbyPage);
}

void LoginWindow::changeToLobbyPage()
{
	ui.stackedWidget->setCurrentIndex(3);
}

void LoginWindow::createGameWidget()
{

}

void LoginWindow::joinGameWidget()
{
}

LoginWindow::~LoginWindow()
{
	//delete m_registerWindow; 
}