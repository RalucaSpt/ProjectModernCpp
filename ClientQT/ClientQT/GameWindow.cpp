#include "GameWindow.h"
#include <qtablewidget.h>
#include<qdebug.h>

GameWindow::GameWindow(QWidget* parent)
	: QMainWindow{ parent },
	m_canvas{ new Canvas },
	m_lineThickness{ 1 },
	m_playerType{ DRAWER},
	m_gameStatus{ NOT_STARTED }
{
	ui.setupUi(this);

	if (m_playerType== PlayerType::DRAWER)
		ui.stackedWidget->setCurrentIndex(0);
	if (m_playerType == PlayerType::GUESSER)
		ui.stackedWidget->setCurrentIndex(2);


	initCanvas();
	initSlider();
	initButtons();
	initChatBox();
	//initScoreBoard();
	timerScoreboard();
	initTimer();
	setButtonColorMap();
	//connectColorButtonsToSlots();
	initChat();
}

void GameWindow::paintEvent(QPaintEvent* event)
{

	QPainter p(this);
	p.drawImage(m_canvas->Coords.x(), m_canvas->Coords.y(), m_canvas->image);
	setFrameColor();
}

void GameWindow::mousePressEvent(QMouseEvent* e)
{
	if (m_playerType == PlayerType::DRAWER)

		if (e->button() == Qt::LeftButton)
		{
			m_canvas->lastPoint = e->pos();
			m_canvas->lastPoint -= m_canvas->Coords;
			m_isDrawing = true;
		}
}

void GameWindow::mouseMoveEvent(QMouseEvent* e)
{
	if (m_isDrawing)
	{
		if (e->pos().x() < m_canvas->Coords.x() + m_canvas->width && e->pos().x() >= m_canvas->Coords.x() &&
			e->pos().y() < m_canvas->Coords.y() + m_canvas->height && e->pos().y() >= m_canvas->Coords.y())
		{
			QPainter p(&m_canvas->image);
			QPen pen(m_canvas->currentColor, m_lineThickness);
			p.setPen(pen);
			p.drawLine(m_canvas->lastPoint, e->pos() - m_canvas->Coords);
			m_canvas->lastPoint = e->pos() - m_canvas->Coords;
			update();
		}
	}

}

void GameWindow::mouseReleaseEvent(QMouseEvent* e)
{
	if (e->button() == Qt::LeftButton && m_isDrawing)
	{
		QPainter p(&m_canvas->image);
		QPen pen(m_canvas->currentColor, m_lineThickness);
		p.setPen(pen);
		p.drawLine(m_canvas->lastPoint, e->pos() - m_canvas->Coords);
		m_canvas->lastPoint = e->pos() - m_canvas->Coords;
		m_isDrawing = false;
		update();
	}
}

void GameWindow::openColorDialog()
{
	if (QColor color = QColorDialog::getColor(m_canvas->currentColor, this, "Selecteaza Culoare"); color.isValid())
	{
		m_canvas->currentColor = color;
	}
}

void GameWindow::UpdateChat()
{
	auto responseMessages = cpr::Get(cpr::Url{ "http://localhost:18080/GetMessage" });
	auto responseRows = crow::json::load(responseMessages.text);
	if (responseRows.size() != 0)
	{
		ui.chat->clear();
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
			ui.chat->addItem(qstrMessage);

		}
	}
}

void GameWindow::onThicknessChanged()
{
	m_lineThickness = ui.horizontalSlider->value();
}

void GameWindow::StartRound()
{
	//cat timp toti au fost jucatori
}

void GameWindow::SetName(std::string name)
{
	m_playerName = name;
}

void GameWindow::SetPlayerType(PlayerType type)
{
	m_playerType = type;
	if (m_playerType == PlayerType::DRAWER) {
		// Afișează pagina 0 pentru jucătorul Drawer
		ui.stackedWidget->setCurrentIndex(0);
	}
	if (m_playerType == PlayerType::GUESSER) {
		// Afișează pagina 1 pentru jucătorul Guesser
		ui.stackedWidget->setCurrentIndex(2);
	}
}

void GameWindow::SetWords(std::string word1, const std::string& word2, const std::string& word3) //nu pot seta textul butoanelor
{

	//QString q = QString::fromStdString("caine");
	//	ui.chooseWord1->setText(QString::fromStdString("caine"));
	//ui.chooseWord2->setText(QString::fromStdString(word2));
	//ui.chooseWord3->setText(QString::fromStdString(word3));
}

