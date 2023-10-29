export module round;
import <vector>;
import <string>;
import player;
import word;

//export 
namespace skribble
{
	//class Player;
	//class Words;
	export class Round
	{
	public:
		//Round(Words& words, std::vector<Player>& players);
		Round(Words words);
		~Round();
		void startRound();
		void guessLetter(char letter);
		void guessWord(const std::string& word);
		void endRound();

		const Player& getWinner() const;
		bool isRoundActive() const;

		std::string getDisplayWord() const;
	private:
		Words m_words;
		//std::vector<Player>& m_players;
		std::string m_currentWord;
		std::string m_displayWord;
		bool m_roundActive;
		Player* m_winner;
	};
}