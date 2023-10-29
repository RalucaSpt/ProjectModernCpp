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

std::string Words::getWord()
{
	if (m_words.size() == 0)
	{
		throw std::runtime_error("No words.");
	}
	else
	{
		std::random_device dev;
		std::mt19937 rng(dev());
		std::uniform_int_distribution<std::mt19937::result_type> dist6(0, m_words.size() - 1);
		int wordPosition = dist6(rng);
		return m_words[wordPosition];
	}
}
