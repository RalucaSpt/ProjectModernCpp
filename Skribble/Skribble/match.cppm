module;
export module match;

import <vector>;
import player;
import round;
import word;

namespace skribble
{
	export class Match
	{
	public:
		Match();
		Match(const Match& match);

		Match(Match&& match) noexcept;

		void StartRound();

		uint8_t getNrPlayers();
		uint8_t getNrSemiRounds();
	private:
		std::vector<skribble::Player> m_players;
		Round m_round;
		uint8_t m_nrPlayers;
		uint8_t m_nrRounds;
		//int m_nrSemiRounds;
		Words m_words;
	};


	

}