module word;
using namespace skribble;



Words::Words(int id, std::string word)
	:m_id{ id }, m_word{ word }
{
}

std::string Words::GetWord() const
{
	return m_word;
}

int Words::GetId() const
{
	return m_id;
}
void skribble::Words::SetWord(const std::string& word)
{
	m_word = word;
}

void skribble::Words::SetId(const int& id)
{
	m_id = id;
}

//
//
//std::vector<std::string> Words::getWord(const int& nrRounds, const int& nrPlayers,const Database& db) const
//{
//	std::vector<Words>
//}
/*
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
	}*/

