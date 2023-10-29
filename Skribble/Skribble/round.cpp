module round; 
import <iostream>;
#include <optional>

namespace skirbble
{
	Round::Round(Words& words, std::vector<Player>& players)
		: m_words(words), m_players(players),m_winner(), m_roundActive(false)
	{
		
	}

	Round::~Round()
	{
		
	}

	void Round::startRound()
	{
		
	}

	void Round::guessLetter(char letter)
	{
		
	}

	void Round::guessWord(const std::string& word)
	{
		
	}

	void Round::endRound()
	{
		
	}

	const Player& Round::getWinner() const
	{
		if (m_winner == nullptr) {
			throw std::runtime_error("No winner yet");
		}
		return *m_winner;
	}

	bool Round::isRoundActive() const
	{
		return m_roundActive;
	}

	std::string Round::getDisplayWord() const
	{
		return m_displayWord;
	}
}