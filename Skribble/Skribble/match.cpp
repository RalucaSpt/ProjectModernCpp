module match;

using skribble::Match;

skribble::Match::Match()
{
}

void Match::StartRound()
{
	m_words.setWords();
	for (int i = 0; i < m_nrRounds; i++)
	{
		std::vector<std::string> word = m_words.getWord(m_nrRounds, m_players.size());
		m_round.setWord(word);
		//m_words.DeleteWord(word);
		for (const Player& player : m_players)
		{
			m_round.guessWord();
		}
	}
}
