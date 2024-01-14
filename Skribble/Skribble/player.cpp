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

uint16_t skribble::Player::GetCorrectAnswerTime() const
{
	return 0;
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

//void skribble::Player::UpdateAfterCorrectGuess(int timeTakenToGuess)
//{
//	const int maxScorePerGuess = 100;
//	int scoreEarned = maxScorePerGuess - timeTakenToGuess;
//	m_score += scoreEarned > 0 ? scoreEarned : 0;
//	m_correctAnswerTime = timeTakenToGuess;
//	std::cout << "Felicit?ri, " << m_name << "! Ai câ?tigat " << scoreEarned << " puncte." << std::endl;
//}
//
void skribble::Player::AddScore(uint16_t points, int nrPlayers)
{
	if (m_isDrawing == DrawingStatus::Drawing) {
		float alfa = 0.0; // in alfa calculam media timpilor la care s au oferit raspunsurile corecte
	}
	else if (m_isDrawing == DrawingStatus::NotDrawing) {
		uint8_t seconds =0 ; //numarul de secunde in care jucatorul a ghicit cuvantul
		m_score = ((60 - seconds) * 100) / 30;
	}
}

void skribble::Player::SubtractScore(uint16_t points, bool hasGuessed)
{
	if (m_isDrawing == DrawingStatus::Drawing) {
		//daca niciun jucator nu a ghicit cuvantul
		points = 100;
		m_score -= points;
	}
	else if (m_isDrawing == DrawingStatus::NotDrawing) {
		//daca jucatorul nu a ghicit cuvantul
		points = 50;
		m_score -= points;
	}
}

void skribble::Player::ResetScore()
{
	m_score = 0;
	m_correctAnswerTime = 0;
	std::cout << "Scorul juc?torului " << m_name << " a fost resetat la 0." << std::endl;
}

void skribble::Player::DisplayPlayersInOrder(const std::vector<Player>& players)
{
	std::vector<Player> sortedPlayers = players;

	// Sortarea juc?torilor dup? un criteriu, de exemplu scor
	std::sort(sortedPlayers.begin(), sortedPlayers.end(),
		[](const Player& a, const Player& b) {
			return a.GetScore() < b.GetScore();
		}
	);

	// Afi?area juc?torilor sorta?i
	for (const auto& player : sortedPlayers) {
		std::cout << player.GetName() << " - Scor: " << player.GetScore() << std::endl;
	}
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

