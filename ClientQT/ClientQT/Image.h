#pragma once
#include <QImage>

class Canvas {
public:
	Canvas()
		:width{ 650 },
		height{ 440 },
		Coords{ 300,150 },
		image(width, height, QImage::Format_RGB32),
		currentColor(Qt::black)
	{
		image.fill(Qt::white);
	}

	void resetCanva(){image.fill(Qt::white);}

	QImage image;
	QPoint Coords;
	size_t height;
	size_t width;
	QColor currentColor;
	QPoint lastPoint;
};