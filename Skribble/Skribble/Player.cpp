#include "Player.h"

Player::Player()
{
	m_IdPlayer = 0;
	m_score = 0;
	m_drawer = false;
}

Player::Player(uint16_t IdPlayer, uint16_t score, bool drawer):
	m_IdPlayer(IdPlayer),
	m_score(score),
	m_drawer(drawer)

{

}

Player::Player(const Player& player)
{
	m_IdPlayer = player.m_IdPlayer;
	m_score = player.m_score;
	m_drawer = player.m_drawer;
}

Player::~Player()
{

}

Player& Player::operator=(const Player& player)
{
	if (this != &player) {
		m_IdPlayer = player.m_IdPlayer;
		m_score = player.m_score;
		m_drawer = player.m_drawer;
	}
	return *this;
}
