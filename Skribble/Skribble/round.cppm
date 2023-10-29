export module round;
import <vector>;
import <string>;
import player;
import word;

export namespace skirbble
{
	class Player;
	class Words;
	export class Round
	{
	public:
		Round(Words& words, std::vector<Player>& players);
		~Round();
		void startRound();
		void guessLetter(char letter);
		void guessWord(const std::string& word);
		void endRound();

		const Player& getWinner() const;
		bool isRoundActive() const;

		std::string getDisplayWord() const;

	};
}