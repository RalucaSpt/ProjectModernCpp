
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
		int getNrPlayers();
		int getNrSemiRounds(/* numarul de jucatori*4 */);
	private:
		std::vector<skribble::Player> m_players;
		Round m_round;
		int m_nrPlayers;
		int m_nrRounds = 4;
		//int m_nrSemiRounds;
		Scoreboard m_scoreboard;
		Words m_words;
	};


	

}