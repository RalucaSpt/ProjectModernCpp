module player;
import<format>;
import <string>;

using skribble::Player;

Player::Player(int IdPlayer, uint16_t score, const std::string& name)
	:m_idPlayer { IdPlayer },
	m_score{ score },
	m_name{ name },
	m_isDrawing{ DrawingStatus::NotDrawing }
{

}

Player::Player(const int& IdPlayer, const std::string& name, const std::string& password)
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
		m_name = player.GetName();
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

void skribble::Player::SetCorrectAnswerTime(uint8_t seconds) 
{
	m_correctAnswerTime = seconds;
}

uint16_t skribble::Player::GetCorrectAnswerTime() const
{
	return m_correctAnswerTime;
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

bool skribble::Player::IsDrawing() const
{
	if (this->m_isDrawing == DrawingStatus::Drawing)
		return true;
	return false;
}

void skribble::Player::AddScore(uint16_t points, int nrPlayers)
{
	if (this->IsDrawing()) {
		float alfa = 0.0; // in alfa calculam media timpilor la care s au oferit raspunsurile corecte
		//uint8_t numPlayers = m_match->getNrPlayers();	
		// de calculat alfa 
		m_score = ((60 - alfa) * 100) / 60;
	}
	else if(!IsDrawing()) {
		uint8_t seconds = GetCorrectAnswerTime(); //numarul de secunde in care jucatorul a ghicit cuvantul
		if (seconds < 30)
			m_score += 100;
		else
			m_score = ((60 - seconds) * 100) / 30;
	}

}

void skribble::Player::SubtractScore(uint16_t points, bool hasGuessed)
{
	if (this->IsDrawing()) {
		// Depunctare pentru juc?torul care deseneaz? dac? nimeni nu a ghicit
		m_score -= 100;
	}
	else if (!hasGuessed) {
		// Depunctare pentru juc?torii care nu au ghicit
		m_score -= 50;
	}
}


void skribble::Player::ResetScore()
{
	m_score = 0;
}

