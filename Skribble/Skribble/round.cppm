module;
export module round;
import <vector>;
import <string>;
import player;
import word;
import <iostream>;
import <vector>;
import <ctime>;
import <random>;


namespace skribble
{
	export class Round
	{
	public:
		//Round(Words& words, std::vector<Player>& players);
		Round();
	    Round(std::string word);
		Round(const Round& round);
		~Round();
		void setWord(std::string word);
		void setPlayer(Player player);
		void guessWord();//const std::string& word);
		void startRound();
		void endRound();

		const Player& getWinner() const;
		bool isRoundActive() const;

		std::string getDisplayWord() const;
		void guessWord(Player& player, const std::string& guessedWord);
	private:
		//Words m_word;
		std::string m_word;
		//std::vector<Player>& m_players;
		//std::string m_currentWord;
		//std::string m_displayWord;
		bool m_roundActive;
		Player m_player;
		Player* m_winner;
	};
}