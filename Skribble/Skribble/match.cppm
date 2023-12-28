module;
export module match;

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
		void AddPlayer(const Player& player);

		int getNrPlayers();
		uint8_t getNrSemiRounds();
	private:
		static const size_t kNrRounds{ 4 };
		static const size_t kNrPlayers{ 8 };

	private:
		std::array<Player,kNrPlayers> m_players;
		Round m_round;
		std::deque<Words> m_words;

	};
}