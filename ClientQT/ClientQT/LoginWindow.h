#pragma once

#include <QMainWindow>
#include "ui_LoginWindow.h"
#include <QPushButton>
#include "ClientQT.h"
class LoginWindow : public QMainWindow
{
	Q_OBJECT

public:
	LoginWindow(QWidget *parent = nullptr);
	~LoginWindow();
private slots:
	void joinGame();
private:
	Ui::LoginWindowClass ui;
	QPushButton* m_colorButton;
};
