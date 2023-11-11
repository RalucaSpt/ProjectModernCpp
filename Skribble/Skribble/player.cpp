module player;
import<format>;
import <string>;

using skribble::Player;

Player::Player()
	:m_idPlayer{ 0 }, m_score{ 0 }, m_isDrawing{ false }
{

}

Player::Player(uint16_t IdPlayer, uint16_t score, const std::string& name):
	m_idPlayer { IdPlayer },
	m_score{ score },
	m_name{ name },
	m_isDrawing{ false }
{

}

Player::Player(const Player& player)
	:m_idPlayer{ player.m_idPlayer }, m_score{ player.m_score }, m_isDrawing{ player.m_isDrawing }
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

std::string Player::GetName() const
{
	return m_name;
}

bool skribble::Player::GetIsDrawing() const
{
	return m_isDrawing;
}

void Player::SetIsDrawing(bool isDrawing)
{
	m_isDrawing = isDrawing;
}

void Player::setName(const std::string& name)
{
	m_name = name;
}

void skribble::Player::AddScore(uint16_t points)
{
	m_score;
}


