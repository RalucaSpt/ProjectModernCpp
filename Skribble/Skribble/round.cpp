module round;

using skribble::Round;


//import <vector>;
//import <string>;
//import <random>;

//#include <optional>

	/*Round::Round(Words& words, std::vector<Player>& players)
		: m_words(words), m_players(players),m_winner(), m_roundActive(false)
	{

	}*/

Round::Round()
	:m_roundActive{ false }, m_winner{ nullptr }, m_word{ "-" }
{
}

Round::Round(std::vector<std::string> word)
	:m_word{ word }, m_roundActive{ false }
{
}

Round::Round(const Round& round)
	:m_player{ round.m_player }, m_roundActive{ round.m_roundActive }, m_winner{ round.m_winner }, m_word{ round.m_word }
{

}

Round::~Round()
{

}

void Round::SetWord(const std::vector<std::string>& word)
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
	for (int it = 0; it < word.size(); it++)
		guessingWord.push_back('_');
	std::cout << guessingWord << "  (" << guessingWord.size() << ")\n";

	std::string playerGuess;

	int score, poz = 0;
	for (int i = 0; i < 10; i++)
	{
		std::cout << guessingWord << "  (" << guessingWord.size() << ")\n";
		std::cout << m_player.GetIdPlayer() << ": ";
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
		if (i >= 4 && poz < guessingWord.size() / 2)
		{
			RevealRandomLetters(word);
		}
	}
	auto it = std::find(m_word.begin(), m_word.end(), word);
	m_word.erase(it);
}

	void Round::startRound(std::vector<Player>& players)
	{
		m_players = players;
		currentSubround = 0;
		if (!m_word.empty()) {
			m_roundActive = true;
			std::cout << "Round has started. Guess the word!"; 
			std::cout<< std::endl;
		}
		else {
			std::cerr << "Cannot start round: word is not set." << std::endl;
		}
	}

void Round::nextSubround()
{
	if (currentSubround < m_players.size()) {
		// Logica pentru începerea unei noi subrunde
		std::cout << "New subround started. " << getCurrentDrawer().getName() << " is drawing now." << std::endl;
		currentSubround++;
	}
	else {
		// Toate subrundele sunt complete
		endRound();
	}
}

void Round::endRound()
{
	if (!m_roundActive) {
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
	std::cout << "Round ended." << std::endl;
}

Player& skribble::Round::getCurrentDrawer()
{
	return players[currentPlayerIndex];
}

void skribble::Round::nextDrawer()
{
	currentPlayerIndex = (currentPlayerIndex + 1) % players.size();
	nextSubround();
}

void skribble::Round::displayScoreboard(std::vector<Player> players)
{
	std::stable_sort(players.begin(), players.end(), [](Player a, Player b)
		{
			return a.GetScore() < b.GetScore();
		});

	std::cout << "Scoreboard:\n";
	for (const auto& player : players)
	{
		std::cout << player.GetName() << " " << player.GetScore();
	}
}

void skribble::Round::startTimer(int durationInSeconds)
{
	roundDuration = std::chrono::seconds(durationInSeconds);
	roundStartTime = std::chrono::steady_clock::now();
}

bool skribble::Round::isTimeUp()
{
	auto now = std::chrono::steady_clock::now();
	return std::chrono::duration_cast<std::chrono::seconds>(now - roundStartTime) >= roundDuration;
}




/*const Player& Round::getWinner() const
{
	if (m_winner == nullptr) {
		throw std::runtime_error("No winner yet");
	}
	return *m_winner;
}
*/
void Round::guessWord(Player& player, const std::string& guessedWord, const std::string& guessingword)
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
