module;
export module round;


import <random>;
import <iostream>;
import <ctime>;
import <algorithm>;
import <set>;
import <vector>;
import <string>;
import <chrono>;
import player;
import word;


namespace skribble
{
	export class Round
	{
	public:
		//Round(Words& words, std::vector<Player>& players);
		Round();
	    Round(std::vector<std::string> word);
		Round(const Round& round);
		~Round();

		void SetWord(const std::vector<std::string>& word);
		void SetPlayer(Player player);
		const Player& GetWinner() const;
		std::string GetDisplayWord() const;

		void guessWord();//const std::string& word);
		void guessWord(Player& player, const std::string& guessedWord,const std::string& guessWord);
		std::string RevealRandomLetters(std::string word);

		void startRound(std::vector<Player>& players);
		void nextSubround();
		bool isRoundActive() const;
		void endRound();

		void displayScoreboard(std::vector<Player> players);
		void startTimer(int durationInSeconds);
		bool isTimeUp();

	private:
		//Words m_word;
		std::vector<std::string> m_word;
		//std::vector<Player>& m_players;
		//std::string m_currentWord;
		//std::string m_displayWord;
		bool m_roundActive;
		Player m_player;
		std::vector<Player> m_players;
		int currentSubround;
		Player* m_winner;
		std::chrono::steady_clock::time_point roundStartTime;
		std::chrono::seconds roundDuration;

	};
}