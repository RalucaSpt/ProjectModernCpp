#pragma once
#include<iostream>
class Player
{
public:
	Player();
	Player(uint16_t m_IdPlayer, uint16_t m_score, bool m_drawer);
	Player(const Player& player);

	~Player();

	Player& operator= (const Player& player);
	
private:
	uint16_t m_IdPlayer;
	uint16_t m_score;
	bool m_drawer;
};

