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
		void StartRound();
	private:
		std::vector<skribble::Player> m_players;
		Round m_round;
		int m_nrRounds;
		Scoreboard m_scoreboard;
		Words m_words;
	};


	

}