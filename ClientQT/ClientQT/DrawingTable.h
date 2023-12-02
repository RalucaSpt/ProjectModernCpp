#pragma once
#include <qcolor.h>
#include <qpainter.h>
#include <QtWidgets/QMainWindow>
class DrawingTable
{
public:
	DrawingTable();
	DrawingTable(int height, int width,int xStart,int yStart);
	void SetTable(int height, int width, int xStart, int yStart);
	void UpdatePixelColor(int x,int y);
	void PrintMatrix(QPainter& p);
	bool IsSet();
	void ChangeIsSet(bool b);
	void UpdatePixelColor(int x, int y, QColor color);

	int GetHeight();
	int GetWidth();
	int GetX();
	int GetY();
private:
	int m_height;
	int m_width;
	int m_xStart;
	int m_yStart;
	bool m_isSet = false;
	std::vector<std::vector<QColor>> m_tablePixels;
	
};

