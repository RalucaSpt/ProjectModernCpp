module;
export module round;


import <random>;
import <iostream>;
import <ctime>;
import <algorithm>;
import <set>;
import <vector>;
import <queue>;
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
	    Round(std::queue<std::string> word);
		Round(const Round& round);
		~Round();

		void SetWord(const std::queue<std::string>& word);
		bool guessWord(const std::string& guess);
		
		std::string RevealRandomLetters(std::string word);

		void startRound();// std::vector<Player>& players);
		void manageRound();
		void endRound();
		void nextDrawer();
		void displayScoreboard(std::vector<Player> players);

		void nextSubround();

		//void SetPlayer(Player player);
		//const Player& GetWinner() const;
		//std::string GetDisplayWord() const;

		/*void guessWord(Player& player, const std::string& guessedWord,const std::string& guessWord);*/
		
		/*bool isRoundActive() const;*/
		//skribble::Player getCurrentDrawer(const int& index);

		//void startTimer(int durationInSeconds);
		//bool isTimeUp();


	private:
		
		int currentPlayerIndex;
		std::queue<std::string> m_word;
		std::chrono::steady_clock::time_point roundStartTime;
		std::chrono::seconds roundDuration;
		//bool m_roundActive;
		//Player m_player;

		//std::vector<Player> m_players;
		
		//int currentSubround;
		//Player* m_winner;
	};
}