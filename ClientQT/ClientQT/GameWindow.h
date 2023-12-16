#pragma once

#include <QMainWindow>
#include "ui_GameWindow.h"
#include <qpainter.h>
#include <QMouseEvent>
#include <QPushButton>
#include <QColorDialog>
#include <QSlider>
//#include <qtextedit.h>
#include <qlistwidget.h>
#include <QLineEdit>
#include <cpr/cpr.h>
#include <qtimer.h>
#include <crow.h>
#include <qstring.h>
class GameWindow : public QMainWindow
{
	Q_OBJECT

public:
	GameWindow(QWidget *parent = nullptr);
	~GameWindow();
    void paintEvent(QPaintEvent* event);
    void mousePressEvent(QMouseEvent* e);

    void mouseMoveEvent(QMouseEvent* event);

    void mouseReleaseEvent(QMouseEvent* event);

    void onThicknessChanged(int thickness);

    void startGame();

    void SetName(std::string name);
    
private slots:
    void openColorDialog();
    void sendMessage();
    void UpdateChat();
private:
    std::string m_playerName;
private:
    Ui::GameWindowClass ui;
    bool m_drawing = false;

    QImage canvas;
    QPoint m_canvasCoords{ 100,100 };
    int kCanvasHeight{ 500 };
    int kCanvasWidth{ 650 };

    QPoint lastPoint;

    QColor m_currentColor;

    QPushButton* m_colorButton;
    QSlider* m_thicknessSlider;

    int m_lineThickness = 1;

    //QTextEdit* m_textBox;
    QListWidget* m_textBox;
    QPoint m_textBoxCoords{ 845 ,100 };
    int kTextBoxHeight{ 500 };
    int kTextBoxWidth{ 300 };
    bool start = false;

    QLineEdit* m_chatMessage;
    QPushButton* m_sendButton;
    QTimer* timer;

   

};
