module match;

using skribble::Match;

skribble::Match::Match()
	:m_nrRounds{4}
{
}

skribble::Match::Match(const Match& match)
	:m_players{match.m_players}, m_round{match.m_round}, m_nrPlayers{match.m_nrPlayers}, m_nrRounds{match.m_nrRounds}, m_scoreboard{match.m_scoreboard}
{
}

skribble::Match::Match(Match&& match) noexcept
{
	m_players=std::move(match.m_players);
	m_round=std::move(match.m_round);
	m_nrPlayers=std::move(match.m_nrPlayers);
	m_nrRounds = std::move(match.m_nrRounds);
	m_scoreboard=std::move(match.m_scoreboard);
	
}

void Match::StartRound()
{
	m_words.setWords();
	for (int i = 0; i < m_nrRounds * getNrSemiRounds(); i++)
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



uint8_t skribble::Match::getNrPlayers()
{
	return m_players.size();
}	

uint8_t skribble::Match::getNrSemiRounds()
{
	return getNrPlayers() * m_nrRounds;
}
