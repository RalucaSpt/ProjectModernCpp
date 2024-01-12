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
#include"Image.h"


enum PlayerType { DRAWER, GUESSER };
enum GameStatus { NOT_STARTED, STARTED, FINISHED };

class GameWindow : public QMainWindow
{
	Q_OBJECT

public:
	GameWindow(QWidget* parent = nullptr);
	~GameWindow()=default;

	void paintEvent(QPaintEvent* event);
	void mousePressEvent(QMouseEvent* e);
	void mouseMoveEvent(QMouseEvent* event);
	void mouseReleaseEvent(QMouseEvent* event);
	void startGame();
	void SetName(std::string name);

	void initScoreBoard();
	void initCanvas();
	void initChatBox();
	void initButtons();
	void initSlider();
	void initTimer();
	void connectColorButtonsToSlots();
	void setButtonColorMap();
	void changePlayerType();


private slots:
	void onThicknessChanged();
	void openColorDialog();
	void sendMessage();
	void UpdateChat();
	void onColorButtonClicked();
	void on_resetCanvasButton_clicked();
	void setFrameColor();
	void updateTimer();

private:
	std::string m_playerName = "Talica";
	PlayerType m_playerType;
	bool m_isDrawing;

private:
	Ui::GameWindowClass ui;
	Canvas* m_canvas;
	size_t m_lineThickness;

	QTimer* m_timer;
	uint16_t m_roundTimeRemaining;

	QMap<QPushButton*, QColor> buttonColorMap;
	GameStatus m_gameStatus;
};
