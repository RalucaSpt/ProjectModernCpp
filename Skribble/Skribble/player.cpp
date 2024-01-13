module player;
import<format>;
import <string>;
#include <random>

using skribble::Player;


Player::Player(int IdPlayer, uint16_t score, const std::string& name)
	:m_idPlayer { IdPlayer },
	m_score{ score },
	m_name{ name },
	m_isDrawing{ DrawingStatus::NotDrawing }
{

}
Player::Player(const int& IdPlayer, const std::string& name,const std::string& password)
	:m_idPlayer{ IdPlayer },
	m_name{ name },
	m_password{password},
	m_isDrawing{ DrawingStatus::NotDrawing }
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
std::string skribble::Player::GetPassword() const
{
	return m_password;
}
void Player::SetName(const std::string& name)
{
	if (IsValidName(name)) {
		m_name = name;
	}
	else {
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> distr(1, 100);

		// Seteaz? numele ca "Jucator" + num?rul aleator
		m_name = "Jucator" + std::to_string(distr(gen));
	}
}

void Player::SetId(const int& id)
{
	m_idPlayer = id;
}

void skribble::Player::SetPassword(const std::string& password)
{
	m_password = password;
}
void skribble::Player::SetScore(uint16_t score)
{
	m_score = score;
}
bool skribble::Player::IsDrawing() const
{
	if(this->m_isDrawing==DrawingStatus::NotDrawing)
		return false;
	return true;
}

bool Player::IsValidName(const std::string& name)
{
	if (name.length() < 3 || name.length() > 20) {
		return false;
	}

	for (char c : name) {
		if (!isalnum(c) && c != '_') {
			return false;
		}
	}

	return true;
	
}
/*
skribble::Player::DrawingStatus skribble::Player::GetIsDrawing() const
{
	//de facut
	return ceva;
}


bool skribble::Player::guessedWord()
{
	return false;
}

void Player::SetIsDrawing(DrawingStatus isDrawing)
{
	m_isDrawing = isDrawing;
}



void Player::AddScore(uint16_t points, int nrPlayers)
{
	//
}
*/

