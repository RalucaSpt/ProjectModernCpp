module match;

using skribble::Match;



skribble::Match::Match(const Match& match)
	:m_players{match.m_players}, m_rounds{match.m_rounds}, m_currentPlayerIndex{0},m_isStarted{false}
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

void skribble::Match::SetIsStarted(const bool& b)
{
	m_isStarted = b;
}



int skribble::Match::GetNrPlayers()
{
	return m_players.size();
}

bool skribble::Match::GetIsStarted()
{
	return m_isStarted;
}

//uint8_t skribble::Match::getNrSemiRounds()
//{
//	return m_players.size() * kNrRounds;
//}

void Match::NextDrawer() {
	m_currentPlayerIndex = (m_currentPlayerIndex + 1) % m_players.size();
	if (m_currentPlayerIndex == 0) {
		m_currentRoundComplete++;
	}
	m_players[m_currentPlayerIndex].StartDrawing();
	// Alte logici pentru pregătirea noului desenator
}
//de discutat daca raman clasele astea sau cele din round
void Match::StartRound() {
	if (m_players.empty()) {
		std::cerr << "There are no players in the match." << std::endl;
		return;
	}
	if (m_words.empty()) {
		std::cerr << "There are no more words available." << std::endl;
		return;
	}
	std::string currentWord = m_words.front().GetWord();
	m_words.pop_front();
	m_players[m_currentPlayerIndex].StartDrawing();
	//StartTimer();
}

void Match::EndRound() {
	m_players[m_currentPlayerIndex].StopDrawing();
	NextDrawer();
	if (m_currentRoundComplete >= kNrRounds) {
		// Dacă toate rundele complete au fost jucate, resetează jocul sau începe un nou set de runde
		ResetGame();
	}
	else {
		StartRound();
	}
}

void Match::ResetGame() {
	m_currentRoundComplete = 0;
	m_currentPlayerIndex = 0;
	//+altele
}
