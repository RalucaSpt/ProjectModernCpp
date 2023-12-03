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

void DrawingTable::UpdatePixelColor(int x, int y,QColor color)
{
	m_tablePixels[y - m_yStart][x - m_xStart] = color;
	m_tablePixels[y - m_yStart-1][x - m_xStart] = color;
	m_tablePixels[y - m_yStart+1][x - m_xStart] = color;
	m_tablePixels[y - m_yStart-1][x - m_xStart+1] = color;
	m_tablePixels[y - m_yStart-1][x - m_xStart-1] = color;
	m_tablePixels[y - m_yStart+1][x - m_xStart+1] = color;
	m_tablePixels[y - m_yStart+1][x - m_xStart-1] = color;
	m_tablePixels[y - m_yStart][x - m_xStart-1] = color;
	m_tablePixels[y - m_yStart][x - m_xStart+1] = color;
}

void DrawingTable::PrintMatrix(QPainter& p)
{
    for (int y = 0; y < m_height; y++) {
        for (int x = 0; x < m_width; x++) {

            p.setPen(QPen(m_tablePixels[y][x]));
            p.drawPoint(x + m_xStart, y + m_yStart);
        }
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
