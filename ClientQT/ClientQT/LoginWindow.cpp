#include "LoginWindow.h"

LoginWindow::LoginWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	m_colorButton = new QPushButton("Alege Culoare", this);
	m_colorButton->setGeometry(width()/2-40, height()/2-30, 120, 30);
	connect(m_colorButton, &QPushButton::clicked, this, &LoginWindow::joinGame);

	m_registerButton = new QPushButton("Inregistrare", this);
	m_registerButton->setGeometry(50, 100, 100, 30); // Ajusteaz? geometria dup? necesit??i
	connect(m_registerButton, &QPushButton::clicked, this, &LoginWindow::onRegisterClicked);

	m_registerWindow = nullptr;
	
}
void LoginWindow::joinGame()
{
	ClientQT* gameWindow= new ClientQT();
	gameWindow->show();
	if (m_registerWindow->GetUsername().size() != 0)
	{
		std::string name= m_registerWindow->GetUsername();
		auto response = cpr::Post(cpr::Url{ "http://localhost:18080/CreateGame" },
			cpr::Body(name));
	}
	this->close();
}

void LoginWindow::onRegisterClicked()
{
	if (!m_registerWindow) {
		m_registerWindow = new RegisterWindow(this);
	}
	m_registerWindow->show();
}

LoginWindow::~LoginWindow()
{
	delete m_registerWindow; 
}