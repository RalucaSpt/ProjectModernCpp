#pragma once

#include <QMainWindow>
#include "ui_GameWindow.h"
#include <qpainter.h>
#include <QMouseEvent>
#include <QPushButton>
#include <QColorDialog>
#include <QSlider>
#include <qtextedit.h>
#include <qlistwidget.h>
#include <QLineEdit>
#include <cpr/cpr.h>
#include <qtimer.h>
#include <crow.h>
#include <qstring.h>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <qbuffer.h>
#include"Image.h"


enum PlayerType { DRAWER, GUESSER };
enum GameStatus { NOT_STARTED, STARTED, FINISHED };

class GameWindow : public QMainWindow
{
	Q_OBJECT

public:
	GameWindow(QWidget* parent = nullptr);
	~GameWindow() = default;

	void paintEvent(QPaintEvent* event);
	void mousePressEvent(QMouseEvent* e);
	void mouseMoveEvent(QMouseEvent* event);
	void mouseReleaseEvent(QMouseEvent* event);

	void SetName(std::string name);
	void SetPlayerType(PlayerType type);
	void SetWords(std::string word1, const std::string& word2, const std::string& word3);//de verificat de ce nu face conversia din std::string in QString
	void setButtonColorMap();
	//void setGameStatus(GameStatus status);
	void StartRound();
	void resetRound();

private:
	void initScoreBoard();
	void initCanvas();
	void initChatBox();
	void initButtons();
	void initSlider();
	void initTimer();
	void initChat();
	void timerScoreboard();
	void initWords();

public slots:
	void onThicknessChanged();
	void openColorDialog();
	void sendMessage();
	void UpdateChat();
	void onColorButtonClicked();
	void on_resetCanvasButton_clicked();
	void setFrameColor();
	void onChooseWordClicked();
	void updateTimer();

private:
	std::string m_playerName = "Talica";
	PlayerType m_playerType;
	bool m_isDrawing;
	QString m_guessWord;
	bool chooseWordClicked = false;

private:
	Ui::GameWindowClass ui;
	Canvas* m_canvas;
	size_t m_lineThickness;

	QTimer* m_timer;
	QTimer* m_timerChat;
	QTimer* m_timerScoreboard;

	uint16_t m_roundTimeRemaining;

	QMap<QPushButton*, QColor> buttonColorMap;
	GameStatus m_gameStatus;
};
