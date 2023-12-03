#include "LoginWindow.h"

LoginWindow::LoginWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	m_colorButton = new QPushButton("Alege Culoare", this);
	m_colorButton->setGeometry(width()/2-40, height()/2-30, 120, 30);
	connect(m_colorButton, &QPushButton::clicked, this, &LoginWindow::joinGame);
}

LoginWindow::~LoginWindow()
{}

void LoginWindow::joinGame()
{
	ClientQT* gameWindow= new ClientQT();
	gameWindow->show();
	this->close();
}