void GameWindow::initScoreBoard()
{
	//std::vector<std::pair<QString, int>> data = { {"Jucatocsnjknkjndcacdr1", 100}, {"Jucator2", 150}, {"Jucator3", 120} };
	std::vector<std::pair<QString, int>> data;
	auto response = cpr::Get(cpr::Url("http://localhost:18080/getPlayersList"));
	auto responseRows = crow::json::load(response.text);
	if (responseRows.size() != 0)
	{
		for (const auto& responseRow : responseRows)
		{
			std::string playerName{ std::string(responseRow["player"]) };
			int playerScore{ std::stoi(std::string(responseRow["score"])) };
			QString name;
			for (auto c : playerName)
			{
				name.push_back(c);
			}
			data.push_back({ name,playerScore });
		}
	}
	

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
	m_canvas->image = QImage(m_canvas->width, m_canvas->height, QImage::Format_ARGB32);
	m_canvas->image.fill(Qt::white);
}

void GameWindow::initChatBox()
{
	ui.chat->setSelectionMode(QAbstractItemView::NoSelection);
	ui.chat->setFocusPolicy(Qt::NoFocus);

	connect(ui.sendButton, &QPushButton::clicked, this, &GameWindow::sendMessage);
}

void GameWindow::initTimer()
{
	m_timer = new QTimer(this);
	m_roundTimeRemaining = 10;
	connect(m_timer, SIGNAL(timeout()), this, SLOT(updateTimer()));
	m_timer->start(1000);//60 milisecunde
}

void GameWindow::initButtons()
{
	connect(ui.pushButtonChooseColor, &QPushButton::clicked, this, &GameWindow::openColorDialog);

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

	connect(ui.chooseWord1, &QPushButton::clicked, this, &GameWindow::onChooseWordClicked);
	connect(ui.chooseWord2, &QPushButton::clicked, this, &GameWindow::onChooseWordClicked);
	connect(ui.chooseWord3, &QPushButton::clicked, this, &GameWindow::onChooseWordClicked);

	//m_colorButton = new QPushButton("Start", this);
	//m_colorButton->setGeometry(150, 10, 120, 30);
	//connect(m_colorButton, &QPushButton::clicked, this, &GameWindow::startGame);
}

void GameWindow::initSlider()
{
	ui.horizontalSlider->setValue(m_lineThickness);
	connect(ui.horizontalSlider, &QSlider::valueChanged, this, &GameWindow::onThicknessChanged);
}

void GameWindow::sendMessage()
{
	std::string message{ ui.textBox->text().toUtf8().constData() };
	if (ui.chat->count() > 200)
	{
		auto response = cpr::Get(cpr::Url{ "http://localhost:18080/ClearChat" });
	}
	auto response = cpr::Put(cpr::Url{ "http://localhost:18080/SendMessage" }, cpr::Parameters{ { "username", m_playerName},
							{"message", message} });
	ui.textBox->clear();
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

void GameWindow::resetRound()
{
	ui.wordLabel->setText(m_guessWord);
	m_canvas->resetCanva();
	m_roundTimeRemaining = 60;
	if (PlayerType::DRAWER == m_playerType)
	{
		ui.stackedWidget->setCurrentIndex(1);
	}
}

void GameWindow::initChat()
{
	m_timerChat = new QTimer(this);
	// Connect the timeout signal to a slot for updating the QListWidget
	connect(m_timerChat, &QTimer::timeout, this, &GameWindow::UpdateChat);
	m_timerChat->start(1000);
}

void GameWindow::timerScoreboard()
{
	m_timerChat = new QTimer(this);
	// Connect the timeout signal to a slot for updating the QListWidget
	connect(m_timerChat, &QTimer::timeout, this, &GameWindow::initScoreBoard);
	m_timerChat->start(5000);
}
//
//void GameWindow::on_resetCanvasButton_clicked()
//{
//
//}

void GameWindow::setFrameColor()
{
	ui.frame->setStyleSheet("background-color: " + m_canvas->currentColor.name());
}

void GameWindow::updateTimer()
{
	if (m_roundTimeRemaining == 0)
	{
		m_guessWord = ui.chooseWord1->text();
		resetRound();
	}
	else
	{
		if (!chooseWordClicked)
		{
			m_roundTimeRemaining--;
			ui.timer->setText(QString::number(m_roundTimeRemaining));
		}
	}
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
		m_canvas->currentColor = buttonColorMap[clickedButton];
	}
}

void GameWindow::onChooseWordClicked()
{
	QObject* senderObj = sender();
	if (!senderObj) {
		return;
	}

	QPushButton* clickedButton = qobject_cast<QPushButton*>(senderObj);
	if (!clickedButton) {
		return;
	}
	m_guessWord = clickedButton->text();
	resetRound();
}



