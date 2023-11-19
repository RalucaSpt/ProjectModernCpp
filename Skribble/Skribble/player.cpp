module player;
import<format>;
import <string>;

using skribble::Player;

Player::Player()
	:m_idPlayer{ 0 }, m_score{ 0 }, m_drawingStatus{Player::DrawingStatus::NotDrawing}
{

}

Player::Player(uint16_t IdPlayer, uint16_t score, const std::string& name):
	m_idPlayer { IdPlayer },
	m_score{ score },
	m_name{ name },
	m_drawingStatus{ DrawingStatus::NotDrawing }
{

}

Player::Player(const Player& player)
	:m_idPlayer{ player.m_idPlayer }, m_score{ player.m_score }, m_drawingStatus{ player.m_drawingStatus }
{

}

Player::~Player()
{

}

Player& Player::operator=(const Player& player)
{
	if (this != &player)
	{
		m_idPlayer = player.m_idPlayer;
		m_score = player.m_score;
	}
	return *this;
}

uint16_t skribble::Player::GetIdPlayer() const {
	return m_idPlayer;
}

uint16_t skribble::Player::GetScore() const
{
	return m_score;
}

uint16_t skribble::Player::GetCorrectAnswerTime()
{
	return m_correctAnswerTime;
}

std::string Player::GetName() const
{
	return m_name;
}

Player::DrawingStatus skribble::Player::GetIsDrawing() const
{
	return m_drawingStatus;
}

void Player::SetIsDrawing(DrawingStatus isDrawing)
{
	m_drawingStatus = isDrawing;
}

void Player::setName(const std::string& name)
{
	if (name.empty()) {
		std::cerr << "Player name cannot be empty." << std::endl;
		return;
	}
	m_name = name;
}

void skribble::Player::AddScore(uint16_t points)
{
	if (m_drawingStatus == DrawingStatus::Drawing) {
		float alfa = 0.0; // in alfa calculam media timpilor la care s au oferit raspunsurile corecte
	}
	else if (m_drawingStatus == DrawingStatus::NotDrawing) {
		uint8_t seconds; //numarul de secunde in care jucatorul a ghicit cuvantul
		m_score = ((60 - seconds) * 100) / 30;
	}
	
}

void skribble::Player::SubtractScore(uint16_t points)
{
	if (m_drawingStatus == DrawingStatus::Drawing) {
		//daca niciun jucator nu a ghicit cuvantul
		points = 100;
		m_score -= points;
	}
	else if(m_drawingStatus == DrawingStatus::NotDrawing) {
		//daca jucatorul nu a ghicit cuvantul
		points = 50;
		m_score -= points;
	}
}

void skribble::Player::ResetScore()
{
	m_score = 0;
}

bool skribble::Player::operator==(const Player& other) const
{
	return m_idPlayer==other.m_idPlayer;
}

bool skribble::Player::operator!=(const Player& other) const
{
	return  m_idPlayer != other.m_idPlayer;
}



