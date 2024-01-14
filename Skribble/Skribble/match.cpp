module match;

using skribble::Match;


skribble::Match::Match(Match&& match) noexcept
{
	m_players = std::move(match.m_players);
	//m_rounds = std::move(match.m_rounds);
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
	if (m_players.size() < kNrPlayers)
	{
		m_players.push_back(std::make_unique<Player>(std::move(player)));
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

void skribble::Match::SetGameCode(const std::string& gameCode)
{
	m_gameCode = gameCode;
}



int skribble::Match::GetNrPlayers()
{
	return m_players.size();
}

bool skribble::Match::GetIsStarted()
{
	return m_isStarted;
}

bool skribble::Match::GetPlayerStatus(const std::string& username)
{
	for (const auto& it:m_players)
		if (it->GetName() == username)
			if(it->IsDrawing() == false)
				return false;
	return true;
}

std::vector<std::tuple<std::string, int>> Match::GetPlayerScore()
{
	std::vector<std::tuple<std::string, int>> playersScore;
	for (const auto& it : m_players)
	{
		playersScore.push_back({it->GetName(), static_cast<int>(it->GetScore())});
	
	}
	return playersScore;

}

std::string skribble::Match::GetGameCode()
{
	return m_gameCode;
}

bool skribble::Match::FindPlayer(const std::string& name)
{
	for (const auto& it : m_players)
		if (it->GetName() == name)
			return true;
	return false;
}

void skribble::Match::ErasePlayer(const std::string& name)
{
	for (auto it=m_players.begin();it!=m_players.end();it++)
		if (it->get()->GetName() == name)
		{
			m_players.erase(it);
			break;
		}

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
	m_players[m_currentPlayerIndex]->StartDrawing();
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
	m_players[m_currentPlayerIndex]->StartDrawing();
	//StartTimer();
}

void Match::EndRound() {
	m_players[m_currentPlayerIndex]->StopDrawing();
	NextDrawer();
	if (m_currentRoundComplete >= kNrRounds) {
		// Dacă toate rundele complete au fost jucate, resetează jocul sau începe un nou set de runde
		ResetGame();
	}
	else {
		StartRound();
	}
}

void skribble::Match::DisplayFinalResults()
{

	std::cout << "Jocul s-a terminat. Rezultatele finale sunt:" << std::endl;

	// Sortați jucătorii în funcție de scor și afișați scorurile
	std::sort(m_players.begin(), m_players.end(),
		[](const std::unique_ptr<Player>& a, const std::unique_ptr<Player>& b) {
			return a->GetScore() > b->GetScore();
		});

	for (const auto& player : m_players) {
		std::cout << player->GetName() << ": " << player->GetScore() << " puncte" << std::endl;
	}

	// Anunțați câștigătorul
	if (!m_players.empty()) {
		std::cout << "Câștigătorul este: " << m_players.front()->GetName() << std::endl;
	}
}

void Match::ResetGame() {
	m_currentRoundComplete = 0;
	m_currentPlayerIndex = 0;
	//+altele
}
