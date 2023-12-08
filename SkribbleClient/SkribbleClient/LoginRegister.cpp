#include "LoginRegister.h"

LoginRegister::LoginRegister(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	//m_colorButton = new QPushButton("Alege Culoare", this);
	//m_colorButton->setGeometry(width()/2-40, height()/2-30, 120, 30);
	//connect(m_colorButton, &QPushButton::clicked, this, &LoginWindow::joinGame);

	//m_loginButton = ui.pushButton;
	//m_registerButton = ui.pushButton_2;
	//m_registerButton->setGeometry(50, 100, 100, 30); // Ajusteaz? geometria dup? necesit??i
	this->resize(1300, 700);
	m_registerButton = new QPushButton("Register", this);
	m_registerButton->setGeometry(50, 50, 200, 30);
	connect(m_registerButton, &QPushButton::clicked, this, &LoginRegister::onRegisterClicked);
	m_loginButton = new QPushButton("Login", this);
	m_loginButton->setGeometry(450, 50, 200, 30);
	connect(m_loginButton, &QPushButton::clicked, this, &LoginRegister::onRegisterClicked);

	//m_registerWindow = nullptr;

	//q: how to fix a size for window

	//this->setStyleSheet("background-image: url(:/ClientQT/fundal.jpg);");
	//this->setFixedSize(1100, 800);
}

LoginRegister::~LoginRegister()
{}


void LoginRegister::onRegisterClicked()
{
	m_registerWindow = new RegisterWindow(this);
	this->close();
	m_registerWindow->show();

}