module round;

using skribble::Round;


	/*Round::Round(Words& words, std::vector<Player>& players)
		: m_words(words), m_players(players),m_winner(), m_roundActive(false)
	{

	}*/

Round::Round()
	/* :m_roundActive{false}, * / /*m_winner{ nullptr }*/
{
}

Round::Round(const std::deque<std::string>& words)
	:m_words{ words }/*, m_roundActive{ false }*/
{
}

Round::Round(const Round& round)
	:/*m_player{ round.m_player }, m_roundActive{ round.m_roundActive }, m_winner{ round.m_winner },*/ m_words{ round.m_words }
{

}

Round::~Round()
{

}

void Round::SetWord(const std::deque<std::string>& words)
{
	m_words = words;
}

std::string skribble::Round::CreateGuessWord(const std::deque<std::string>& words)
{
	std::string word = words.front();
	m_words.pop_front();
	std::string guessingWord;
	for (int it = 0; it < word.size(); it++)
		guessingWord.push_back('_');
	return guessingWord;
}

//bool Round::guessWord(const std::string& guess)
//{
//	if (guess == guessingWord)
//		return true;
//	return false;
//}
std::vector<std::string> skribble::Round::GenerateThreeWords()
{
	std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(m_words.begin(), m_words.end(), g);

	m_threeWords.clear();
	for (int i = 0; i < 3 && i < m_words.size(); ++i) {
		m_threeWords.push_back(m_words[i]);
	}
	return m_threeWords;
}

void skribble::Round::SendWordsToDrawer(int drawerIndex, std::vector<std::string> threeWords)
{

}

void Round::StartSubRound(int drawerIndex)
{
	if (!m_words.empty()) {
		m_subRoundActive = true;
		std::cout << "Subround has started. Guess the word!"; 
		std::cout<< std::endl;
		std::vector<std::string> threeWords = GenerateThreeWords();
		SendWordsToDrawer(drawerIndex, threeWords);
		
	}
	else {
		std::cerr << "Cannot start subround: not enough words." << std::endl;
	}
}

void Round::NextSubround(std::vector<Player> players)
{
	if (currentDrawerIndex < players.size() - 1 && m_roundActive == true)
	{
		StartSubRound(currentDrawerIndex);
		currentDrawerIndex++;
	}
	else
	{
		EndSubRound();
	}
}

void Round::EndSubRound()
{
	if (m_subRoundActive == true)
	{
		m_subRoundActive = false;
		currentDrawerIndex = 0;
	}

	/*if (!m_roundActive) {
		std::cerr << "Cannot end round: No round is active."; 
		std::cout << std::endl;
		return;
	}
	m_roundActive = false;
	if (m_winner == nullptr) {
		std::cout << "No one guessed the word. No winner this round." << std::endl;
	}
	else {
		std::cout << "Winner of the round is: " << m_winner->GetName() << std::endl;
	}
	std::cout << "Round ended." << std::endl;*/
}

//skribble::Player Round::getCurrentDrawer(const int& index)
//{
//	return m_players[index];
//}

//void skribble::Round::nextDrawer()
//{
//	currentPlayerIndex = currentPlayerIndex + 1; //% m_players.size();
//	nextSubround();
//}

void skribble::Round::displayScoreboard(std::vector<Player> players)
{
	std::ranges::sort(players, [](const Player& a, const Player& b) {
		return a.GetScore() > b.GetScore();
		});
	std::cout << "Scoreboard:\n";
	for (const auto& player : players)
	{
		std::cout << player.GetName() << " " << player.GetScore();
	}
}



//void skribble::Round::startTimer(int durationInSeconds)
//{
//	roundDuration = std::chrono::seconds(durationInSeconds);
//	roundStartTime = std::chrono::steady_clock::now();
//}

//bool skribble::Round::isTimeUp()
//{
//	auto now = std::chrono::steady_clock::now();
//	return std::chrono::duration_cast<std::chrono::seconds>(now - roundStartTime) >= roundDuration;
//}
//
//void skribble::Round::manageRound()
//{
//}
	//// Începe o nouă rundă
	///*startRound();*/

	//while (isRoundActive()) {
	//	 //Aici ar fi logica pentru gestionarea desenului și a ghicirii cuvântului

	//	// Verifică dacă timpul alocat pentru subrundă s-a terminat
	//	if (/*isTimeUp()*/) {
	//		std::cout << "Time is up for the current subround." << std::endl;
	//		/*endSubround();*/ // Metodă pentru a finaliza subrunda curentă
	//	}

	//	 //Verifică dacă cuvântul a fost ghicit
	//	if (/* condiția de verificare a cuvântului ghicit */) {
	//		std::cout << "The word has been guessed!" << std::endl;
	//		// Acordă puncte jucătorului care a ghicit
	//		/*awardPointsToGuesser(); */// Metodă ipotetică, trebuie implementată

	//		/*endSubround();*/
	//	}

	//	 //Dacă subrunda curentă s-a terminat, trece la următoarea
	//	/*if (isSubroundOver()) {
	//		nextSubround();
	//	}*/
	//}

	// //Runda s-a încheiat
	//endRound();
	// //Afișează rezultatele runde, scorurile etc.





/*const Player& Round::getWinner() const
{
	if (m_winner == nullptr) {
		throw std::runtime_error("No winner yet");
	}
	return *m_winner;
}
*/

//void Round::guessWord(Player& player, const std::string& guessedWord, const std::string& guessingword)
//{
//	if (!m_roundActive) {
//		std::cerr << "Round not active. Cannot guess word." << std::endl;
//		return;
//	}
//
//	if (guessedWord == guessingword) {
//		std::cout << player.GetName() << " has guessed the word!" << std::endl;
//		//player.AddScore(); 
//	}
//	else {
//		std::cout << player.GetName() << " has not guessed the word. Try again!" << std::endl;
//	}
//}

//bool Round::isRoundActive() const
//{
//	return m_roundActive;
//}

std::string Round::RevealRandomLetters(const std::string& word)
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
