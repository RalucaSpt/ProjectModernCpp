#include "RegisterWindow.h"

RegisterWindow::RegisterWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

    // Setează dimensiunile și titlul ferestrei
    // this->setWindowTitle("Register");
    // this->setFixedSize(300, 200);
    this->resize(1300, 700);
    // Creează și poziționează elementele UI
    m_usernameLineEdit = new QLineEdit(this);
    m_usernameLineEdit->setPlaceholderText("Username");
    m_usernameLineEdit->setGeometry(50, 50, 200, 30);

    m_passwordLineEdit = new QLineEdit(this);
    m_passwordLineEdit->setPlaceholderText("Password");
    m_passwordLineEdit->setEchoMode(QLineEdit::Password); // Ascunde parola
    m_passwordLineEdit->setGeometry(50, 90, 200, 30);

    m_registerButton = new QPushButton("Register", this);
    m_registerButton->setGeometry(50, 130, 200, 30);

    // Conectează butonul la slotul corespunzător
    connect(m_registerButton, &QPushButton::clicked, this, &RegisterWindow::onRegisterClicked);
}

RegisterWindow::~RegisterWindow()
{}


std::string RegisterWindow::GetUsername()
{
    return m_username;
}

std::string RegisterWindow::GetPassword()
{
    return m_password;
}

bool RegisterWindow::GetHasRegistered()
{
    return m_hasRegistred;
}

void RegisterWindow::onRegisterClicked()
{
    // Implementează logica pentru înregistrare
    m_username = m_usernameLineEdit->text().toUtf8().constData();
    m_password = m_passwordLineEdit->text().toUtf8().constData();
    /*   if (GetUsername().size() != 0)
       {
           std::string name = GetUsername();
           auto response = cpr::Post(cpr::Url{ "http://localhost:18080/CreateGame" },
               cpr::Body(name));
       }*/
    m_lobby = new LobbyWindow(this);
    this->close();
    m_lobby->show();

    // Aici poți adăuga logica pentru a salva datele de înregistrare sau pentru a le trimite undeva
    // De exemplu, poți trimite aceste date la un server pentru înregistrare
}
