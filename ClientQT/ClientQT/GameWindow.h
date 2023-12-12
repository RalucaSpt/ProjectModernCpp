#pragma once

#include <QMainWindow>
#include "ui_GameWindow.h"
#include <qpainter.h>
#include <QMouseEvent>
#include <QPushButton>
#include <QColorDialog>
#include <QSlider>
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

private slots:
    void openColorDialog();
private:
    Ui::GameWindowClass ui;
    bool m_drawing = false;

    QImage canvas;
    QPoint lastPoint;

    QColor m_currentColor;

    QPushButton* m_colorButton;
    QSlider* m_thicknessSlider;

    int m_lineThickness = 1;

    bool start = false;

};
