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
		void SetIsStarted(const bool& b);

		int GetNrPlayers();
		bool GetIsStarted();
		//uint8_t getNrSemiRounds();

		void StartRound();
		void EndRound();
		void ResetGame();
		void NextDrawer();

		static const size_t kNrRounds{ 4 };
		static const size_t kNrPlayers{ 8 };
	
	private:
		int m_currentPlayerIndex;
		int m_currentRoundComplete;
		//void StartTimer();->de implementat

	private:
		std::array<Player,kNrPlayers> m_players;
		std::array<Round,kNrRounds> m_rounds;
		std::deque<Words> m_words;
		bool m_isStarted;
	};
}