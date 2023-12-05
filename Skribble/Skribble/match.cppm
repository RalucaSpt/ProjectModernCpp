module;
export module match;

import<iostream>;
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
		void AddPlayer(const Player& player);

		int getNrPlayers();
		uint8_t getNrSemiRounds();
	private:
		std::vector<Player> m_players;
		Round m_round;
		uint8_t m_nrPlayers;
		uint8_t m_nrRounds;
		//int m_nrSemiRounds;
		Words m_words;
	};


	

}