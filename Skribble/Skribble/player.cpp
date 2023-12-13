module player;
import<format>;
import <string>;

using skribble::Player;


Player::Player(int IdPlayer, uint16_t score, const std::string& name)
	:m_idPlayer { IdPlayer },
	m_score{ score },
	m_name{ name },
	m_drawingStatus{ DrawingStatus::NotDrawing }
	
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

uint16_t skribble::Player::GetCorrectAnswerTime()
{
	return m_correctAnswerTime; //returneaza un numar de secunde
}

std::string Player::GetName() const
{
	return m_name;
}

Player::DrawingStatus skribble::Player::GetIsDrawing() const
{
	return m_drawingStatus;
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
	m_drawingStatus = isDrawing;
}

void Player::SetName(const std::string& name)
{
	if (name.empty()) {
		std::cerr << "Player name cannot be empty." << std::endl;
		return;
	}
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
	if (m_drawingStatus == DrawingStatus::Drawing) {
		float alfa = 0.0; // in alfa calculam media timpilor la care s au oferit raspunsurile corecte
		//uint8_t numPlayers = m_match->getNrPlayers();	
		// de calculat alfa 
		m_score = ((60 - alfa) * 100) / 60;
	}
	else if (m_drawingStatus == DrawingStatus::NotDrawing) {
		uint8_t seconds = GetCorrectAnswerTime(); //numarul de secunde in care jucatorul a ghicit cuvantul
		if (seconds < 30)
			m_score += 100;
		else
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



