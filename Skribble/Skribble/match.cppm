
module;
export module match;

import <vector>;
import player;
import round;
import scoreboard;
import word;

namespace skribble
{
	export class Match
	{
	public:
		Match();
		void StartRound();
		uint8_t getNrPlayers();
		uint8_t getNrSemiRounds();
	private:
		std::vector<skribble::Player> m_players;
		Round m_round;
		uint8_t m_nrPlayers;
		uint8_t m_nrRounds = 4;
		//int m_nrSemiRounds;
		Scoreboard m_scoreboard;
		Words m_words;
	};


	

}