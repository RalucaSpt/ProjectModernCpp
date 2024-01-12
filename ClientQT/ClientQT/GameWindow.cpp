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
	setButtonColorMap();
	connectColorButtonsToSlots();
}

GameWindow::~GameWindow()
{}


void GameWindow::paintEvent(QPaintEvent* event)
{
	QPainter p(this);
	p.drawImage(m_canvasCoords.x(), m_canvasCoords.y(), canvas);
	setFrameColor();	
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

void GameWindow::onThicknessChanged()
{
	m_lineThickness = m_thicknessSlider->value();
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
	std::vector<std::pair<QString, int>> data = { {"Jucatocsnjknkjndcacdr1", 100}, {"Jucator2", 150}, {"Jucator3", 120} };

	ui.tableWidgetScoreboard->setRowCount(data.size());
	ui.tableWidgetScoreboard->setColumnWidth(1, 1);
	QHeaderView* headerColoane = ui.tableWidgetScoreboard->horizontalHeader();
	headerColoane->setStyleSheet("QHeaderView::section { background-color: rgb(205, 225, 255) }");

	// Setează culorile pentru headerul vertical (rânduri)
	QHeaderView* headerRinduri = ui.tableWidgetScoreboard->verticalHeader();
	headerRinduri->setStyleSheet("QHeaderView::section { background-color: rgb(205, 225, 255) }");


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
	m_textBox = ui.chat;
	m_textBox->setSelectionMode(QAbstractItemView::NoSelection);
	m_textBox->setFocusPolicy(Qt::NoFocus);

	m_chatMessage = ui.textBox;

	m_sendButton = ui.sendButton;
	connect(m_sendButton, &QPushButton::clicked, this, &GameWindow::sendMessage);
}

void GameWindow::initTimer()
{

}


void GameWindow::initButtons()
{
	m_colorButton = ui.pushButtonChooseColor;
	connect(m_colorButton, &QPushButton::clicked, this, &GameWindow::openColorDialog);


	m_colorButton = new QPushButton("Start", this);
	m_colorButton->setGeometry(150, 10, 120, 30);
	connect(m_colorButton, &QPushButton::clicked, this, &GameWindow::startGame);
}

void GameWindow::initSlider()
{
	m_thicknessSlider = ui.horizontalSlider;
	m_thicknessSlider->setValue(m_lineThickness);
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

void GameWindow::setButtonColorMap()
{
	buttonColorMap[ui.blackButton] = QColor(0, 0, 0);  // black
	buttonColorMap[ui.whiteButton] = QColor(255, 255, 255);  // white
	buttonColorMap[ui.greyButton] = QColor(189, 189, 189);
	buttonColorMap[ui.darkGreyButton] = QColor(72, 72, 7);
	buttonColorMap[ui.redButton] = QColor(255, 0, 0);  // red
	buttonColorMap[ui.greenButton] = QColor(170, 255, 0);  // green
	buttonColorMap[ui.darkRedButtpn] = QColor(170, 0, 0);  // dark red
	buttonColorMap[ui.yellowButton] = QColor(255, 242, 99);  // yellow
	buttonColorMap[ui.orangeButton] = QColor(255, 170, 0);  // ornage
	buttonColorMap[ui.nudeButton] = QColor(255, 220, 179);  // nude
	buttonColorMap[ui.darkNudeButton] = QColor(197, 139, 88);
	buttonColorMap[ui.darkGreenButton] = QColor(0, 170, 0);
	buttonColorMap[ui.blueButton] = QColor(35, 215, 255);
	buttonColorMap[ui.darkBlueButton] = QColor(0, 54, 180);
	buttonColorMap[ui.purpleButtton] = QColor(170, 0, 255);
	buttonColorMap[ui.darkPurpleButtton] = QColor(85, 0, 127);
	buttonColorMap[ui.pinkButton] = QColor(255, 187, 199);
	buttonColorMap[ui.darkPinkButton] = QColor(255, 93, 131);
	buttonColorMap[ui.brownButton] = QColor(170, 85, 0);
	buttonColorMap[ui.darkBrownButton] = QColor(109, 55, 0);
}

void GameWindow::connectColorButtonsToSlots()
{
	connect(ui.blackButton, &QPushButton::clicked, this, &GameWindow::onColorButtonClicked);
	connect(ui.whiteButton, &QPushButton::clicked, this, &GameWindow::onColorButtonClicked);
	connect(ui.redButton, &QPushButton::clicked, this, &GameWindow::onColorButtonClicked);
	connect(ui.greenButton, &QPushButton::clicked, this, &GameWindow::onColorButtonClicked);
	connect(ui.darkRedButtpn, &QPushButton::clicked, this, &GameWindow::onColorButtonClicked);
	connect(ui.yellowButton, &QPushButton::clicked, this, &GameWindow::onColorButtonClicked);
	connect(ui.orangeButton, &QPushButton::clicked, this, &GameWindow::onColorButtonClicked);
	connect(ui.nudeButton, &QPushButton::clicked, this, &GameWindow::onColorButtonClicked);
	connect(ui.darkNudeButton, &QPushButton::clicked, this, &GameWindow::onColorButtonClicked);
	connect(ui.darkGreenButton, &QPushButton::clicked, this, &GameWindow::onColorButtonClicked);
	connect(ui.blueButton, &QPushButton::clicked, this, &GameWindow::onColorButtonClicked);
	connect(ui.darkBlueButton, &QPushButton::clicked, this, &GameWindow::onColorButtonClicked);
	connect(ui.purpleButtton, &QPushButton::clicked, this, &GameWindow::onColorButtonClicked);
	connect(ui.darkPurpleButtton, &QPushButton::clicked, this, &GameWindow::onColorButtonClicked);
	connect(ui.pinkButton, &QPushButton::clicked, this, &GameWindow::onColorButtonClicked);
	connect(ui.darkPinkButton, &QPushButton::clicked, this, &GameWindow::onColorButtonClicked);
	connect(ui.brownButton, &QPushButton::clicked, this, &GameWindow::onColorButtonClicked);
	connect(ui.darkBrownButton, &QPushButton::clicked, this, &GameWindow::onColorButtonClicked);
}

void GameWindow::onColorButtonClicked()
{
	QObject* senderObj = sender();
	if (!senderObj) {
		return;
	}

	QPushButton* clickedButton = qobject_cast<QPushButton*>(senderObj);
	if (!clickedButton) {
		return;
	}

	if (buttonColorMap.isEmpty()) {
		setButtonColorMap();
	}

	if (buttonColorMap.contains(clickedButton)) {
		m_currentColor = buttonColorMap[clickedButton];
	}
}

void GameWindow::on_resetCanvasButton_clicked()
{
	canvas.fill(Qt::white);
	update();
}

void GameWindow::setFrameColor()
{
	ui.frame->setStyleSheet("background-color: " + m_currentColor.name());
}


