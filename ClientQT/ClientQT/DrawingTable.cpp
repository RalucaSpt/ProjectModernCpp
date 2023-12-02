#include "DrawingTable.h"

DrawingTable::DrawingTable()
{
}

DrawingTable::DrawingTable(int height, int width, int xStart, int yStart)
	:m_height{20/100*height},m_width{20/100*width},m_xStart{xStart},m_yStart{yStart}
{
    std::vector<QColor> line;
    for (int y = 0; y < m_height; y++)
    {
        for (int x = 0; x < m_width; x++)
        {
            line.push_back(Qt::white);
        }
        m_tablePixels.push_back(line);
        line.clear();
    }
    ChangeIsSet(true);
}

void DrawingTable::SetTable(int height, int width, int xStart, int yStart)
{
    m_height = (50.0 / 100.0) * height;
    m_width = (50.0 / 100.0) * width;
    m_xStart = xStart;
    m_yStart = yStart;
    std::vector<QColor> line;
    for (int y = 0; y < m_height; y++)
    {
        for (int x = 0; x < m_width; x++)
        {
            line.push_back(Qt::white);
        }
        m_tablePixels.push_back(line);
        line.clear();
    }
    ChangeIsSet(true);
}

void DrawingTable::UpdatePixelColor(int x, int y)
{
	m_tablePixels[y - m_yStart][x - m_xStart] = Qt::black;
	m_tablePixels[y - m_yStart-1][x - m_xStart] = Qt::black;
	m_tablePixels[y - m_yStart+1][x - m_xStart] = Qt::black;
	m_tablePixels[y - m_yStart-1][x - m_xStart+1] = Qt::black;
	m_tablePixels[y - m_yStart-1][x - m_xStart-1] = Qt::black;
	m_tablePixels[y - m_yStart+1][x - m_xStart+1] = Qt::black;
	m_tablePixels[y - m_yStart+1][x - m_xStart-1] = Qt::black;
	m_tablePixels[y - m_yStart][x - m_xStart-1] = Qt::black;
	m_tablePixels[y - m_yStart][x - m_xStart+1] = Qt::black;
}

void DrawingTable::PrintMatrix(QPainter& p)
{
    p.setPen(Qt::white);
    for (int x = 0; x < m_width; x++) {
        for (int y = 0; y < m_height; y++) {
            if (m_tablePixels[y][x] == Qt::black)
            {
                p.setPen(Qt::black);
                p.drawPoint(x + m_xStart, y + m_yStart);
                p.setPen(Qt::white);
            }
            else
            {
                p.setPen(Qt::white);
                p.drawPoint(x + m_xStart, y + m_yStart);
            }
        }
    }
}

void DrawingTable::UpdatePixelColor(int x, int y, QColor color)
{
    int correctedX = x - m_xStart;
    int correctedY = y - m_yStart;

    if (correctedX >= 0 && correctedX < m_width && correctedY >= 0 && correctedY < m_height)
    {
        m_tablePixels[correctedY][correctedX] = color;

    }
}

bool DrawingTable::IsSet()
{
    return m_isSet;
}

void DrawingTable::ChangeIsSet(bool b)
{
    m_isSet = b;
}

int DrawingTable::GetHeight()
{
    return m_height;
}

int DrawingTable::GetWidth()
{
    return m_width;
}

int DrawingTable::GetX()
{
    return m_xStart;
}

int DrawingTable::GetY()
{
    return m_yStart;
}
