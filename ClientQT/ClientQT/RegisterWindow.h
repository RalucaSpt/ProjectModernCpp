#pragma once

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>

class RegisterWindow : public QMainWindow
{
    Q_OBJECT

public:
    RegisterWindow(QWidget* parent = nullptr);
    ~RegisterWindow();
    std::string GetUsername();
    std::string GetPassword();
private slots:
    void onRegisterClicked();

private:
    QLineEdit* m_usernameLineEdit;
    QLineEdit* m_passwordLineEdit;
    QPushButton* m_registerButton;

    std::string m_username;
    std::string m_password;
};

