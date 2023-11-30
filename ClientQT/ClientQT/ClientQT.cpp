#include "ClientQT.h"

ClientQT::ClientQT(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
}

ClientQT::~ClientQT()
{}

void ClientQT::paintEvent(QPaintEvent * event)
{
    if (!m_table.IsSet())
    {
        m_table.SetTable(height(), width(), 100, 100);
    }
    QPainter painter(this);
    m_table.PrintMatrix(painter);
   
    qDebug() << this->size();
}

void ClientQT::mousePressEvent(QMouseEvent* e)
{
    if (e->button() == Qt::LeftButton) {
        m_drawing = true;
    }
}

void ClientQT::mouseMoveEvent(QMouseEvent* event)
{
    QPainter painter(this);
    if (/*(event->button() == Qt::LeftButton) &&*/ m_drawing) {
        QPoint currentPoint = event->pos();
        if (currentPoint.x() < m_table.GetWidth() + m_table.GetX() && currentPoint.x() >= m_table.GetX() &&
            currentPoint.y() < m_table.GetHeight() + m_table.GetY() && currentPoint.y() >= m_table.GetY())
        {
            m_table.UpdatePixelColor(currentPoint.x(), currentPoint.y());
            
        }
    }
    
}

void ClientQT::mouseReleaseEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton && m_drawing) {
        m_drawing = false;
    }
    update();
}


