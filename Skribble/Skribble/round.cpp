module round; 

import <vector>;
import <string>;
import <random>;
import <set>;

//#include <optional>

namespace skribble
{
	/*Round::Round(Words& words, std::vector<Player>& players)
		: m_words(words), m_players(players),m_winner(), m_roundActive(false)
	{

	}*/

	Round::Round()
		:m_roundActive{false},m_winner{nullptr},m_word{"-"}
	{
	}

	Round::Round(std::vector<std::string> word)
		:m_word{word}, m_roundActive{ false }
	{
	}

	Round::Round(const Round& round)
		:m_player{round.m_player},m_roundActive{round.m_roundActive},m_winner{round.m_winner},m_word{round.m_word}
	{

	}

	Round::~Round()
	{
		
	}

	void Round::setWord(std::vector<std::string> word)
	{
		/*static const std::vector<std::string> wordList = { "pictură", "calculator", "bibliotecă", "astronaut", "chitară" };
		static std::mt19937 rng(std::time(nullptr));
		std::uniform_int_distribution<std::mt19937::result_type> dist(0, wordList.size() - 1);

		int randomIndex = dist(rng);

		setWord(wordList[randomIndex]);*/
		m_word = word;
	}



	/*void Round::guessLetter(char letter)
	{
		
	}*/

	void Round::guessWord()//const std::string& word)
	{
		std::string word = m_word.front();
		std::string guessingWord;
		for (int it = 0; it < m_word.size(); it++)
			guessingWord.push_back('_');
		std::cout << guessingWord<<"  ("<<guessingWord.size()<<")\n";

		std::string playerGuess;

		int score, poz=0;
		for (int i = 0; i < 10; i++)
		{
			std::cout << guessingWord << "  (" << guessingWord.size() << ")\n";
			std::cout << m_player.GetIdPlayer()<<": ";
			std::cin >> playerGuess;
			std::cout << "\n";
			if (word == playerGuess)
			{
				score = 10 - i;
				std::cout << "Round Over!" << "\n";
				break;
			}
			else
			{
				std::cout << "Gresit!\n";
			}
			if (i >= 4 && poz<guessingWord.size()/2)
			{
				RevealRandomLetters(word);
			}
		}
		
	}

	void Round::startRound()
	{
		if (!m_word.empty()) {
			m_roundActive = true;
			std::cout << "Round has started. Guess the word!" << std::endl;
		}
		else {
			std::cerr << "Cannot start round: word is not set." << std::endl;
		}
	} 
		

	void Round::endRound()
	{
		if (!m_roundActive) {
			std::cerr << "Cannot end round: No round is active." << std::endl;
			return;
		}
		m_roundActive = false;
		if (m_winner == nullptr) {
			std::cout << "No one guessed the word. No winner this round." << std::endl;
		}
		else {
			std::cout << "Winner of the round is: " << m_winner->GetName() << std::endl;
		}
		std::cout << "Round ended." << std::endl;
	}

	/*const Player& Round::getWinner() const
	{
		if (m_winner == nullptr) {
			throw std::runtime_error("No winner yet");
		}
		return *m_winner;
	}
	*/
	void Round::guessWord(Player& player, const std::string& guessedWord,const std::string& guessingword)
	{
		if (!m_roundActive) {
			std::cerr << "Round not active. Cannot guess word." << std::endl;
			return;
		}

		if (guessedWord == guessingword) {
			std::cout << player.GetName() << " has guessed the word!" << std::endl;
			//player.AddScore(); 
		}
		else {
			std::cout << player.GetName() << " has not guessed the word. Try again!" << std::endl;
		}
	}
	bool Round::isRoundActive() const
	{
		return m_roundActive;
	}

	std::string Round::RevealRandomLetters(std::string word)
	{
		
		int halfLength = word.length() / 2;
		std::string revealedWord = word;
		std::random_device rd;
		std::mt19937 g(rd());

		std::set<int> revealedPositions;
		while (revealedPositions.size() < halfLength) {
			int pos = g() % word.length();
			revealedPositions.insert(pos);
		}

		for (int i = 0; i < revealedWord.length(); ++i) {
			if (revealedPositions.find(i) == revealedPositions.end()) {
				revealedWord[i] = '_';
			}
		}

		return revealedWord;
	}
}