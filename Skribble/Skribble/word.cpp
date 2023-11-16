module word;

using skribble::Words;

Words::Words()
{

}
Words::Words(std::vector<std::string> words)
{
	m_words=words;
}
Words::~Words()
{

}

void Words::setWords(const std::string& fileName)
{
	std::ifstream file(fileName);
	std::string word;
	while (file)
	{
		file >> word;
		m_words.push_back(word);
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

Words::Words(Words&& listWords)
{
	m_words = std::move(listWords.m_words);
}

std::vector<std::string> Words::getWord(int nrRounds,int nrPlayers)
{
	if (m_words.size() == 0)
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
			it--;
		}
		return matchWords;
	}
}
