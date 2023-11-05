module player;
import<format>;

using skribble::Player;

Player::Player()
	:m_idPlayer{0},m_score{0},m_isDrawing{false}
{
	
}

Player::Player(uint16_t IdPlayer, uint16_t score):
	m_idPlayer{ IdPlayer },
	m_score{score},
	m_isDrawing{false}
{

}

Player::Player(const Player& player)
	:m_idPlayer{player.m_idPlayer},m_score{player.m_score},m_isDrawing{player.m_isDrawing}
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

uint16_t skribble::Player::GetIdPlayer()
{
	return m_idPlayer;
}

uint16_t skribble::Player::GetScore()
{
	return m_score;
}

std::string skribble::Player::GetName() const
{
	return std::string();
}

bool skribble::Player::GetIsDrawing()
{
	return m_isDrawing;
}

void Player::SetIsDrawing(bool isDrawing)
{
	m_isDrawing = isDrawing;
}

void skribble::Player::SetName(const std::string& name)
{
}
