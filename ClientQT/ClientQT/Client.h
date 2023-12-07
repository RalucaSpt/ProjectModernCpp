#pragma once
#include <QSlider>
#include <QtWidgets/QMainWindow>
#include "ui_Client.h"
#include <qpainter.h>
#include <QMouseEvent>
#include <QPushButton>
#include <QColorDialog>
#include "DrawingTable.h"
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
private:
    Ui::MainWindow ui;
    bool m_drawing = false;
    DrawingTable m_table;
    QPoint m_lastPoint;
    QColor m_currentColor;
    QPushButton* m_colorButton;
    QSlider* m_thicknessSlider;
    int m_lineThickness = 1;
private slots:
    void openColorDialog();
};
