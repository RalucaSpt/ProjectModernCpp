module word;

using skirbble::Words;

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

void Words::setWords(std::string fileName)
{
	std::fstream file(fileName);
	std::string word;
	while (file)
	{
		file >> word;
		m_words.push_back(word);
	}
}
