#include "SkribbleClient.h"

SkribbleClient::SkribbleClient(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    QPalette pal = this->palette();
    pal.setColor(QPalette::Window, Qt::red);
    this->setPalette(pal);
    this->resize(1300, 700);

    m_colorButton = new QPushButton("Alege Culoare", this);
    m_colorButton->setGeometry(10, 10, 120, 30);
    connect(m_colorButton, &QPushButton::clicked, this, &SkribbleClient::openColorDialog);


    m_colorButton = new QPushButton("Start", this);
    m_colorButton->setGeometry(150, 10, 120, 30);
    connect(m_colorButton, &QPushButton::clicked, this, &SkribbleClient::startGame);

    m_thicknessSlider = new QSlider(Qt::Horizontal, this);
    m_thicknessSlider->setRange(1, 10);
    m_thicknessSlider->setValue(m_lineThickness);
    m_thicknessSlider->setGeometry(50, 50, 200, 30);
    connect(m_thicknessSlider, &QSlider::valueChanged, this, &SkribbleClient::onThicknessChanged);

    canvas = QImage(width() * 0.5, height() * 0.5, QImage::Format_ARGB32);
    canvas.fill(Qt::white);
    m_drawing = false;
}

SkribbleClient::~SkribbleClient()
{}

void SkribbleClient::paintEvent(QPaintEvent* event)
{
    QPainter p(this);
    p.drawImage(100, 100, canvas);
}

void SkribbleClient::mousePressEvent(QMouseEvent* e)
{
    if (e->button() == Qt::LeftButton) {
        lastPoint = e->pos();

        lastPoint -= QPoint(100, 100); // Adjust for canvas position
        m_drawing = true;
    }
}

void SkribbleClient::mouseMoveEvent(QMouseEvent* e)
{
    if (/* (event->button() == Qt::LeftButton) &&*/  m_drawing) {
        if (e->pos().x() < 100 + width() * 50 / 100 && e->pos().x() >= 100 &&
            e->pos().y() < 100 + height() * 50 / 100 && e->pos().y() >= 100)
        {
            QPainter p(&canvas);
            QPen pen(m_currentColor, m_lineThickness);
            p.setPen(pen);
            p.drawLine(lastPoint, e->pos() - QPoint(100, 100)); // Adjust for canvas position
            lastPoint = e->pos() - QPoint(100, 100); // Adjust for canvas position
            update();
        }
    }

}

void SkribbleClient::mouseReleaseEvent(QMouseEvent* e)
{
    if (e->button() == Qt::LeftButton && m_drawing) {

        QPainter p(&canvas);
        QPen pen(m_currentColor, m_lineThickness);
        p.setPen(pen);
        p.drawLine(lastPoint, e->pos() - QPoint(100, 100)); // Adjust for canvas position
        lastPoint = e->pos() - QPoint(100, 100); // Adjust for canvas position
        m_drawing = false;
        update();
    }
}

void SkribbleClient::openColorDialog()
{
    QColor color = QColorDialog::getColor(m_currentColor, this, "Selecteaza Culoare");
    if (color.isValid())
    {
        m_currentColor = color;
    }
}

void SkribbleClient::onThicknessChanged(int thickness)
{
    m_lineThickness = thickness;
}


void SkribbleClient::startGame()
{
    start = true;
    update();
}
