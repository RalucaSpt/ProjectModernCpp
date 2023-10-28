module player;
import<format>;

using skribble::Player;

Player::Player()
{
	m_idPlayer = 0;
	m_score = 0;
}

Player::Player(uint16_t IdPlayer, uint16_t score):
	m_idPlayer(IdPlayer),
	m_score(score)
{

}

Player::Player(const Player& player)
{
	m_idPlayer = player.m_idPlayer;
	m_score = player.m_score;
}

Player::~Player()
{

}

Player& Player::operator=(const Player& player)
{
	if (this != &player) {
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
