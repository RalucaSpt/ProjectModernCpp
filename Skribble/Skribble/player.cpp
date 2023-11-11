module player;
import<format>;
import <string>;

using skribble::Player;

Player::Player()
	:m_idPlayer{ 0 }, m_score{ 0 }, m_drawingStatus{ DrawingStatus::NotDrawing }
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
		m_drawingStatus = player.m_drawingStatus;
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

std::string Player::GetName() const
{
	return m_name;
}

bool Player::GetIsDrawing() const {
	return m_drawingStatus == DrawingStatus::Drawing;
}

void Player::SetIsDrawing(bool isDrawing) {
	m_drawingStatus = isDrawing ? DrawingStatus::Drawing : DrawingStatus::NotDrawing;
}

void Player::setName(const std::string& name)
{
	m_name = name;
}

void skribble::Player::AddScore(uint16_t points)
{
	m_score;
}


