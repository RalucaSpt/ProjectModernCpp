module match;

using skribble::Match;



skribble::Match::Match(const Match& match)
	:m_players{match.m_players}, m_round{match.m_round}
{
}

skribble::Match::Match(Match&& match) noexcept
{
	m_players = std::move(match.m_players);
	m_round = std::move(match.m_round);
}
//
//void Match::StartRound()
//{
//	//m_words.setWords();
//	for (int i = 0; i < m_nrRounds * getNrSemiRounds(); i++)
//	{
//		std::vector<std::string> word = m_words.getWord(m_nrRounds, m_players.size());
//		m_round.SetWord(word);
//		//m_words.DeleteWord(word);
//		for (skribble::Player& player : m_players)
//		{
//			m_round.guessWord();
//			player.AddScore(1, m_players.size());
//				
//		}
//	}
//}

void Match::AddPlayer(const Player& player)
{
	if (m_players.size() < m_players.max_size())
		m_players[m_players.size()] = player;
}

int skribble::Match::getNrPlayers()
{
	return m_players.size();
}	

uint8_t skribble::Match::getNrSemiRounds()
{
	return m_players.size() * kNrRounds;
}
