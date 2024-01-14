#include "LoginWindow.h"
#include<QMessageBox>

LoginWindow::LoginWindow(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	changeToMainPage();
	connect(ui.goToLoginButton, &QPushButton::clicked, this, &LoginWindow::changeToLoginPage);
	connect(ui.goToRegisterButton, &QPushButton::clicked, this, &LoginWindow::changeToRegisterPage);
	connect(ui.exitButton, &QPushButton::clicked, this, &LoginWindow::exitGameWidget);
}

void LoginWindow::changeToMainPage()
{
	ui.stackedWidget->setCurrentIndex(0);
}

void LoginWindow::changeToLoginPage()
{
	ui.stackedWidget->setCurrentIndex(1);
	connect(ui.backButtonLogin, &QPushButton::clicked, this, &LoginWindow::changeToMainPage);
}

void LoginWindow::changeToRegisterPage()
{
	ui.stackedWidget->setCurrentIndex(2);
	connect(ui.backButtonRegister, &QPushButton::clicked, this, &LoginWindow::changeToMainPage);
}

void LoginWindow::changeToLobbyPage()
{
	ui.stackedWidget->setCurrentIndex(3);
	connect(ui.goToJoinGameButton, &QPushButton::clicked, this, &LoginWindow::changeToJoinGamePage);
	connect(ui.goToCreateGameButton, &QPushButton::clicked, this, &LoginWindow::changeToCreateGamePage);
}

void LoginWindow::changeToCreateGamePage()//de verificat de ce nu face conversia din std::string in QString
{
	ui.stackedWidget->setCurrentIndex(4);
	displayGameCode();
}

void LoginWindow::changeToJoinGamePage()
{
	ui.stackedWidget->setCurrentIndex(5);
	//connect(ui.joinGameButton, &QPushButton::clicked, this, &LoginWindow::changeToCreateGamePage);
}

void LoginWindow::exitGameWidget()
{
	this->close();
}

void LoginWindow::displayGameCode()//de verificat de ce nu face conversia din std::string in QString
{

}

void LoginWindow::on_loginButton_clicked()
{
	username = ui.lineEditUsernameLogin->text().toUtf8().constData();
	password = ui.lineEditPasswordLogin->text().toUtf8().constData();


	auto response = cpr::Put(cpr::Url{ "http://localhost:18080/Login" }, cpr::Parameters{ { "username", username},
							 { "password", password } });
	if (response.status_code == 200)

	{
		changeToLobbyPage();
	}
	else
		if (response.status_code == 300)
		{
			QMessageBox::warning(this, "Login", "Username or password is not correct.");
		}
}

void LoginWindow::on_registerButton_clicked()
{
	username = ui.lineEditUsernameRegister->text().toUtf8().constData();
	password = ui.lineEditPasswordRegister->text().toUtf8().constData();


	auto response = cpr::Put(cpr::Url{ "http://localhost:18080/Register" }, cpr::Parameters{ { "username", username},
							 { "password", password } });
	if (response.status_code == 300)
	{
		QMessageBox::warning(this, "Register", "Username already registered!");
	}
	else if (response.status_code == 200)
	{
		changeToLobbyPage();
	}
}

void LoginWindow::on_startGameButton_clicked()
{
	std::string testCode = "testCode";
	auto response = cpr::Put(cpr::Url("http://localhost:18080/CreateGame"), cpr::Parameters{ { "username", username},
							 { "gameCode", testCode } });
	if (response.status_code == 200)
	{
		this->close();

		GameWindow* gameWindow = new GameWindow();
		gameWindow->SetName(username);

		gameWindow->show();
	}
}

void LoginWindow::on_joinGameButton_clicked()
{
	m_gameCode = ui.lineEdit->text().toUtf8().constData();
	auto response = cpr::Get(cpr::Url("http://localhost:18080/joinGame"), cpr::Parameters{ { "gameCode", m_gameCode}, {"username",username} });
	if (response.status_code == 200)
	{
		QString cod = QString::fromUtf8(m_gameCode.c_str());
		ui.showCodeLabel->setText(cod);
		changeToCreateGamePage();
	}
	else
	{
		QMessageBox::warning(this, "JoinGame", "Wrong code!");
	}
}

void LoginWindow::on_goToCreateGameButton_clicked()
{
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist6(1000, 9999);
	//generam random init
	int gameCode = dist6(rng);
	//convertim game code in string
	m_gameCode = std::to_string(gameCode);

	QString code{ QString::number(gameCode) };
	auto response = cpr::Put(cpr::Url("http://localhost:18080/setGameCode"), cpr::Parameters{ { "gameCode", m_gameCode} });
	ui.showCodeLabel->setText(code);
}
