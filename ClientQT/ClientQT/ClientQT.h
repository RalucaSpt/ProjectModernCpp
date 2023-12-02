#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ClientQT.h"
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
private:
    Ui::ClientQTClass ui;
    bool m_drawing = false;
    DrawingTable m_table;
    QPoint m_lastPoint;
    QColor m_currentColor;
    QPushButton* m_colorButton;
private slots:
    void openColorDialog();
};
