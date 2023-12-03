#pragma once

#include <QMainWindow>
#include <QPushButton>
#include <QListWidget>

class LobbyWindow : public QMainWindow
{
    Q_OBJECT

public:
    LobbyWindow(QWidget* parent = nullptr);
    ~LobbyWindow();

private slots:
    void onCreateGameClicked();
    void onJoinGameClicked();

private:
    QPushButton* m_createGameButton;
    QPushButton* m_joinGameButton;
    QListWidget* m_gamesList;
};
