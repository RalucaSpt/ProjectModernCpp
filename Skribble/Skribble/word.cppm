
export module word;
import <string>;
import <vector>;
import <iostream>;
import <fstream>;
import <cstdlib>;
import <random>;
import  <algorithm>;

namespace skribble
{
	export class Words
	{
	public:
		Words();
		Words(std::vector<std::string> words);
		~Words();

		void setWords(const std::string& textFile);
		void setWords();

		Words(Words&& listWords);

		std::vector<std::string> getWord(int nrRounds, int nrPlayers);
		

	private:
		std::vector<std::string> m_words;
	};
}