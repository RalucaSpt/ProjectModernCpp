module;
export module round;


import <random>;
import <iostream>;
import <ctime>;
import <algorithm>;
import <set>;
import <vector>;
import <deque>;
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
	    Round(const std::deque<std::string>& words);
		Round(const Round& round);
		~Round();

		void SetWord(const std::deque<std::string>& words);
		std::string CreateGuessWord(const std::deque<std::string>& words);
		//bool guessWord(const std::string& guess);
		
		std::string RevealRandomLetters(const std::string& word);

		void StartSubRound(int drawerIndex);
		void NextSubround(std::vector<Player> players);
		void EndSubRound();
		//void manageRound();
		//void nextDrawer();
		void displayScoreboard(std::vector<Player> players);
		std::vector<std::string> GenerateThreeWords();
		void SendWordsToDrawer(int drawerIndex, std::vector<std::string> threeWords);
		//void SetPlayer(Player player);
		//const Player& GetWinner() const;
		//std::string GetDisplayWord() const;

		/*void guessWord(Player& player, const std::string& guessedWord,const std::string& guessWord);*/
		
		/*bool isRoundActive() const;*/
		//skribble::Player getCurrentDrawer(const int& index);

		//void startTimer(int durationInSeconds);
		//bool isTimeUp();


	private:
		
		std::deque<std::string> m_words;
		std::vector<std::string> m_threeWords;
		
		int currentDrawerIndex;
		bool m_roundActive;
		bool m_subRoundActive = true;
		std::vector<Player> m_players;

		std::chrono::steady_clock::time_point roundStartTime;
		std::chrono::seconds roundDuration;

		//Player m_player;

		//std::vector<Player> m_players;
		
		//int currentSubround;
		//Player* m_winner;
	};
}