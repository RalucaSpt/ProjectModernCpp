module;
export module match;

//#include "SkribbleDatabase.h"

import<iostream>;
import <vector>;
import <deque>;
import <list>;
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
		Match(const Match& match)=delete;

		Match(Match&& match) noexcept;

		//void StartRound();
		bool AddPlayer(const Player& player);

		void SetMatchWords(const std::deque<Words>& words);
		void SetIsStarted(const bool& b);
		void SetGameCode(const std::string& gameCode);

		int GetNrPlayers();
		bool GetIsStarted();
		bool GetPlayerStatus(const std::string& username);
		std::vector<std::tuple<std::string, int>> GetPlayerScore();
		std::string GetGameCode();
		//uint8_t getNrSemiRounds();

		bool FindPlayer(const std::string& name);
		void ErasePlayer(const std::string& name);

		void StartRound();
		void EndRound();

		void DisplayFinalResults();


		void ResetGame();
		void NextDrawer();

		static const size_t kNrRounds{ 4 };
		static const size_t kNrPlayers{ 8 };
	
	private:
		int m_currentPlayerIndex;
		int m_currentRoundComplete;
		//void StartTimer();->de implementat

	private:
		std::deque<std::unique_ptr<Player>> m_players;
		std::deque<Words> m_words;
		bool m_isStarted;
		std::string m_gameCode;
	};
}