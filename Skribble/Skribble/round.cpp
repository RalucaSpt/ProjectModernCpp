module round; 

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

	Round::Round(std::string word)
		:m_word{word}, m_roundActive{ false }
	{
	}

	Round::~Round()
	{
		
	}

	void Round::setWord(std::string word)
	{
		m_word = word;
	}



	/*void Round::guessLetter(char letter)
	{
		
	}*/

	void Round::guessWord()//const std::string& word)
	{

		std::string guessingWord;
		for (int it = 0; it < m_word.size(); it++)
			guessingWord.push_back('.');
		std::cout << guessingWord<<"  ("<<guessingWord.size()<<")\n";

		std::string word;

		int score, poz=0;
		for (int i = 0; i < 10; i++)
		{
			std::cout << guessingWord << "  (" << guessingWord.size() << ")\n";
			std::cout << m_player.GetIdPlayer()<<": ";
			std::cin >> word;
			std::cout << "\n";
			if (word == m_word)
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
				guessingWord[poz] = m_word[poz];
			}
		}
		
	}

	void Round::startRound()
	{
		
	}

	void Round::endRound()
	{
		
	}

	/*const Player& Round::getWinner() const
	{
		if (m_winner == nullptr) {
			throw std::runtime_error("No winner yet");
		}
		return *m_winner;
	}
	*/
	bool Round::isRoundActive() const
	{
		return m_roundActive;
	}

	/*std::string Round::getDisplayWord() const
	{
		return m_word;
	}*/
}