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

private slots:
    void onRegisterClicked();

private:
    QLineEdit* m_usernameLineEdit;
    QLineEdit* m_passwordLineEdit;
    QPushButton* m_registerButton;
};

