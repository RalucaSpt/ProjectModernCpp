#pragma once

#include <QMainWindow>
#include "ui_RegisterWindow.h"

#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
//#include "LobbyWindow.h"
#include <cpr/cpr.h>


#include "LobbyWindow.h"
class RegisterWindow : public QMainWindow
{
	Q_OBJECT

public:
	RegisterWindow(QWidget *parent = nullptr);
	~RegisterWindow();

    std::string GetUsername();
    std::string GetPassword();
    bool GetHasRegistered();
private slots:
    void onRegisterClicked();

private:
    Ui::RegisterWindowClass ui;
    QLineEdit* m_usernameLineEdit;
    QLineEdit* m_passwordLineEdit;
    QPushButton* m_registerButton;

    LobbyWindow* m_lobby;

    bool m_hasRegistred = false;
    std::string m_username;
    std::string m_password;
};
