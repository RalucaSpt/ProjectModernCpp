module;
export module match;

//#include "SkribbleDatabase.h"

import<iostream>;
import <vector>;
import <deque>;
import player;
import round;
import word;
import <array>;


namespace skribble
{
	export class Match
	{
	public:
		Match() noexcept=default;
		Match(const Match& match);

		Match(Match&& match) noexcept;

		//void StartRound();
		bool AddPlayer(const Player& player);

		void SetMatchWords(const std::deque<Words>& words);
		int getNrPlayers();
		//uint8_t getNrSemiRounds();

		void StartRound();
		void EndRound();

	private:
		void NextDrawer();
		int currentPlayerIndex;
		static const size_t kNrRounds{ 4 };
		static const size_t kNrPlayers{ 8 };
		//void StartTimer();->de implementat

	private:
		std::array<Player,kNrPlayers> m_players;
		std::array<Round,kNrRounds> m_rounds;
		std::deque<Words> m_words;

	};
}