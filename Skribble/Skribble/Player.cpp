module player;
import<format>;
import <string>;

using skribble::Player;

Player::Player()
	:m_idPlayer{ 0 }, m_score{ 0 }, m_isDrawing{ false }
{

Player::Player(int IdPlayer, uint16_t score, const std::string& name)
	:m_idPlayer { IdPlayer },
	m_score{ score },
	m_name{ name },
	m_isDrawing{ false }
{

}

Player::Player(const Player& player)
	:m_idPlayer{ player.m_idPlayer }, m_score{ player.m_score }, m_isDrawing{ player.m_isDrawing }
{

}

Player::Player(int IdPlayer, const std::string& name,std::string password)
	:m_idPlayer{ IdPlayer },
	m_name{ name },
	m_password{password},
	m_drawingStatus{ DrawingStatus::NotDrawing }
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


int skribble::Player::GetIdPlayer() const {
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
/*
skribble::Player::DrawingStatus skribble::Player::GetIsDrawing() const
{
	//de facut
	return ceva;
}

std::string skribble::Player::GetPassword() const
{
	return m_password;
}

bool skribble::Player::guessedWord()
{
	return false;
}

void Player::SetIsDrawing(DrawingStatus isDrawing)
{
	m_isDrawing = isDrawing;
}

void Player::SetName(const std::string& name)
{
	m_name = name;
}

void Player::SetId(const int& id) 
{
	m_idPlayer = id;
}

void skribble::Player::SetPassword(const std::string& password)
{
	m_password = password;
}

void Player::AddScore(uint16_t points, int nrPlayers)
{
	//
}


