#include "GameWindow.h"
#include <qtablewidget.h>

GameWindow::GameWindow(QWidget* parent)
	: QMainWindow(parent),
	m_drawing(false),
	m_startGame(false)
{
	ui.setupUi(this);
	initCanvas();
	initSlider();
	initButtons();
	initChatBox();
	initScoreBoard();
	initTimer();
}

GameWindow::~GameWindow()
{}


void GameWindow::paintEvent(QPaintEvent* event)
{
	QPainter p(this);
	p.drawImage(m_canvasCoords.x(), m_canvasCoords.y(), canvas);
}

void GameWindow::mousePressEvent(QMouseEvent* e)
{
	if (e->button() == Qt::LeftButton)
	{
		lastPoint = e->pos();
		lastPoint -= m_canvasCoords;
		m_drawing = true;
	}
}

void GameWindow::mouseMoveEvent(QMouseEvent* e)
{
	if (m_drawing)
	{
		if (e->pos().x() < m_canvasCoords.x() + kCanvasWidth && e->pos().x() >= m_canvasCoords.x() &&
			e->pos().y() < m_canvasCoords.y() + kCanvasHeight && e->pos().y() >= m_canvasCoords.y())
		{
			QPainter p(&canvas);
			QPen pen(m_currentColor, m_lineThickness);
			p.setPen(pen);
			p.drawLine(lastPoint, e->pos() - m_canvasCoords);
			lastPoint = e->pos() - m_canvasCoords;
			update();
		}
	}

}

void GameWindow::mouseReleaseEvent(QMouseEvent* e)
{
	if (e->button() == Qt::LeftButton && m_drawing)
	{
		QPainter p(&canvas);
		QPen pen(m_currentColor, m_lineThickness);
		p.setPen(pen);
		p.drawLine(lastPoint, e->pos() - m_canvasCoords);
		lastPoint = e->pos() - m_canvasCoords;
		m_drawing = false;
		update();
	}
}

void GameWindow::openColorDialog()
{
	if (QColor color = QColorDialog::getColor(m_currentColor, this, "Selecteaza Culoare"); color.isValid())
	{
		m_currentColor = color;
	}
}

void GameWindow::onThicknessChanged(int thickness)
{
	m_lineThickness = thickness;
}

void GameWindow::startGame()
{
	m_startGame = true;
	update();
}

void GameWindow::SetName(std::string name)
{
	m_playerName = name;
}

void GameWindow::initScoreBoard()
{
	//
	std::vector<std::pair<QString, int>> data = { {"Jucator1", 100}, {"Jucator2", 150}, {"Jucator3", 120} };

	ui.tableWidgetScoreboard->setRowCount(data.size());


	for (int i = 0; i < data.size(); ++i) {
		QTableWidgetItem* nameItem = new QTableWidgetItem(data[i].first);
		QTableWidgetItem* scoreItem = new QTableWidgetItem(QString::number(data[i].second));

		ui.tableWidgetScoreboard->setItem(i, 0, nameItem);
		ui.tableWidgetScoreboard->setItem(i, 1, scoreItem);

		//timer = new QTimer(this);
		//connect(timer, &QTimer::timeout, this, &GameWindow::UpdateChat);
		//timer->start(1000); 
	}
	ui.tableWidgetScoreboard->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.tableWidgetScoreboard->setFocusPolicy(Qt::NoFocus);
}

void GameWindow::initCanvas()
{
	QPalette pal = this->palette();
	pal.setColor(QPalette::Window, QColor(205, 225, 255));
	this->setPalette(pal);
	this->resize(1300, 700);
	canvas = QImage(kCanvasWidth, kCanvasHeight, QImage::Format_ARGB32);
	canvas.fill(Qt::white);
}

void GameWindow::initChatBox()
{
	m_textBox = new QListWidget(this);
	m_textBox->setGeometry(m_textBoxCoords.x() + 90, m_textBoxCoords.y(), kTextBoxWidth, kTextBoxHeight - 35);
	m_textBox->setSelectionMode(QAbstractItemView::NoSelection);

	m_chatMessage = new QLineEdit(this);
	m_chatMessage->setGeometry(845 + 145, 570, 245, 30);

	m_sendButton = new QPushButton("Send", this);
	m_sendButton->setGeometry(850 + 245 + 145, 570, 50, 30);
	connect(m_sendButton, &QPushButton::clicked, this, &GameWindow::sendMessage);
}

void GameWindow::initTimer()
{

}

void GameWindow::initButtons()
{
	m_colorButton = new QPushButton("Alege Culoare", this);
	m_colorButton->setGeometry(10, 10, 120, 30);
	connect(m_colorButton, &QPushButton::clicked, this, &GameWindow::openColorDialog);


	m_colorButton = new QPushButton("Start", this);
	m_colorButton->setGeometry(150, 10, 120, 30);
	connect(m_colorButton, &QPushButton::clicked, this, &GameWindow::startGame);
}

void GameWindow::initSlider()
{
	m_thicknessSlider = new QSlider(Qt::Horizontal, this);
	m_thicknessSlider->setRange(1, 10);
	m_thicknessSlider->setValue(m_lineThickness);
	m_thicknessSlider->setGeometry(50 + 50, 50, 200, 30);
	connect(m_thicknessSlider, &QSlider::valueChanged, this, &GameWindow::onThicknessChanged);
}

void GameWindow::sendMessage()
{
	std::string message{ m_chatMessage->text().toUtf8().constData() };
	if (m_textBox->count() > 200)
	{
		auto response = cpr::Get(cpr::Url{ "http://localhost:18080/ClearChat" });
	}
	auto response = cpr::Put(cpr::Url{ "http://localhost:18080/SendMessage" }, cpr::Parameters{ { "username", m_playerName},
							{"message", message} });
	m_chatMessage->clear();
}

void GameWindow::UpdateChat()
{
	auto responseMessages = cpr::Get(cpr::Url{ "http://localhost:18080/GetMessage" });
	auto responseRows = crow::json::load(responseMessages.text);
	if (responseRows.size() != 0)
	{
		m_textBox->clear();
		for (const auto& responseRow : responseRows)
		{
			std::string message;
			std::string mess = std::string(responseRow["message"]);
			if (std::string name = std::string(responseRow["username"]); name == m_playerName)
				message = "You: " + mess;
			else
			{
				message = name + ": " + mess;
			}

			QString qstrMessage;
			for (auto c : message)
			{
				qstrMessage.push_back(c);
			}
			m_textBox->addItem(qstrMessage);

		}
	}
}


