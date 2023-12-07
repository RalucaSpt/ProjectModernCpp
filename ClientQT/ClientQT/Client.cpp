#include "Client.h"

ClientQT::ClientQT(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    QPalette pal = this->palette();
    pal.setColor(QPalette::Window, Qt::red);
    this->setPalette(pal);
    this->resize(1300, 700);

    m_colorButton = new QPushButton("Alege Culoare", this);
    m_colorButton->setGeometry(10, 10, 120, 30);
    connect(m_colorButton, &QPushButton::clicked, this, &ClientQT::openColorDialog);
    m_thicknessSlider = new QSlider(Qt::Horizontal, this);
    m_thicknessSlider->setRange(1, 10);
    m_thicknessSlider->setValue(m_lineThickness);
    m_thicknessSlider->setGeometry(50, 50, 200, 30);
    connect(m_thicknessSlider, &QSlider::valueChanged, this, &ClientQT::onThicknessChanged);
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
    if (/* (event->button() == Qt::LeftButton) && */ m_drawing) {
        QPoint currentPoint = event->pos();
        if (currentPoint.x() < m_table.GetWidth() + m_table.GetX() && currentPoint.x() >= m_table.GetX() &&
            currentPoint.y() < m_table.GetHeight() + m_table.GetY() && currentPoint.y() >= m_table.GetY())
        {
            m_table.UpdatePixelColor(currentPoint.x(), currentPoint.y(), m_currentColor, m_lineThickness);

        }
    }

}

void ClientQT::mouseReleaseEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton && m_drawing) {
        m_drawing = false;
        update(m_table.GetX(), m_table.GetY(),m_table.GetWidth(),m_table.GetHeight());
    }
}

void ClientQT::openColorDialog()
{
    QColor color = QColorDialog::getColor(m_currentColor, this, "Selecteaza Culoare");
    if (color.isValid())
    {
        m_currentColor = color;
    }
}

void ClientQT::onThicknessChanged(int thickness)
{
    m_lineThickness = thickness;
}
