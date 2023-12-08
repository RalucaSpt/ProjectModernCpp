#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_SkribbleClient.h"

#include <qpainter.h>
#include <QMouseEvent>
#include <QPushButton>
#include <QColorDialog>
#include <QSlider>

class SkribbleClient : public QMainWindow
{
    Q_OBJECT

public:
    SkribbleClient(QWidget *parent = nullptr);
    ~SkribbleClient();

    void paintEvent(QPaintEvent* event);

    void mousePressEvent(QMouseEvent* e);

    void mouseMoveEvent(QMouseEvent* event);

    void mouseReleaseEvent(QMouseEvent* event);

    void onThicknessChanged(int thickness);

    void startGame();

private:
    Ui::SkribbleClientClass ui;

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
