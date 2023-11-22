module word;

using skribble::Words;

Words::Words(const std::vector<std::string>& words)
{
	m_words=words;
}

void Words::setWords(const std::string& fileName)
{	
	std::ifstream file(fileName);
	if (!file) {
		throw std::runtime_error("Failed to open file: " + fileName);
	}
	std::string word;
	while (file>>word)
	{
		m_words.push_back(word);
	}
	if (m_words.empty()) {
		throw std::runtime_error("No words found in file: " + fileName);
	}
}

void skribble::Words::setWords()
{
	std::ifstream file("Words.txt");
	std::string word;
	while (file)
	{
		file >> word;
		m_words.push_back(word);
	}
	
}


std::vector<std::string> Words::getWord(int nrRounds,int nrPlayers) const
{
	if (nrRounds <= 0 || nrPlayers <= 0) {
		throw std::invalid_argument("Number of rounds and players must be greater than 0.");
	}
	if (m_words.size() < static_cast<size_t>(nrRounds * nrPlayers)) {
		throw std::runtime_error("Not enough words to match the number of rounds and players.");
	}
	if (m_words.empty())
	{
		throw std::runtime_error("No words.");
	}
	else
	{
		std::vector<std::string> matchWords;
		for (int it = 0; it < nrPlayers * nrRounds; it++)
		{
			std::random_device dev;
			std::mt19937 rng(dev());
			std::uniform_int_distribution<std::mt19937::result_type> dist6(0, m_words.size() - 1);
			int wordPosition = dist6(rng);
			if (std::find(matchWords.begin(), matchWords.end(), m_words[wordPosition]) == matchWords.end())
				matchWords.push_back(m_words[wordPosition]);
			else
			{
				it--;
			}
		}
		return matchWords;
	}
}
