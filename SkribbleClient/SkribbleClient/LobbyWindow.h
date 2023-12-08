#pragma once

#include <QMainWindow>
#include "ui_LobbyWindow.h"

#include <QPushButton>
#include <QListWidget>
#include "SkribbleClient.h"

class LobbyWindow : public QMainWindow
{
	Q_OBJECT

public:
	LobbyWindow(QWidget *parent = nullptr);
	~LobbyWindow();

private slots:
	void onCreateGameClicked();
	void onJoinGameClicked();

private:
	Ui::LobbyWindowClass ui;

private:
	QPushButton* m_createGameButton;
	QPushButton* m_joinGameButton;
	QListWidget* m_gamesList;

	SkribbleClient* m_gameWindow;
};
