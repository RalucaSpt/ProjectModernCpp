#include "LobbyWindow.h"

LobbyWindow::LobbyWindow(QWidget* parent)
    : QMainWindow(parent)
{
    // Setează dimensiunile și titlul ferestrei
    this->setWindowTitle("Lobby");
    this->setFixedSize(400, 300);

    // Creează lista de jocuri
    m_gamesList = new QListWidget(this);
    m_gamesList->setGeometry(50, 50, 300, 150); // Ajustează aceste valori după necesități

    // Creează butonul pentru a crea un joc nou
    m_createGameButton = new QPushButton("Creează Joc", this);
    m_createGameButton->setGeometry(50, 220, 100, 30);
    connect(m_createGameButton, &QPushButton::clicked, this, &LobbyWindow::onCreateGameClicked);

    // Creează butonul pentru a te alătura unui joc
    m_joinGameButton = new QPushButton("Alătură-te Jocului", this);
    m_joinGameButton->setGeometry(250, 220, 100, 30);
    connect(m_joinGameButton, &QPushButton::clicked, this, &LobbyWindow::onJoinGameClicked);
}

LobbyWindow::~LobbyWindow()
{
    // Distrugere resurse dacă este necesar
}

void LobbyWindow::onCreateGameClicked()
{
    // Logica pentru a crea un joc nou
}

void LobbyWindow::onJoinGameClicked()
{
    // Logica pentru a te alătura unui joc selectat din lista
}
