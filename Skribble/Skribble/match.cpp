module match;

using skribble::Match;



skribble::Match::Match(const Match& match)
	:m_players{match.m_players}, m_rounds{match.m_rounds}
{
}

skribble::Match::Match(Match&& match) noexcept
{
	m_players = std::move(match.m_players);
	m_rounds = std::move(match.m_rounds);
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

bool Match::AddPlayer(const Player& player)
{
	if (m_players.size() < m_players.max_size())
	{
		m_players[m_players.size()] = player;
		return true;
	}
	return false;
}

void skribble::Match::SetMatchWords(const std::deque<Words>& words)
{
	m_words =std::move(words);
}

int skribble::Match::getNrPlayers()
{
	return m_players.size();
}	

//uint8_t skribble::Match::getNrSemiRounds()
//{
//	return m_players.size() * kNrRounds;
//}

void Match::NextDrawer() {
	currentPlayerIndex = (currentPlayerIndex + 1) % m_players.size();
	m_players[currentPlayerIndex].StartDrawing();
	// Alte logici pentru pregătirea noului desenator
}

void Match::StartRound() {
	if (m_players.empty()) {
		std::cerr << "Nu sunt jucători în meci." << std::endl;
		return;
	}
	if (m_words.empty()) {
		std::cerr << "Nu mai sunt cuvinte disponibile." << std::endl;
		return;
	}
	std::string currentWord = m_words.front().GetWord();
	m_words.pop_front();
	m_players[currentPlayerIndex].StartDrawing();
	//StartTimer();
}
