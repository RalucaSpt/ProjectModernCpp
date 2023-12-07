#pragma once
#include <QSlider>
#include <QtWidgets/QMainWindow>
#include "ui_Client.h"
#include <qpainter.h>
#include <QMouseEvent>
#include <QPushButton>
#include <QColorDialog>

class ClientQT : public QMainWindow
{
    Q_OBJECT

public:
    ClientQT(QWidget *parent = nullptr);
    ~ClientQT();
    void paintEvent(QPaintEvent* event);
    void mousePressEvent(QMouseEvent* e);

    void mouseMoveEvent(QMouseEvent* event);

    void mouseReleaseEvent(QMouseEvent* event);

    void onThicknessChanged(int thickness);

    void startGame();
private:
    Ui::MainWindow ui;
    bool m_drawing = false;
    
    QImage canvas;
    QPoint lastPoint;
    
    QColor m_currentColor;

    QPushButton* m_colorButton;
    QSlider* m_thicknessSlider;

    int m_lineThickness = 1;

    bool start = false;

private slots:
    void openColorDialog();
};
